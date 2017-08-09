// Copyright CERN and copyright holders of ALICE O2. This software is
// distributed under the terms of the GNU General Public License v3 (GPL
// Version 3), copied verbatim in the file "COPYING".
//
// See https://alice-o2.web.cern.ch/ for full licensing information.
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

#ifndef ALICEO2_TOF_GEO_H
#define ALICEO2_TOF_GEO_H

#include "Rtypes.h"

namespace o2
{
namespace tof
{
/// \class Geo
/// \brief TOF geo parameters (only statics)
class Geo
{
 public:
  // From AliTOFGeometry
  static Float_t GetAngles(Int_t iplate, Int_t istrip) { return ANGLES[iplate][istrip]; }
  static Float_t GetHeights(Int_t iplate, Int_t istrip) { return HEIGHTS[iplate][istrip]; }
  static Float_t GetDistances(Int_t iplate, Int_t istrip) { return DISTANCES[iplate][istrip]; }
  static constexpr Int_t NPADX = 48;
  static constexpr Int_t NPADZ = 2;
  static constexpr Int_t NSTRIPA = 15;
  static constexpr Int_t NSTRIPB = 19;
  static constexpr Int_t NSTRIPC = 19;
  static constexpr Int_t NMAXNSTRIP = 20;
  static constexpr Int_t NSTRIPXSECTOR = NSTRIPA + 2 * NSTRIPB + 2 * NSTRIPC;

  static constexpr Int_t NSECTORS = 18;
  static constexpr Int_t NPLATES = 5;

  static constexpr Float_t MAXHZTOF = 370.6;      // Max half z-size of TOF (cm)
  static constexpr Float_t ZLENA = MAXHZTOF * 2.; // length (cm) of the A module
  static constexpr Float_t ZLENB = 146.5;         // length (cm) of the B module
  static constexpr Float_t ZLENC = 170.45;        // length (cm) of the C module

  static constexpr Float_t XTOF = 372.00; // Inner radius of the TOF for Reconstruction (cm)
  static constexpr Float_t RMIN = 371;
  static constexpr Float_t RMAX = 400.05;

  static constexpr Float_t XPAD = 2.5;
  static constexpr Float_t ZPAD = 3.5;
  static constexpr Float_t STRIPLENGTH = 122;

  static constexpr Float_t SIGMAFORTAIL1 = 2.;   // Sig1 for simulation of TDC tails
  static constexpr Float_t SIGMAFORTAIL12 = 0.5; // Sig2 for simulation of TDC tails

  static constexpr Float_t PHISEC = 20; // sector Phi width (deg)

  static constexpr Float_t TDCBIN = 24.4;                    // time-of-flight bin width [ps]
  static constexpr Float_t TOTBIN = 48.8;                    // time-over-threshold bin width [ps]
  static constexpr Float_t BUNCHCROSSINGBIN = TDCBIN * 1024; // bunch-crossing bin width [ps]

  static constexpr Float_t SLEWTOTMIN = 10.; // min TOT for slewing correction [ns]
  static constexpr Float_t SLEWTOTMAX = 16.; // max TOT for slewing correction [ns]

  static constexpr Float_t DEADTIME = 25E+03;              // Single channel dead time (ps)
  static constexpr Float_t MATCHINGWINDOW = TDCBIN * 8192; // Matching window  (ps) 2^13=8192

  static constexpr Float_t ANGLES[NPLATES][NMAXNSTRIP] = { // Strip Tilt Angles
    { 43.99, 43.20, 42.40, 41.59, 40.77, 39.94, 39.11, 38.25, 37.40, 36.53,
      35.65, 34.76, 33.87, 32.96, 32.05, 31.13, 30.19, 29.24, 12.33, 0.00 },
    { 27.26, 26.28, 25.30, 24.31, 23.31, 22.31, 21.30, 20.29, 19.26, 18.24,
      17.20, 16.16, 15.11, 14.05, 13.00, 11.93, 10.87, 9.80,  8.74,  0.00 },
    { 0.00,  6.30,  5.31,  4.25,  3.19, 2.12, 1.06, 0.00, -1.06, -2.12,
      -3.19, -4.25, -5.31, -6.30, 0.00, 0.00, 0.00, 0.00, 0.00,  0.00 },
    { -8.74,  -9.80,  -10.87, -11.93, -13.00, -14.05, -15.11, -16.16, -17.20, -18.24,
      -19.26, -20.29, -21.30, -22.31, -23.31, -24.31, -25.30, -26.28, -27.26, 0.00 },
    { -12.33, -29.24, -30.19, -31.13, -32.05, -32.96, -33.87, -34.76, -35.65, -36.53,
      -37.40, -38.25, -39.11, -39.94, -40.77, -41.59, -42.40, -43.20, -43.99, 0.00 }
  };

