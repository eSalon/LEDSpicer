/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/**
 * @file      Adalight.hpp
 * @since     Jan 10, 2021
 * @author    Bzzrd
 *
 * @copyright Copyright © 2021 Bzzrd
 *
 * @copyright LEDSpicer is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * @copyright LEDSpicer is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * @copyright You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "../Device.hpp"
#include "utility/Utility.hpp"
#include <libserialport.h>

#ifndef ADALIGHT_HPP_
#define ADALIGHT_HPP_ 1

#define ADALIGHT_NAME "AdalightName"

namespace LEDSpicer {
namespace Devices {

/**
 * LEDSpicer::Devices::Adalight
 *
 * Adalight smart led controller (using WLED firmware on ESP8266)
 */
class Adalight : public Device {

public:

	Adalight(
		uint8_t  boardId,
		umap<string, string>& options) :
		Device(
			options.count("leds") ? Utility::parseNumber(options["leds"], "Invalid Value for number of leds") * 3 : 0,
		  ADALIGHT_NAME
		) {}

	virtual ~Adalight() = default;

	virtual void resetLeds();

	string getFullName() const;

	virtual void drawHardwarePinMap();

	virtual void transfer() const;

  virtual void packData();


protected:

	static bool initialized;
	struct sp_port *serialPort;
  int check(enum sp_return result);
	void openDevice();
	void closeDevice();

};

} /* namespace Devices */
} /* namespace LEDSpicer */

deviceFactory(LEDSpicer::Devices::Adalight)

#endif /* ADALIGHT_HPP_ */
