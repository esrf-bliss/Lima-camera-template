//###########################################################################
// This file is part of LImA, a Library for Image Acquisition
//
// Copyright (C) : 2009-2011
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

#include "{{cookiecutter.namespace_name}}/DetInfoCtrlObj.h"

using namespace lima;
using namespace lima::{{cookiecutter.namespace_name}};

void DetInfoCtrlObj::getMaxImageSize(Size &max_image_size)
{
  DEB_MEMBER_FUNCT();
  // TODO
}

void DetInfoCtrlObj::getDetectorImageSize(Size &det_image_size)
{
  DEB_MEMBER_FUNCT();
  // TODO
}

void DetInfoCtrlObj::getDefImageType(ImageType &def_image_type)
{
  DEB_MEMBER_FUNCT();
  // TODO
}

void DetInfoCtrlObj::setCurrImageType(ImageType curr_image_type)
{
  DEB_MEMBER_FUNCT();
  // TODO
}

void DetInfoCtrlObj::getCurrImageType(ImageType &curr_image_type)
{
  DEB_MEMBER_FUNCT();
  // TODO
}

void DetInfoCtrlObj::getPixelSize(double &x_size, double &y_size)
{
  DEB_MEMBER_FUNCT();
  // TODO
}

void DetInfoCtrlObj::getDetectorType(std::string &det_type)
{
  DEB_MEMBER_FUNCT();
  det_type = "Iris";
}

void DetInfoCtrlObj::getDetectorModel(std::string &det_model)
{
  DEB_MEMBER_FUNCT();
  // TODO
}

void DetInfoCtrlObj::registerMaxImageSizeCallback(HwMaxImageSizeCallback &cbk)
{
  DEB_MEMBER_FUNCT();

  // TODO
}

void DetInfoCtrlObj::unregisterMaxImageSizeCallback(HwMaxImageSizeCallback &cbk)
{
  DEB_MEMBER_FUNCT();

  // TODO
}
