//This file is for the creation of the arrays of histograms to be used with the cuts code. It also contains the fill histograms command.

#include <histograms.h>

//C++ libraries
#include <vector>
#include <iostream>

//ROOT libraries
#include <TH1F.h>
#include <TString.h>
#include <TFile.h>
#include <TDirectory.h>
#include <TObject.h>

//From Coefficients.cxx
extern int nGeOrder; //Order of calibration i.e. 1 = linear.
extern int nGeDets; //Total number of signals from Germanium detectors
extern int nGeSegments; //number of segments in a single Germanium crystal, for adding purposes

extern int nSiLiOrder; //Order of calibration i.e. 1 = linear.
extern int nSiLiDets; //Total number of signals from SiLi
extern int nSiLiPlace; //Start of SiLis in generalized array detectors

//From Constraints.cxx
extern std::vector<std::vector<double> > dGeBounds; //bounds for cuts
extern std::vector<std::vector<double> > dSiLiBounds; //bounds for cuts
extern int nGeConstraints;
extern int nSiLiConstraints;

extern std::vector<std::vector<double> > dGeGeBounds; //bounds for cuts
extern std::vector<std::vector<double> > dGeSiLiBounds; //bounds for cuts
extern std::vector<std::vector<double> > dSiLiSiLiBounds; //bounds for cuts
extern int nGeGeConstraints;
extern int nGeSiLiConstraints;
extern int nSiLiSiLiConstraints;

extern int nBGODets; //Total number of signals from BGO detectors
extern int nBGOPlace; //Start of BGOs in generalized array
extern std::vector<double> dBGOThreshold;

//From main.cxx
extern double dTimeLow;
extern double dTimeHigh;

//From this file
std::vector<std::vector<TH1F*> > ge_en_ge_cut;
std::vector<std::vector<TH1F*> > sili_en_ge_cut;
std::vector<std::vector<TH1F*> > ge_en_sili_cut;
std::vector<std::vector<TH1F*> > sili_en_sili_cut;

std::vector<std::vector<TH1F*> > ge_en_ge_ge_cut;
std::vector<std::vector<TH1F*> > sili_en_ge_ge_cut;
std::vector<std::vector<TH1F*> > ge_en_ge_sili_cut;
std::vector<std::vector<TH1F*> > sili_en_ge_sili_cut;
std::vector<std::vector<TH1F*> > ge_en_sili_sili_cut;
std::vector<std::vector<TH1F*> > sili_en_sili_sili_cut;


//For regular coincidence
void makeHistograms(int nGeDets, int nGeCuts, int nSiLiDets, int nSiLiCuts)
{
	//Vector to make a new row
	std::vector<TH1F*> row;
	//Loop through and construct them all.
	for(int j=0 ; j < nGeDets ; j++)
	{
		ge_en_ge_cut.push_back(row);
		ge_en_sili_cut.push_back(row);
		for(int i=0 ; i < nGeCuts ; i++)
		{
			ge_en_ge_cut[j].push_back( new TH1F(Form("ge_en_ge_cut[%i][%i]",j,i),Form("Clover_%i",j),4000,0.5,4000.5));
		}
		for(int i=0 ; i < nSiLiCuts ; i++)
		{
			ge_en_sili_cut[j].push_back(new TH1F(Form("sili_en_ge_cut[%i][%i]",j,i),Form("SiLi_%i",j+1),4000,0.5,4000.5));
		}
	}
	for(int j=0 ; j < nSiLiDets ; j++)
	{
		sili_en_ge_cut.push_back(row);
		sili_en_sili_cut.push_back(row);
		for(int i=0 ; i < nGeCuts ; i++)
		{
			sili_en_ge_cut[j].push_back(new TH1F(Form("ge_en_sili_cut[%i][%i]",j,i),Form("Clover_%i",j),4000,0.5,4000.5));
		}
		for(int i=0 ; i < nSiLiCuts ; i++)
		{
			sili_en_sili_cut[j].push_back(new TH1F(Form("sili_en_sili_cut[%i][%i]",j,i),Form("SiLi_%i",j+1),4000,0.5,4000.5));
		}
	}
}

