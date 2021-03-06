#ifndef HcalPedestalWidthsValidation_H
#define HcalPedestalWidthsValidation_H

#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/HcalDetId/interface/HcalGenericDetId.h"
#include "DataFormats/HcalDetId/interface/HcalElectronicsId.h"
#include "DataFormats/HcalDetId/interface/HcalDetId.h"
#include "DataFormats/HcalDigi/interface/HcalDigiCollections.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "CondFormats/HcalObjects/interface/HcalPedestals.h"
#include "CondFormats/HcalObjects/interface/HcalPedestalWidths.h"
#include "CondFormats/HcalObjects/interface/HcalQIECoder.h"
#include "CondFormats/HcalObjects/interface/HcalQIEData.h"
#include "CondFormats/HcalObjects/interface/HcalQIEShape.h"
#include "CondFormats/HcalObjects/interface/HcalElectronicsMap.h"
#include "CondFormats/HcalObjects/interface/AllObjects.h"

#include "CalibFormats/HcalObjects/interface/HcalDbRecord.h"
#include "CalibFormats/HcalObjects/interface/HcalDbService.h"
#include "CalibFormats/HcalObjects/interface/HcalCalibrations.h"
#include "CalibFormats/HcalObjects/interface/HcalCalibrationWidths.h"

#include "CondTools/Hcal/interface/HcalDbOnline.h"

#include "CalibCalorimetry/HcalAlgos/interface/HcalDbASCIIIO.h"
#include "TBDataFormats/HcalTBObjects/interface/HcalTBTriggerData.h"

#include "TFile.h"
#include "TProfile.h"
#include "TH1.h"
#include "TH2.h"
#include <math.h>
#include <iostream>
#include <map>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

namespace edm {
  class ParameterSet;
  class Event;
  class EventSetup;
}

   struct NewPedBunchVal
   {
      HcalDetId detid;
      bool usedflag;
      float cap[4];
      float capfc[4];
      float sig[4][4];
      float sigfc[4][4];
      float prod[4][4];
      float prodfc[4][4];
      int num[4][4];
      TH1F * hist[4];
      TH2F * covarhistADC;
      TH2F * covarhistfC;
   };

class HcalPedestalWidthsValidation : public edm::EDAnalyzer
{
   public:
   //Constructor
   HcalPedestalWidthsValidation(const edm::ParameterSet& ps);
   //Destructor
   virtual ~HcalPedestalWidthsValidation();
   //Analysis
   void analyze(const edm::Event & event, const edm::EventSetup& eventSetup);

   private:
   //Container for data, 1 per channel
   std::vector<NewPedBunchVal> BunchVales;
   int runnum;
   int firstTS;
   int lastTS;
   std::string ROOTfilename;
   std::string pedsADCfilename;
   std::string pedsfCfilename;
   std::string widthsADCfilename;
   std::string widthsfCfilename;

   TH1F *HBMeans;
   TH1F *HBWidths;
   TH1F *HEMeans;
   TH1F *HEWidths;
   TH1F *HFMeans;
   TH1F *HFWidths;
   TH1F *HOMeans;
   TH1F *HOWidths;

   TFile *theFile;
   bool firsttime;
   HcalPedestals* rawPedsItem;
   HcalPedestalWidths* rawWidthsItem;
   HcalPedestals* rawPedsItemfc;
   HcalPedestalWidths* rawWidthsItemfc;
};
#endif

