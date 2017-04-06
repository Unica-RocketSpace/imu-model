/*
 * ParabolaModel.h
 *
 *  Created on: 6 апр. 2017 г.
 *      Author: snork
 */

#ifndef CPP_FREEFALLMOTIONMODEL_H_
#define CPP_FREEFALLMOTIONMODEL_H_

#include "glm/glm.hpp"

#include <sofa.h>
#include <sofam.h>

#include "MotionModel.h"
#include "DataPoint.h"

namespace Model
{

	class FreeFallMotionModel: public MotionModel
	{
	public:
		FreeFallMotionModel()
		{

		}

	protected:
		virtual DataPoint _do_evaluate(time_t tsince) override
		{
			DataPoint retval;

			int axes[] = {glm::X, glm::Y, glm::Z};
			for (auto axis : axes)
			{
				// считаем по закону равноускоренного движения
				retval.trueData.ri[axis] =
						_ri_start[axis]
						+ (_vi_start[axis] * tsince)
						+ (_gi[axis] * tsince * tsince) / 2.0f;

				retval.trueData.vi[axis] =
						_vi_start[axis] + _gi[axis] * tsince;

				retval.trueData.ai[axis] = _gi[axis];
			}

			return retval;
		}

	private:
		glm::vec3 _gi = glm::vec3(0.0f, 0.0f, 9.81f);
		glm::vec3 _ri_start[3];
		glm::vec3 _vi_start[3];
	};
}

#endif /* CPP_FREEFALLMOTIONMODEL_H_ */
