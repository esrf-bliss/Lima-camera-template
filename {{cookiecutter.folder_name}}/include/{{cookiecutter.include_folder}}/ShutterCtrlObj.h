//###########################################################################
// This file is part of LImA, a Library for Image Acquisition
//
// Copyright (C) : 2009-2012
// European Synchrotron Radiation Facility
// BP 220, Grenoble 38043
// FRANCE
//
// This is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This software is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, see <http://www.gnu.org/licenses/>.
//###########################################################################

#pragma once

#include "lima/HwInterface.h"

#include <{{cookiecutter.project_name}}_export.h>

#include "{{cookiecutter.include_folder}}/Camera.h"

namespace lima
{
namespace {{cookiecutter.namespace_name}}
{

/// Control object providing camera shutter interface
class {{cookiecutter.uppercase_projectname}}_EXPORT ShutterCtrlObj : public HwShutterCtrlObj {
  DEB_CLASS_NAMESPC(DebModCamera, "ShutterCtrlObj", "{{cookiecutter.project_name}}");

public:
  enum CamShutterMode { FRAME, MANUAL };

  ShutterCtrlObj(Camera &cam);
  virtual ~ShutterCtrlObj();

  virtual bool checkMode(ShutterMode shut_mode) const;
  virtual void getModeList(ShutterModeList &mode_list) const;
  virtual void setMode(ShutterMode shut_mode);
  virtual void getMode(ShutterMode &shut_mode) const;

  virtual void setState(bool shut_open);
  virtual void getState(bool &shut_open) const;

  virtual void setOpenTime(double shut_open_time);
  virtual void getOpenTime(double &shut_open_time) const;
  virtual void setCloseTime(double shut_close_time);
  virtual void getCloseTime(double &shut_close_time) const;

private:
  Camera &m_cam;
  CamShutterMode m_shutter_mode = FRAME;
  bool m_manual_state           = false;
  double m_open_time            = 0.0;
  double m_close_time           = 0.0;
};

} // namespace Iris

} // namespace lima
