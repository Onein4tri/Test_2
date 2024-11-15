/*
 * PressureSensor.h
 *
 *  Created on: Nov 12, 2024
 *      Author: 00352092
 */

// PressureSensor.hpp

#define APPLICATION_USER_CORE_PRESSURESENSOR_HPP_

#ifndef PRESSURE_SENSOR_H
#define PRESSURE_SENSOR_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void ReadPressureData(uint16_t *pressure);

#ifdef __cplusplus
}
#endif

#endif // PRESSURE_SENSOR_H
