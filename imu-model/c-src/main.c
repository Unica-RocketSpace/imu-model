/*
 * main.c
 *
 *  Created on: 5 апр. 2017 г.
 *      Author: snork
 */

#include <unistd.h>
#include <stdio.h>
#include <math.h>

#include <sofa/sofam.h>

#include "../model/model.h"
#include <sofa/sofa.h>


int main()
{

	float rstart[3] = {0,0,100};
	float vstart[3] = {0,0,0};
	float a[3]		= {0,0,-9.8};
	float oscfreq = 0; //0.02;
	float oscmagn = DD2R * 45.0f;
	float rotfreq = 0.1;

	model_t * model = model_init_freefal(rstart, vstart, a, oscfreq, oscmagn, rotfreq);

	for (float tsince = 0.f ; tsince < 10.f; tsince += 1.0f)
	{
		data_point_t dp = model_evaluate(model, tsince);
		/*
		printf("tri[% 10.4f, %10.4f, %10.4f]", dp.trueData.ri[0], dp.trueData.ri[1], dp.trueData.ri[2]);
		printf(" ");
		printf("tvi[% 10.4f, %10.4f, %10.4f]", dp.trueData.vi[0], dp.trueData.vi[1], dp.trueData.vi[2]);
		printf(" ");
		printf("tai[% 10.4f, %10.4f, %10.4f]", dp.trueData.ai[0], dp.trueData.ai[1], dp.trueData.ai[2]);
		printf("\n");
		*/

		printf("ofa[% 10.4f, %10.4f, %10.4f]", dp.obsData.af[0], dp.obsData.af[1], dp.obsData.af[2]);
		printf(" ");
		printf("ofw[% 10.4f, %10.4f, %10.4f]", dp.obsData.wf[0], dp.obsData.wf[1], dp.obsData.wf[2]);
		printf(" ");

		float x_fixed[3] = {1, 0, 0};
		float x_fixed_in_ics[3];
		//iauTr(dp.trueData.f_to_i, dp.trueData.f_to_i);
		iauRxp(dp.trueData.f_to_i, x_fixed, x_fixed_in_ics);
		printf("xfi[% 10.4f, %10.4f, %10.4f]", x_fixed_in_ics[0], x_fixed_in_ics[1], x_fixed_in_ics[2]);

		printf("\n");
	}



	return 0;
}

