/*
 * Copyright (c) 2005-2019 Libor Pecháček.
 *
 * This file is part of CoVe 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef COVE_FIRFILTER_H
#define COVE_FIRFILTER_H

#include <vector>

#include <QImage>
#include <QRgb>

namespace cove {
class ProgressObserver;

class FIRFilter
{
protected:
	std::vector<std::vector<double>> matrix;

public:
	FIRFilter(unsigned radius = 0);
	FIRFilter& binomic();
	FIRFilter& box();
	FIRFilter& a(double center);
	QImage apply(const QImage& source,
	             QRgb outOfBoundsColor = qRgb(128, 128, 128),
	             ProgressObserver* progressObserver = nullptr);
};
} // cove

#endif