  static constexpr Float_t HEIGHTS[NPLATES][NMAXNSTRIP] = {
    { -8.405, -7.725, -8.405, -7.765, -8.285, -7.745, -7.865, -7.905, -7.895, -7.885,
      -7.705, -7.395, -7.525, -7.645, -7.835, -7.965, -8.365, -9.385, -3.255, 0.000 },
    { -7.905, -8.235, -8.605,  -9.045, -10.205, -3.975,  -5.915, -7.765, -10.205, -3.635,
      -5.885, -8.005, -10.505, -4.395, -7.325,  -10.235, -4.655, -7.495, -10.515, 0.000 },
    { -2.705, -10.645, -5.165, -10.095, -4.995, -10.085, -4.835, -10.385, -4.835, -10.085,
      -4.995, -10.095, -5.165, -10.645, -2.705, 0.000,   0.000,  0.000,   0.000,  0.000 },
    { -10.515, -7.495, -4.655, -10.235, -7.325,  -4.395, -10.505, -8.005, -5.885, -3.635,
      -10.205, -7.765, -5.915, -3.975,  -10.205, -9.045, -8.605,  -8.235, -7.905, 0.000 },
    { -3.255, -9.385, -8.365, -7.965, -7.835, -7.645, -7.525, -7.395, -7.705, -7.885,
      -7.895, -7.905, -7.865, -7.745, -8.285, -7.765, -8.405, -7.725, -8.405, 0.000 }
  };

  static constexpr Float_t DISTANCES[NPLATES][NMAXNSTRIP] = {
    { 364.14, 354.88, 344.49, 335.31, 325.44, 316.51, 307.11, 297.91, 288.84, 279.89,
      271.20, 262.62, 253.84, 245.20, 236.56, 228.06, 219.46, 210.63, 206.09, 0.00 },
    { 194.57, 186.38, 178.25, 170.13, 161.78, 156.62, 148.10, 139.72, 131.23, 125.87,
      117.61, 109.44, 101.29, 95.46,  87.36,  79.37,  73.17,  65.33,  57.71,  0.00 },
    { 49.28,  41.35,  35.37,  27.91,  21.20,  13.94, 7.06, 0.00, -7.06, -13.94,
      -21.20, -27.91, -35.37, -41.35, -49.28, 0.00,  0.00, 0.00, 0.00,  0.00 },
    { -57.71,  -65.33,  -73.17,  -79.37,  -87.36,  -95.46,  -101.29, -109.44, -117.61, -125.87,
      -131.23, -139.72, -148.10, -156.62, -161.78, -170.13, -178.25, -186.38, -194.57, 0.00 },
    { -206.09, -210.63, -219.46, -228.06, -236.56, -245.20, -253.84, -262.62, -271.20, -279.89,
      -288.84, -297.91, -307.11, -316.51, -325.44, -335.31, -344.49, -354.88, -364.14, 0.00 }
  };

  // from AliTOFv6T0 class
  static constexpr Bool_t FEAWITHMASKS[18] =
    // TOF sectors with Nino masks: 0, 8, 9, 10, 16
    { kTRUE, kFALSE, kFALSE, kFALSE, kFALSE, kFALSE, kFALSE, kFALSE, kTRUE,
      kTRUE, kTRUE,  kFALSE, kFALSE, kFALSE, kFALSE, kFALSE, kTRUE,  kFALSE };
  ; // Selecting TOF sectors containing FEA cooling masks

