/*
 * Model.h
 *
 *  Created on: 6 апр. 2017 г.
 *      Author: snork
 */

#ifndef CPP_MOTIONMODEL_H_
#define CPP_MOTIONMODEL_H_

#include "DataPoint.h"

namespace Model
{

	class MotionModel
	{
	public:
		MotionModel() = default;
		virtual ~MotionModel() = default;

		DataPoint evaluate(time_t tsince)
		{
			return _do_evaluate(tsince);
		}

	private:
		virtual DataPoint _do_evaluate(time_t tsince) = 0;
	};

}

#endif /* CPP_MOTIONMODEL_H_ */
