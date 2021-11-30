#include <TVector3.h>
#include <TCanvas.h>
#include <iostream>
#include <TLorentzVector.h>
#include <TH1D.h>
#include <string>
#include <cstring>

const double PI = 3.1415926;


class HIST
{
	public:
		HISR(string str);
		void SetColor(int numberLineColor, int numberFillColor);
		void Scale(double weight);
		void SetLineWidth(int width);

		TH1D *MuonE;
		TH1D *MuonP;
		TH1D *PionE;
		TH1D *PionP;
		TH1D *Gamma1E;
		TH1D *Gamma1P;
		TH1D *Gamma2E;
		TH1D *Gamma2P;
		TH1D *EtaM;
		TH1D *EtaP;
		TH1D *EtaE;
};

class STACK
{
		STACK();

		THStack *STMuonE;
		THStack *STMuonP;
		THStack *STPionE;
		THStack *STPionP;
		THStack *STGamma1E;
		THStack *STGamma1P;
		THStack *STGamma2E;
		THStack *STGamma2P;
		THStack *STEtaM;
		THStack *STEtaP;
		THStack *STEtaE;
};



char* makeName(string str1,string str2);

void FillInHisto(char *fileAdd,HIST *hist);

void AddInStack(HIST *hist,STACK *sta);



//********************** main function!!! **********************//


void mainAnalysis()
{
	HIST exMC("exMC");
	HIST inMC("inMC");

	FillInHisto("$GGAMMAMUPIDATE/analysis/e3.554_etapinu.root",&exMC);
	FillInHisto("$GGAMMAMUPIDATE/analysis/e3.5539_incMC.root",&inMC);
	
	exMC.Scale(1);  
	inMC.Scale(1);

	exMC.SetLineWidth(3);
	inMC.SetLineWidth(3);

	exMC.SetColor(622,0);//red
	inMC.SetColor(590,0);//blue

	auto temp = new TCanvas();
	
	inMC.MuonE->Draw("hist");
	exMC.MuonP->Draw("sameHist");
	auto legend = new TLegend(0.78,0.77,0.98,0.9);
	legend->AddEntry(inMC.MuonE,"inMC","f");
   	legend->AddEntry(exMC.MuonE,"exMC","f");
	legend->DrawClone();

	
	return ;
}



//**********************************************************//

const int binNumber = 100;
const double startNumber = 0;
const double endNumber = 2;

void HIST::HIST(string str)
{

	char *name;

	name = makeName(str,"MuonE");
	MuonE = new TH1D(name,"MuonE",binNumber,startNumber,endNumber);
	delete name;

	name = makeName(str,"MuonP");
	MuonP = new TH1D(name,"MuonP",binNumber,startNumber,endNumber);
	delete name;

	name = makeName(str,"PionE");
	PionE = new TH1D(name,"PionE",binNumber ,startNumber ,endNumber);
	delete name;

	name = makeName(str,"PionP");
	PionP = new TH1D(name,"PionP",binNumber,startNumber,endNumber);
	delete name;

	name = makeName(str,"Gamma1E");
	Gamma1E = new TH1D(name,"Gamma1E",binNumber,startNumber,endNumber);
	delete name;

	name = makeName(str,"Gamma1P");
	Gamma1P = new TH1D(name,"Gamma1P",binNumber,startNumber,endNumber);
	delete name;

	name = makeName(str,"Gamma2E");
	Gamma2E = new TH1D(name,"Gamma2E",binNumber,startNumber,endNumber);
	delete name;

	name = makeName(str,"Gamma2P");
	Gamma2P = new TH1D(name,"Gamma2P",binNumber,startNumber,endNumber);
	delete name;

	name = makeName(str,"EtaM");
	EtaM = new TH1D(name,"EtaM",binNumber,startNumber,endNumber);
	delete name;

	name = makeName(str,"EtaP");
	EtaP = new TH1D(name,"EtaP",binNumber,startNumber,endNumber);
	delete name;

	name = makeName(str,"EtaE");
	EtaE = new TH1D(name,"EtaE",binNumber,startNumber,endNumber);
	delete name;
}




//**********************************************************//

