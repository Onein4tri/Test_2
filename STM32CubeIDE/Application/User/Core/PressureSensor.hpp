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

void ReadPressureData(void);
float ConvertPressureToMMHg(float pressure_psi);
extern float pressure_mmhg;
extern uint16_t scaled_pressure; // Holds the y-axis value for the graph

#ifdef __cplusplus
}
#endif

#endif // PRESSURE_SENSOR_H
