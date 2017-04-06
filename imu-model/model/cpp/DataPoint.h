/*
 * DataPoint.h
 *
 *  Created on: 6 апр. 2017 г.
 *      Author: snork
 */

#ifndef CPP_DATAPOINT_H_
#define CPP_DATAPOINT_H_

#include <glm/vec3.hpp>
#include <glm/mat3x3.hpp>


namespace Model
{
	typedef float time_t;

	struct TrueData
	{
		glm::vec3 ri;
		glm::vec3 vi;
		glm::vec3 ai;
		glm::mat3 i_to_f;
	};

	struct SensorsData
	{
		glm::vec3 af;
		glm::vec3 wf;
	};


	struct DataPoint
	{
	public:
		TrueData trueData;
		SensorsData sensorsData;
	};
}


#endif /* CPP_DATAPOINT_H_ */