void HIST::SetColor(int numberLineColor, int numberFillColor)
{
	MuonE->SetFillColor(numberFillColor);
	MuonE->SetLineColor(numberLineColor);

	MuonP->SetFillColor(numberFillColor);
	MuonP->SetLineColor(numberLineColor);

	PionE->SetFillColor(numberFillColor);
	PionE->SetLineColor(numberLineColor);

	PionP->SetFillColor(numberFillColor);
	PionP->SetLineColor(numberLineColor);

	Gamma1E->SetFillColor(numberFillColor);
	Gamma1E->SetLineColor(numberLineColor);

	Gamma1P->SetFillColor(numberFillColor);
	Gamma1P->SetLineColor(numberLineColor);

	Gamma2E->SetFillColor(numberFillColor);
	Gamma2E->SetLineColor(numberLineColor);

	Gamma2P->SetFillColor(numberFillColor);
	Gamma2P->SetLineColor(numberLineColor);

	EtaM->SetFillColor(numberFillColor);
	EtaM->SetLineColor(numberLineColor);

	EtaP->SetFillColor(numberFillColor);
	EtaP->SetLineColor(numberLineColor);

	EtaE->SetFillColor(numberFillColor);
	EtaE->SetLineColor(numberLineColor);

	return;
}


//**********************************************************//


void HIST::Scale(double weight)
{

	MuonE->Scale(weight);
	MuonP->Scale(weight);
	PionE->Scale(weight);
	PionP->Scale(weight);
	Gamma1E->Scale(weight);
	Gamma1P->Scale(weight);
	Gamma2E->Scale(weight);
	Gamma2P->Scale(weight);
	EtaM->Scale(weight);
	EtaP->Scale(weight);
	EtaE->Scale(weight);


	return;
}





//***********************************************************//


void HIST::SetLineWidth(int width)
{

	MuonE->SetLineWidth(width);
	MuonP->SetLineWidth(width);
	PionE->SetLineWidth(width);
	PionP->SetLineWidth(width);
	Gamma1E->SetLineWidth(width);
	Gamma1P->SetLineWidth(width);
	Gamma2E->SetLineWidth(width);
	Gamma2P->SetLineWidth(width);
	EtaM->SetLineWidth(width);
	EtaP->SetLineWidth(width);
	EtaE->SetLineWidth(width);

	return;
}




//***********************************************************//


void STACK::STACK()
{


	STMuonE = new THStack("MuonE","MuonE");
	STMuonP = new THStack("MuonP","MuonP");
	STPionE = new THStack("PionE","PionE");
	STPionP = new THStack("PionP","PionP");
	STGamma1E = new THStack("Gamma1E","Gamma1E");
	STGamma1P = new THStack("Gamma1P","Gamma1P");
	STGamma2E = new THStack("Gamma2E","Gamma2E");
	STGamma2P = new THStack("Gamma2P","Gamma2P");
	STEtaM = new THStack("EtaM","EtaM");
	STEtaP = new THStack("EtaP","EtaP");
	STEtaE = new THStack("EtaE","EtaE");


}



//**********************************************************//

char* makeName(string str1,string str2)
{
	string stringName = str1 + str2;
	char *name;
	name = new char[strlen(stringName.c_str())+1];
	strcpy(name,stringName.c_str());
	return name;
}





//***********************************************************//



void AddInStack(HIST *hist,STACK *sta)
{

	sta->STMuonE->Add(hist->STMuonE);
	sta->STMuonP->Add(hist->STMuonP);
	sta->STPionE->Add(hist->STPionE);
	sta->STPionP->Add(hist->STPionP);
	sta->STGamma1E->Add(hist->STGamma1E);
	sta->STGamma1P->Add(hist->STGamma1P);
	sta->STGamma2E->Add(hist->STGamma2E);
	sta->STGamma2P->Add(hist->STGamma2P);
	sta->STEtaM->Add(hist->STEtaM);
	sta->STEtaP->Add(hist->STEtaP);
	sta->STEtaE->Add(hist->STEtaE);
}


//***********************************************************//