//For triple coincidence
void makeHistograms(int nGeDets, int nSiLiDets, int nGeGeCuts, int nGeSiLiCuts, int nSiLiSiLiCuts)
{
	//Vector to make a new row
	std::vector<TH1F*> row;
	//Loop through and construct them all.
	for(int j=0 ; j < nGeDets ; j++)
	{
		ge_en_ge_ge_cut.push_back(row);
		ge_en_ge_sili_cut.push_back(row);
		ge_en_sili_sili_cut.push_back(row);
		for(int i=0 ; i < nGeGeCuts ; i++)
		{
			ge_en_ge_ge_cut[j].push_back( new TH1F(Form("ge_en_ge_ge_cut[%i][%i]",j,i),Form("Clover_%i",j),4000,0.5,4000.5));
		}
		for(int i=0 ; i < nGeSiLiCuts ; i++)
		{
			ge_en_ge_sili_cut[j].push_back(new TH1F(Form("ge_en_ge_sili_cut[%i][%i]",j,i),Form("Clover_%i",j),4000,0.5,4000.5));
		}
		for(int i=0 ; i < nSiLiSiLiCuts ; i++)
		{
			ge_en_sili_sili_cut[j].push_back(new TH1F(Form("ge_en_sili_sili_cut[%i][%i]",j,i),Form("Clover_%i",j),4000,0.5,4000.5));
		}
	}
	for(int j=0 ; j < nSiLiDets ; j++)
	{
		sili_en_ge_ge_cut.push_back(row);
		sili_en_ge_sili_cut.push_back(row);
		sili_en_sili_sili_cut.push_back(row);
		for(int i=0 ; i < nGeGeCuts ; i++)
		{
			sili_en_ge_ge_cut[j].push_back( new TH1F(Form("sili_en_ge_ge_cut[%i][%i]",j,i),Form("SiLi_%i",j+1),4000,0.5,4000.5));
		}
		for(int i=0 ; i < nGeSiLiCuts ; i++)
		{
			sili_en_ge_sili_cut[j].push_back(new TH1F(Form("sili_en_ge_sili_cut[%i][%i]",j,i),Form("SiLi_%i",j+1),4000,0.5,4000.5));
		}
		for(int i=0 ; i < nSiLiSiLiCuts ; i++)
		{
			sili_en_sili_sili_cut[j].push_back(new TH1F(Form("sili_en_sili_sili_cut[%i][%i]",j,i),Form("SiLi_%i",j+1),4000,0.5,4000.5));
		}
	}
}

//Regular, singular coincidence
void fillHistograms(int nConstraints, std::vector<std::vector<double> >dConstraints, std::vector<double> dEnCut, std::vector<double> dGeDetectors, std::vector<double> dSiLiDetectors, std::vector<double> dBGO, std::vector<double> dGeT, std::vector<double> dSiLiT, bool GeorSiLi/*true  = ge gate, false = sili gate*/)
{
	for(int i=0; i<nConstraints ; i++)
	{
		if((dEnCut[(int)dConstraints[i][0]] > dConstraints[i][1] && //gate detector lower limit
			dEnCut[(int)dConstraints[i][0]] < dConstraints[i][2] && //gate detector upper limit
			GeorSiLi                                             && //is germanium
			dBGO[(int)dConstraints[i][0]] < dBGOThreshold[(int)dConstraints[i][0]]) //BGO Threshold met
			|| //OR (above is Ge constraint, below is SiLi)
		   (dEnCut[(int)dConstraints[i][0]] > dConstraints[i][1] && //gate detector lower limit
		   	dEnCut[(int)dConstraints[i][0]] < dConstraints[i][2] && //gate detector upper limit
		   	!GeorSiLi)) //is SiLi
		{
			//Fill Germanium histograms, includes BGO thresholds and timing
			for(int j = 0 ; j < nGeDets/nGeSegments ; j++)
			{
				if(GeorSiLi && dConstraints[i][0] != j && dBGO[j] < dBGOThreshold[j]) // if Ge gate AND gate detector is not this detector AND BGO is under threshold)
				{
					if( dGeDetectors[j] > 5 && (dGeT[(int)dConstraints[i][0]]-dGeT[j]) >= dTimeLow && (dGeT[(int)dConstraints[i][0]]-dGeT[j]) <= dTimeHigh) ge_en_ge_cut[j][i]->Fill(dGeDetectors[j]); //If detector energy > 5 keV AND timing between this detector and gate detector is +/- 0.3, fill this detector-gate combo
				}
				else if (!GeorSiLi && dBGO[j] < dBGOThreshold[j])
				{
					if( dGeDetectors[j] > 5 && (dSiLiT[(int)dConstraints[i][0]]-dGeT[j]) >= dTimeLow && (dSiLiT[(int)dConstraints[i][0]]-dGeT[j]) <= dTimeHigh) ge_en_sili_cut[j][i]->Fill(dGeDetectors[j]);
				}
			}
			//Fill SiLi histograms, includes timing
			for(int j = 0 ; j < nSiLiDets ; j++)
			{
				if(GeorSiLi)
				{
					if(dSiLiDetectors[j] > 10 && (dGeT[(int)dConstraints[i][0]]-dSiLiT[j]) >= dTimeLow && (dGeT[(int)dConstraints[i][0]]-dSiLiT[j]) <= dTimeHigh) sili_en_ge_cut[j][i]->Fill(dSiLiDetectors[j]);
				}
				else if (!GeorSiLi && dConstraints[i][0] != j)
				{
					if(dSiLiDetectors[j] > 10 && (dSiLiT[(int)dConstraints[i][0]]-dSiLiT[j]) >= dTimeLow && (dSiLiT[(int)dConstraints[i][0]]-dSiLiT[j]) <= dTimeHigh) sili_en_sili_cut[j][i]->Fill(dSiLiDetectors[j]);
				}
			}
		}
	}
}

