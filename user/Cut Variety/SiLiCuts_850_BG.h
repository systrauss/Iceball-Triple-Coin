#ifndef SILICUTS_H
#define SILICUTS_H

//In this section, we create the set of cuts that will be used in analysis to make cuts based on the Germanium detectors

static const int nSiLiCutTotal = 6; //Total number of SiLi cuts to make
static const double dSiLiCuts[nSiLiCutTotal][3] = {{0,870,4}, //{Ge number(0-6),centroid, sigma}
												   {1,870,4},
												   {2,870,4},
												   {3,870,4},
												   {4,870,4},
												   {5,870,4}};

#endif