void FillInHisto(char *fileAdd,HIST *hist)
{

	TFile *file = new TFile(fileAdd);
	TTree *muonm = (TTree*)file->Get("muonm");



//read the date
	Double_t MuonP_Px = 0;
	Double_t MuonP_Py = 0;
	Double_t MuonP_Pz = 0;
	Double_t MuonP_E = 0;
	Double_t MuonP_M = 0;
	Double_t MuonP_P3 = 0;
	Double_t Muonp_Theta = 0;
	Double_t Muonp_Phi = 0;

	Double_t PionM_Px = 0;
	Double_t PionM_Py = 0;
	Double_t PionM_Pz = 0;
	Double_t PionM_E = 0;
	Double_t PionM_M = 0;
	Double_t PionM_P3 = 0;
	Double_t Pionm_Theta = 0;
	Double_t Pionm_Phi = 0;

	Double_t Gamma1_Px = 0;
	Double_t Gamma1_Py = 0;
	Double_t Gamma1_Pz = 0;
	Double_t Gamma1_E = 0;
	Double_t Gamma1_P3 = 0;
	Double_t Gamma1_Theta = 0;
	Double_t Gamma1_Phi = 0;

	Double_t Gamma2_Px = 0;
	Double_t Gamma2_Py = 0;
	Double_t Gamma2_Pz = 0;
	Double_t Gamma2_E = 0;
	Double_t Gamma2_P3 = 0;
	Double_t Gamma2_Theta = 0;
	Double_t Gamma2_Phi = 0;

	Double_t Eta_E = 0;
	Double_t Eta_M = 0;
	Double_t Eta_P3 = 0;
	Double_t Eta_Theta = 0;
	Double_t Eta_Phi = 0;


	muonm->SetBranchAddress("muonp_px",&MuonP_Px);
	muonm->SetBranchAddress("muonp_py",&MuonP_Py);
	muonm->SetBranchAddress("muonp_pz",&MuonP_Pz);
	muonm->SetBranchAddress("muonp_E",&MuonP_E);
	muonm->SetBranchAddress("muonp_m",&MuonP_M);
	muonm->SetBranchAddress("muonp_p3",&MuonP_P3);
	muonm->SetBranchAddress("muonp_theta",&Muonp_Theta);
	muonm->SetBranchAddress("muonp_phi",&Muonp_Phi);

	muonm->SetBranchAddress("pionm_px",&PionM_Px);
	muonm->SetBranchAddress("pionm_py",&PionM_Py);
	muonm->SetBranchAddress("pionm_pz",&PionM_Pz);
	muonm->SetBranchAddress("pionm_E",&PionM_E);
	muonm->SetBranchAddress("pionm_m",&PionM_M);
	muonm->SetBranchAddress("pionm_p3",&PionM_P3);
	muonm->SetBranchAddress("pionm_theta",&Pionm_Theta);
	muonm->SetBranchAddress("pionm_phi",&Pionm_Phi);

	muonm->SetBranchAddress("gamma1_px",&Gamma1_Px);
	muonm->SetBranchAddress("gamma1_py",&Gamma1_Py);
	muonm->SetBranchAddress("gamma1_pz",&Gamma1_Pz);
	muonm->SetBranchAddress("gamma1_E",&Gamma1_E);
	muonm->SetBranchAddress("gamma1_p",&Gamma1_P3);
	muonm->SetBranchAddress("gamma1_theta",&Gamma1_Theta);
	muonm->SetBranchAddress("gamma1_phi",&Gamma1_Phi);

	muonm->SetBranchAddress("gamma2_px",&Gamma2_Px);
	muonm->SetBranchAddress("gamma2_py",&Gamma2_Py);
	muonm->SetBranchAddress("gamma2_pz",&Gamma2_Pz);
	muonm->SetBranchAddress("gamma2_E",&Gamma2_E);
	muonm->SetBranchAddress("gamma2_p",&Gamma2_P3);
	muonm->SetBranchAddress("gamma2_theta",&Gamma2_Theta);
	muonm->SetBranchAddress("gamma2_phi",&Gamma2_Phi);

	muonm->SetBranchAddress("eta_p",&Eta_P3);
	muonm->SetBranchAddress("eta_theta",&Eta_Theta);
	muonm->SetBranchAddress("eta_phi",&Eta_Phi);
	muonm->SetBranchAddress("eta_m",&Eta_M);
	muonm->SetBranchAddress("eta_E",&Eta_E);




//number of event
	int Event_Number = 0;

	Event_Number = muonm->GetEntries();


//do
	for(int i = 0; i<Event_Number; i++)
	{
		muonm->GetEntry(i);

		hist->MuonE->Fill(MuonP_E);
		hist->MuonP->Fill(MuonP_P3);
		hist->PionE->Fill(PionM_E);
		hist->PionP->Fill(PionM_P3);
		hist->Gamma1E->Fill(Gamma1_E);
		hist->Gamma1P->Fill(Gamma1_P3);
		hist->Gamma2E->Fill(Gamma2_E);
		hist->Gamma2P->Fill(Gamma2_P3);
		hist->EtaM->Fill(Eta_M);
		hist->EtaP->Fill(Eta_P3);
		hist->EtaE->Fill(Eta_E);
		// cout << "enter i = " << i << endl;
		// cout << "MuonP_E = " << MuonP_E << endl;
		// cout << "MuonP_P3 = " << MuonP_P3 << endl;
	}

}
