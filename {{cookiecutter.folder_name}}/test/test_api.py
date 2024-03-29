"""
This file can be used with `pytest`.

The following way to execute the whole tests.
```
pytest test/test.py
```

Or the following way to execute a single test.
```
pytest test/test.py::test_internal_trigger
```

"""

import numpy
import time
import logging
from Lima import Core, {{cookiecutter.project_name}}


_logger = logging.getLogger(__name__)


class AcquisitionStatusFromImageStatusCallback(Core.CtControl.ImageStatusCallback):
    def __init__(self):
        super().__init__()
        self.last_base_image_ready = -1
        self.last_image_acquired = -1
        self.last_image_ready = -1
        self.last_image_saved = -1
        self.last_counter_ready = -1

    def imageStatusChanged(self, image_status):
        self.last_base_image_ready = image_status.LastBaseImageReady
        self.last_image_acquired = image_status.LastImageAcquired
        self.last_image_ready = image_status.LastImageReady
        self.last_image_saved = image_status.LastImageSaved
        self.last_counter_ready = image_status.LastCounterReady


def test_internal_trigger():
    cam = {{cookiecutter.project_name}}.Camera()
    hw = {{cookiecutter.project_name}}.Interface(cam)
    ct = Core.CtControl(hw)

    acq_status = AcquisitionStatusFromImageStatusCallback()
    ct.registerImageStatusCallback(acq_status)

    ct.prepareAcq()
    ct.startAcq()

    while ct.getStatus().AcquisitionStatus != Core.AcqReady:
        time.sleep(0.1)

    assert acq_status.last_image_ready == 0


def test_internal_trigger_multi():
    cam = {{cookiecutter.project_name}}.Camera()
    hw = {{cookiecutter.project_name}}.Interface(cam)
    ct = Core.CtControl(hw)

    acq_status = AcquisitionStatusFromImageStatusCallback()
    ct.registerImageStatusCallback(acq_status)

    acq = ct.acquisition()
    acq.setTriggerMode(Core.IntTrigMult)
    acq.setAcqNbFrames(3)
    acq.setAcqExpoTime(0.01)

    ct.prepareAcq()
    for _ in range(3):
        time.sleep(0.1)
        ct.startAcq()
        # Make sure the detector is ready for next image
        while hw.getStatus().acq != Core.AcqReady:
            time.sleep(0.1)

    while ct.getStatus().AcquisitionStatus != Core.AcqReady:
        time.sleep(0.1)

    assert acq_status.last_image_ready == 2


def test_external_trigger_single():
    cam = {{cookiecutter.project_name}}.Camera()
    hw = {{cookiecutter.project_name}}.Interface(cam)
    ct = Core.CtControl(hw)

    acq_status = AcquisitionStatusFromImageStatusCallback()
    ct.registerImageStatusCallback(acq_status)

    acq = ct.acquisition()
    acq.setTriggerMode(Core.ExtTrigSingle)
    acq.setAcqNbFrames(3)
    acq.setAcqExpoTime(0.01)

    ct.prepareAcq()
    cam.extTrigAcq()  # simulate an external trigger

    while ct.getStatus().AcquisitionStatus != Core.AcqReady:
        time.sleep(0.1)

    assert acq_status.last_image_ready == 2