//Triple coincidence
void fillHistograms(int nConstraints, std::vector<std::vector<double> >dConstraints, std::vector<double> dEnCut1, std::vector<double> dEnCut2,std::vector<double> dGeDetectors, std::vector<double> dSiLiDetectors, std::vector<double> dBGO, std::vector<double> dGeT, std::vector<double> dSiLiT, bool GeorSiLi1/*true  = ge gate, false = sili gate*/, bool GeorSiLi2)
{
	for(int i=0; i<nConstraints ; i++)
	{
		if((dEnCut1[(int)dConstraints[i][0]] > dConstraints[i][1] && //gate detector 1 lower limit
			dEnCut1[(int)dConstraints[i][0]] < dConstraints[i][2] && //gate detector 1 upper limit
			GeorSiLi1                                             && //is germanium
			dBGO[(int)dConstraints[i][0]] < dBGOThreshold[(int)dConstraints[i][0]]) //BGO Threshold met
			|| //OR (above is Ge constraint, below is SiLi)
		   (dEnCut1[(int)dConstraints[i][0]] > dConstraints[i][1] && //gate detector 1 lower limit
		   	dEnCut1[(int)dConstraints[i][0]] < dConstraints[i][2] && //gate detector 1 upper limit
		   	!GeorSiLi1)
			&&
			(dEnCut2[(int)dConstraints[i][3]] > dConstraints[i][4] && //gate detector 2 lower limit
			dEnCut2[(int)dConstraints[i][3]] < dConstraints[i][5] && //gate detector 2 upper limit
			GeorSiLi2                                             && //is germanium
			dBGO[(int)dConstraints[i][3]] < dBGOThreshold[(int)dConstraints[i][3]]) //BGO Threshold met
			|| //OR (above is Ge constraint, below is SiLi)
		   (dEnCut2[(int)dConstraints[i][3]] > dConstraints[i][4] && //gate detector 2 lower limit
		   	dEnCut2[(int)dConstraints[i][3]] < dConstraints[i][5] && //gate detector 2 upper limit
		   	!GeorSiLi2)) //is SiLi
		{
			//Fill Germanium histograms, includes BGO thresholds and timing
			for(int j = 0 ; j < nGeDets/nGeSegments ; j++)
			{
				if(GeorSiLi1 && dConstraints[i][0] != j && GeorSiLi2 && dConstraints[i][3] != j && dBGO[j] < dBGOThreshold[j]) // if Ge gate1 and Ge gate 2 AND gate detectors are not this detector AND BGO is under threshold)
				{
					if( dGeDetectors[j] > 5 && (dGeT[(int)dConstraints[i][0]]-dGeT[j]) >= dTimeLow && (dGeT[(int)dConstraints[i][0]]-dGeT[j]) <= dTimeHigh && (dGeT[(int)dConstraints[i][3]]-dGeT[j]) >= dTimeLow && (dGeT[(int)dConstraints[i][3]]-dGeT[j]) <= dTimeHigh) ge_en_ge_ge_cut[j][i]->Fill(dGeDetectors[j]); //If detector energy > 5 keV AND timing between this detector and gate detectors is +/- 0.3, fill this detector-gate combo
				}
				else if(GeorSiLi1 && dConstraints[i][0] != j && !GeorSiLi2 &&  dBGO[j] < dBGOThreshold[j]) // if Ge gate1 and SiLi gate 2 AND gate detectors are not this detector AND BGO is under threshold)
				{
					if( dGeDetectors[j] > 5 && (dGeT[(int)dConstraints[i][0]]-dGeT[j]) >= dTimeLow && (dGeT[(int)dConstraints[i][0]]-dGeT[j]) <= dTimeHigh && (dSiLiT[(int)dConstraints[i][3]]-dGeT[j]) >= dTimeLow && (dSiLiT[(int)dConstraints[i][3]]-dGeT[j]) <= dTimeHigh) ge_en_ge_sili_cut[j][i]->Fill(dGeDetectors[j]); //If detector energy > 5 keV AND timing between this detector and gate detectors is +/- 0.3, fill this detector-gate combo
				}
				else if (!GeorSiLi1 && !GeorSiLi2 && dBGO[j] < dBGOThreshold[j]) //if Sili gate 1 and Sili gate 2 AND BGO is under threshold
				{
					if( dGeDetectors[j] > 5 && (dSiLiT[(int)dConstraints[i][0]]-dGeT[j]) >= dTimeLow && (dSiLiT[(int)dConstraints[i][0]]-dGeT[j]) <= dTimeHigh && (dSiLiT[(int)dConstraints[i][3]]-dGeT[j]) >= dTimeLow && (dSiLiT[(int)dConstraints[i][3]]-dGeT[j]) <= dTimeHigh) ge_en_sili_sili_cut[j][i]->Fill(dGeDetectors[j]);
				}
			}
			//Fill SiLi histograms, includes timing
			for(int j = 0 ; j < nSiLiDets ; j++)
			{
				if(GeorSiLi1 && GeorSiLi2) //ge gate 1 and ge gate 2
				{
					if(dSiLiDetectors[j] > 10 && (dGeT[(int)dConstraints[i][0]]-dSiLiT[j]) >= dTimeLow && (dGeT[(int)dConstraints[i][0]]-dSiLiT[j]) <= dTimeHigh && (dGeT[(int)dConstraints[i][3]]-dSiLiT[j]) >= dTimeLow && (dGeT[(int)dConstraints[i][3]]-dSiLiT[j]) <= dTimeHigh) sili_en_ge_ge_cut[j][i]->Fill(dSiLiDetectors[j]);
				}
				else if (GeorSiLi1 && !GeorSiLi2 && dConstraints[i][3] != j) //ge gate 1 and sili gate 2 and gate detector is not this detector
				{
					if(dSiLiDetectors[j] > 10 && (dGeT[(int)dConstraints[i][0]]-dSiLiT[j]) >= dTimeLow && (dGeT[(int)dConstraints[i][0]]-dSiLiT[j]) <= dTimeHigh && (dSiLiT[(int)dConstraints[i][3]]-dSiLiT[j]) >= dTimeLow && (dSiLiT[(int)dConstraints[i][3]]-dSiLiT[j]) <= dTimeHigh) sili_en_ge_sili_cut[j][i]->Fill(dSiLiDetectors[j]);
				}
				else if (GeorSiLi1 && !GeorSiLi2 && dConstraints[i][0] != j && dConstraints[i][3] != j) //ge gate 1 and sili gate 2 and neither is detector
				{
					if(dSiLiDetectors[j] > 10 && (dSiLiT[(int)dConstraints[i][0]]-dSiLiT[j]) >= dTimeLow && (dSiLiT[(int)dConstraints[i][0]]-dSiLiT[j]) <= dTimeHigh && (dSiLiT[(int)dConstraints[i][3]]-dSiLiT[j]) >= dTimeLow && (dSiLiT[(int)dConstraints[i][3]]-dSiLiT[j]) <= dTimeHigh) sili_en_sili_sili_cut[j][i]->Fill(dSiLiDetectors[j]);
				}
			}
		}
	}
}