  static constexpr Float_t MODULEWALLTHICKNESS = 0.33;  // wall thickness (cm)
  static constexpr Float_t INTERCENTRMODBORDER1 = 49.5; // 1st distance of
  // border between
  // central and
  // intermediate
  // modules respect to
  // the central module
  // centre (cm)
  static constexpr Float_t INTERCENTRMODBORDER2 = 57.5; // 2nd distance of
  // border between the
  // central and
  // intermediate
  // modules respect to
  // the central module
  // centre (cm)
  static constexpr Float_t EXTERINTERMODBORDER1 = 196.0; // 1st distance of
  // border between the
  // intermediate and
  // external modules
  // respect to the
  // central module
  // centre (cm)
  static constexpr Float_t EXTERINTERMODBORDER2 = 203.5; // 2nd distance of
  // border between the
  // intermediate and
  // external
  // modules respect to
  // the central module
  // centre (cm)
  static constexpr Float_t LENGTHINCEMODBORDERU = 5.0; // height of upper border
  // between the central
  // and intermediate
  // modules (cm)
  static constexpr Float_t LENGTHINCEMODBORDERD = 7.0; // height of lower border
  // between the central
  // and intermediate
  // modules (cm)
  static constexpr Float_t LENGTHEXINMODBORDER = 5.0; // height of border
  // between the
  // intermediate and
  // external modules
  // (cm)
  static constexpr Float_t MODULECOVERTHICKNESS = 2.0; // thickness of cover
  // modules zone (cm)
  static constexpr Float_t FEAWIDTH1 = 19.0;      // mother volume width of each of
                                                  // two external FEA in a
                                                  // supermodule (cm)
  static constexpr Float_t FEAWIDTH2 = 39.5;      // mother volume width of two
                                                  // internal FEA in a supermodule
                                                  // (cm)
  static constexpr Float_t SAWTHICKNESS = 1.0;    // services alluminium wall
                                                  // thickness (cm)
  static constexpr Float_t CBLW = 13.5;           // cables&tubes block width (cm)
  static constexpr Float_t CBLH1 = 2.0;           // min. height of cables&tubes block
                                                  // (cm)
  static constexpr Float_t CBLH2 = 12.3;          // max. height of cables&tubes block
                                                  // (cm)
  static constexpr Float_t BETWEENLANDMASK = 0.1; // distance between the L
  // element and the Nino
  // mask (cm)
  static constexpr Float_t AL1PARAMETERS[3] = { static_cast<Float_t>(FEAWIDTH1 * 0.5), 0.4, 0.2 }; // (cm)
  static constexpr Float_t AL2PARAMETERS[3] = { 7.25, 0.75, 0.25 };                                // (cm)
  static constexpr Float_t AL3PARAMETERS[3] = { 3., 4., 0.1 };                                     // (cm)
  static constexpr Float_t ROOF1PARAMETERS[3] = { AL1PARAMETERS[0], AL1PARAMETERS[2], 1.45 };      // (cm)
  static constexpr Float_t ROOF2PARAMETERS[3] = { AL3PARAMETERS[0], 0.1, 1.15 };                   // (cm)
  static constexpr Float_t FEAPARAMETERS[3] = { static_cast<Float_t>(FEAWIDTH1 * 0.5), 5.6, 0.1 }; // (cm)
  static constexpr Float_t BAR[3] = { 8.575, 0.6, 0.25 };                                          // (cm)
  static constexpr Float_t BAR1[3] = { BAR[0], BAR[1], 0.1 };                                      // (cm)
  static constexpr Float_t BAR2[3] = { BAR[0], 0.1, static_cast<Float_t>(BAR[1] - 2. * BAR1[2]) }; // (cm)
  static constexpr Float_t BARS[3] = { 2., BAR[1], BAR[2] };                                       // (cm)
  static constexpr Float_t BARS1[3] = { BARS[0], BAR1[1], BAR1[2] };                               // (cm)
  static constexpr Float_t BARS2[3] = { BARS[0], BAR2[1], BAR2[2] };                               // (cm)

 private:
  ClassDefNV(Geo, 1);
};
}
}

#endif