void writeHistToFile(TFile* fOut, bool bTripleCoin)
{
	if(!bTripleCoin)
	{
		for(int i=0; i<nGeConstraints ; i++)
		{
			fOut->cd();
			gDirectory->mkdir(Form("Ge Cut Detector %i, Peak %f",(int)dGeBounds[i][0],(dGeBounds[i][1]+dGeBounds[i][2])/2));
			fOut->cd(Form("Ge Cut Detector %i, Peak %f",(int)dGeBounds[i][0],(dGeBounds[i][1]+dGeBounds[i][2])/2));
			for(int j=0; j<nGeDets/nGeSegments ; j++)
			{
				ge_en_ge_cut[j][i]->Write(Form("Clover_%i",j),TObject::kOverwrite,1E8);
			}
			for(int j=0; j<nSiLiDets ; j++)
			{
				sili_en_ge_cut[j][i]->Write(Form("SiLi_%i",j+1),TObject::kOverwrite,1E8);
			}
		}
		for(int i=0; i<nSiLiConstraints ; i++)
		{
			fOut->cd();
			gDirectory->mkdir(Form("SiLi Cut Detector %i, Peak %f",(int)dSiLiBounds[i][0]+1,(dSiLiBounds[i][1]+dSiLiBounds[i][2])/2));
			fOut->cd(Form("SiLi Cut Detector %i, Peak %f",(int)dSiLiBounds[i][0]+1,(dSiLiBounds[i][1]+dSiLiBounds[i][2])/2));
			for(int j=0; j<nGeDets/nGeSegments ; j++)
			{
				ge_en_sili_cut[j][i]->Write(Form("Clover_%i",j),TObject::kOverwrite,1E8);
			}
			for(int j=0; j<nSiLiDets ; j++)
			{
				sili_en_sili_cut[j][i]->Write(Form("SiLi_%i",j+1),TObject::kOverwrite,1E8);
			}
		}
	}
	else
	{
		for(int i=0; i<nGeGeConstraints ; i++)
		{
			fOut->cd();
			gDirectory->mkdir(Form("Ge Cut Detector %i, Peak %f, Ge Cut Detector %i, Peak %f",(int)dGeGeBounds[i][0],(dGeGeBounds[i][1]+dGeGeBounds[i][2])/2, (int)dGeGeBounds[i][3],(dGeGeBounds[i][4]+dGeGeBounds[i][5])/2));
			fOut->cd(Form("Ge Cut Detector %i, Peak %f, Ge Cut Detector %i, Peak %f",(int)dGeGeBounds[i][0],(dGeGeBounds[i][1]+dGeGeBounds[i][2])/2, (int)dGeGeBounds[i][3],(dGeGeBounds[i][4]+dGeGeBounds[i][5])/2));
			for(int j=0; j<nGeDets/nGeSegments ; j++)
			{
				ge_en_ge_ge_cut[j][i]->Write(Form("Clover_%i",j),TObject::kOverwrite,1E8);
			}
			for(int j=0; j<nSiLiDets ; j++)
			{
				sili_en_ge_ge_cut[j][i]->Write(Form("SiLi_%i",j+1),TObject::kOverwrite,1E8);
			}
		}
		for(int i=0; i<nGeSiLiConstraints ; i++)
		{
			fOut->cd();
			gDirectory->mkdir(Form("Ge Cut Detector %i, Peak %f, SiLi Cut Detector %i, Peak %f",(int)dGeSiLiBounds[i][0],(dGeSiLiBounds[i][1]+dGeSiLiBounds[i][2])/2, (int)dGeSiLiBounds[i][3],(dGeSiLiBounds[i][4]+dGeSiLiBounds[i][5])/2));
			fOut->cd(Form("Ge Cut Detector %i, Peak %f, SiLi Cut Detector %i, Peak %f",(int)dGeSiLiBounds[i][0],(dGeSiLiBounds[i][1]+dGeSiLiBounds[i][2])/2, (int)dGeSiLiBounds[i][3],(dGeSiLiBounds[i][4]+dGeSiLiBounds[i][5])/2));
			for(int j=0; j<nGeDets/nGeSegments ; j++)
			{
				ge_en_ge_sili_cut[j][i]->Write(Form("Clover_%i",j),TObject::kOverwrite,1E8);
			}
			for(int j=0; j<nSiLiDets ; j++)
			{
				sili_en_ge_sili_cut[j][i]->Write(Form("SiLi_%i",j+1),TObject::kOverwrite,1E8);
			}
		}
		for(int i=0; i<nSiLiSiLiConstraints ; i++)
		{
			fOut->cd();
			gDirectory->mkdir(Form("SiLi Cut Detector %i, Peak %f, SiLi Cut Detector %i, Peak %f",(int)dSiLiSiLiBounds[i][0],(dSiLiSiLiBounds[i][1]+dSiLiSiLiBounds[i][2])/2, (int)dSiLiSiLiBounds[i][3],(dSiLiSiLiBounds[i][4]+dSiLiSiLiBounds[i][5])/2));
			fOut->cd(Form("SiLi Cut Detector %i, Peak %f, SiLi Cut Detector %i, Peak %f",(int)dSiLiSiLiBounds[i][0],(dSiLiSiLiBounds[i][1]+dSiLiSiLiBounds[i][2])/2, (int)dSiLiSiLiBounds[i][3],(dSiLiSiLiBounds[i][4]+dSiLiSiLiBounds[i][5])/2));
			for(int j=0; j<nGeDets/nGeSegments ; j++)
			{
				ge_en_sili_sili_cut[j][i]->Write(Form("Clover_%i",j),TObject::kOverwrite,1E8);
			}
			for(int j=0; j<nSiLiDets ; j++)
			{
				sili_en_sili_sili_cut[j][i]->Write(Form("SiLi_%i",j+1),TObject::kOverwrite,1E8);
			}
		}
	}
	fOut->Write();

}