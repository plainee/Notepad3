// Scintilla source code edit control
/** @file Lexilla.cxx
 ** Lexer infrastructure.
 ** Provides entry points to shared library.
 **/
// Copyright 2019 by Neil Hodgson <neilh@scintilla.org>
// The License.txt file describes the conditions under which this software may be distributed.

#include <cstring>
#include <vector>

#if _WIN32

#ifdef DLL_EXPORT
#define EXPORT_FUNCTION __declspec(dllexport)
#else
#define EXPORT_FUNCTION
#endif // DLL_EXPORT

#define CALLING_CONVENTION __stdcall

#else

#define EXPORT_FUNCTION __attribute__((visibility("default")))
#define CALLING_CONVENTION

#endif

#include "ILexer.h"

#include "LexerModule.h"
#include "CatalogueModules.h"

using namespace Scintilla;

//extern LexerModule lmA68k;
//extern LexerModule lmAbaqus;
//extern LexerModule lmAda;
//extern LexerModule lmAPDL;
//extern LexerModule lmAs;
 extern LexerModule lmAsm;
//extern LexerModule lmAsn1;
//extern LexerModule lmASY;
 extern LexerModule lmAU3;
//extern LexerModule lmAVE;
 extern LexerModule lmAVS;
//extern LexerModule lmBaan;
 extern LexerModule lmBash;
 extern LexerModule lmBatch;
//extern LexerModule lmBibTeX;
//extern LexerModule lmBlitzBasic;
//extern LexerModule lmBullant;
//extern LexerModule lmCaml;
//extern LexerModule lmCIL;
//extern LexerModule lmClw;
//extern LexerModule lmClwNoCase;
 extern LexerModule lmCmake;
//extern LexerModule lmCOBOL;
 extern LexerModule lmCoffeeScript;
 extern LexerModule lmConf;
 extern LexerModule lmCPP;
 extern LexerModule lmCPPNoCase;
//extern LexerModule lmCsound;
 extern LexerModule lmCss;
 extern LexerModule lmD;
//extern LexerModule lmDataflex;
 extern LexerModule lmDiff;
//extern LexerModule lmDMAP;
//extern LexerModule lmDMIS;
//extern LexerModule lmECL;
//extern LexerModule lmEDIFACT;
//extern LexerModule lmEiffel;
//extern LexerModule lmEiffelkw;
//extern LexerModule lmErlang;
//extern LexerModule lmErrorList;
//extern LexerModule lmESCRIPT;
//extern LexerModule lmF77;
//extern LexerModule lmFlagShip;
//extern LexerModule lmForth;
//extern LexerModule lmFortran;
//extern LexerModule lmFreeBasic;
//extern LexerModule lmGAP;
//extern LexerModule lmGui4Cli;
//extern LexerModule lmHaskell;
//extern LexerModule lmHollywood;
 extern LexerModule lmHTML;
//extern LexerModule lmIHex;
//extern LexerModule lmIndent;
 extern LexerModule lmInno;
 extern LexerModule lmJSON;
//extern LexerModule lmKix;
//extern LexerModule lmKVIrc;
 extern LexerModule lmLatex;
//extern LexerModule lmLISP;
//extern LexerModule lmLiterateHaskell;
//extern LexerModule lmLot;
//extern LexerModule lmLout;
 extern LexerModule lmLua;
//extern LexerModule lmMagikSF;
 extern LexerModule lmMake;
 extern LexerModule lmMarkdown;
 extern LexerModule lmMatlab;
//extern LexerModule lmMaxima;
//extern LexerModule lmMETAPOST;
//extern LexerModule lmMMIXAL;
//extern LexerModule lmModula;
//extern LexerModule lmMSSQL;
//extern LexerModule lmMySQL;
 extern LexerModule lmNim;
//extern LexerModule lmNimrod;
//extern LexerModule lmNncrontab;
 extern LexerModule lmNsis;
 extern LexerModule lmNull;
//extern LexerModule lmOctave;
//extern LexerModule lmOpal;
//extern LexerModule lmOScript;
 extern LexerModule lmPascal;
//extern LexerModule lmPB;
 extern LexerModule lmPerl;
//extern LexerModule lmPHPSCRIPT;
//extern LexerModule lmPLM;
//extern LexerModule lmPO;
//extern LexerModule lmPOV;
//extern LexerModule lmPowerPro;
 extern LexerModule lmPowerShell;
//extern LexerModule lmProgress;
 extern LexerModule lmProps;
//extern LexerModule lmPS;
//extern LexerModule lmPureBasic;
 extern LexerModule lmPython;
 extern LexerModule lmR;
//extern LexerModule lmRaku;
//extern LexerModule lmREBOL;
 extern LexerModule lmRegistry;
 extern LexerModule lmRuby;
 extern LexerModule lmRust;
//extern LexerModule lmSAS;
//extern LexerModule lmScriptol;
//extern LexerModule lmSmalltalk;
//extern LexerModule lmSML;
//extern LexerModule lmSorc;
//extern LexerModule lmSpecman;
//extern LexerModule lmSpice;
 extern LexerModule lmSQL;
//extern LexerModule lmSrec;
//extern LexerModule lmStata;
//extern LexerModule lmSTTXT;
//extern LexerModule lmTACL;
//extern LexerModule lmTADS3;
//extern LexerModule lmTAL;
 extern LexerModule lmTCL;
//extern LexerModule lmTCMD;
//extern LexerModule lmTEHex;
//extern LexerModule lmTeX;
//extern LexerModule lmTxt2tags;
 extern LexerModule lmVB;
 extern LexerModule lmVBScript;
//extern LexerModule lmVerilog;
 extern LexerModule lmVHDL;
//extern LexerModule lmVisualProlog;
//extern LexerModule lmX12;
 extern LexerModule lmXML;
 extern LexerModule lmYAML;

// --- custom lexers ---

 extern LexerModule lmAHKL;
 extern LexerModule lmCSV;
 extern LexerModule lmTOML;


namespace {

CatalogueModules catalogueLexilla;

void AddEachLexer() {

	if (catalogueLexilla.Count() > 0) {
		return;
	}

	//catalogueLexilla.AddLexerModule(&lmA68k);
  //catalogueLexilla.AddLexerModule(&lmAbaqus);
  //catalogueLexilla.AddLexerModule(&lmAda);
  //catalogueLexilla.AddLexerModule(&lmAPDL);
 // catalogueLexilla.AddLexerModule(&lmAs);
	catalogueLexilla.AddLexerModule(&lmAsm);
  //catalogueLexilla.AddLexerModule(&lmAsn1);
  //catalogueLexilla.AddLexerModule(&lmASY);
	catalogueLexilla.AddLexerModule(&lmAU3);
  //catalogueLexilla.AddLexerModule(&lmAVE);
	catalogueLexilla.AddLexerModule(&lmAVS);
  //catalogueLexilla.AddLexerModule(&lmBaan);
	catalogueLexilla.AddLexerModule(&lmBash);
	catalogueLexilla.AddLexerModule(&lmBatch);
  //catalogueLexilla.AddLexerModule(&lmBibTeX);
  //catalogueLexilla.AddLexerModule(&lmBlitzBasic);
  //catalogueLexilla.AddLexerModule(&lmBullant);
  //catalogueLexilla.AddLexerModule(&lmCaml);
  //catalogueLexilla.AddLexerModule(&lmCIL);
  //catalogueLexilla.AddLexerModule(&lmClw);
  //catalogueLexilla.AddLexerModule(&lmClwNoCase);
	catalogueLexilla.AddLexerModule(&lmCmake);
  //catalogueLexilla.AddLexerModule(&lmCOBOL);
	catalogueLexilla.AddLexerModule(&lmCoffeeScript);
	catalogueLexilla.AddLexerModule(&lmConf);
	catalogueLexilla.AddLexerModule(&lmCPP);
	catalogueLexilla.AddLexerModule(&lmCPPNoCase);
  //catalogueLexilla.AddLexerModule(&lmCsound);
	catalogueLexilla.AddLexerModule(&lmCss);
	catalogueLexilla.AddLexerModule(&lmD);
  //catalogueLexilla.AddLexerModule(&lmDataflex);
	catalogueLexilla.AddLexerModule(&lmDiff);
  //catalogueLexilla.AddLexerModule(&lmDMAP);
  //catalogueLexilla.AddLexerModule(&lmDMIS);
  //catalogueLexilla.AddLexerModule(&lmECL);
  //catalogueLexilla.AddLexerModule(&lmEDIFACT);
  //catalogueLexilla.AddLexerModule(&lmEiffel);
  //catalogueLexilla.AddLexerModule(&lmEiffelkw);
	//catalogueLexilla.AddLexerModule(&lmErlang);
	//catalogueLexilla.AddLexerModule(&lmErrorList);
	//catalogueLexilla.AddLexerModule(&lmESCRIPT);
	//catalogueLexilla.AddLexerModule(&lmF77);
	//catalogueLexilla.AddLexerModule(&lmFlagShip);
	//catalogueLexilla.AddLexerModule(&lmForth);
	//catalogueLexilla.AddLexerModule(&lmFortran);
	//catalogueLexilla.AddLexerModule(&lmFreeBasic);
	//catalogueLexilla.AddLexerModule(&lmGAP);
	//catalogueLexilla.AddLexerModule(&lmGui4Cli);
	//catalogueLexilla.AddLexerModule(&lmHaskell);
	//catalogueLexilla.AddLexerModule(&lmHollywood);
	catalogueLexilla.AddLexerModule(&lmHTML);
  //catalogueLexilla.AddLexerModule(&lmIHex);
  //catalogueLexilla.AddLexerModule(&lmIndent);
	catalogueLexilla.AddLexerModule(&lmInno);
	catalogueLexilla.AddLexerModule(&lmJSON);
  //catalogueLexilla.AddLexerModule(&lmKix);
  //catalogueLexilla.AddLexerModule(&lmKVIrc);
	catalogueLexilla.AddLexerModule(&lmLatex);
	//catalogueLexilla.AddLexerModule(&lmLISP);
	//catalogueLexilla.AddLexerModule(&lmLiterateHaskell);
	//catalogueLexilla.AddLexerModule(&lmLot);
	//catalogueLexilla.AddLexerModule(&lmLout);
	catalogueLexilla.AddLexerModule(&lmLua);
  //catalogueLexilla.AddLexerModule(&lmMagikSF);
	catalogueLexilla.AddLexerModule(&lmMake);
	catalogueLexilla.AddLexerModule(&lmMarkdown);
	catalogueLexilla.AddLexerModule(&lmMatlab);
	//catalogueLexilla.AddLexerModule(&lmMaxima);
	//catalogueLexilla.AddLexerModule(&lmMETAPOST);
	//catalogueLexilla.AddLexerModule(&lmMMIXAL);
	//catalogueLexilla.AddLexerModule(&lmModula);
	//catalogueLexilla.AddLexerModule(&lmMSSQL);
	//catalogueLexilla.AddLexerModule(&lmMySQL);
	catalogueLexilla.AddLexerModule(&lmNim);
	//catalogueLexilla.AddLexerModule(&lmNimrod);
	//catalogueLexilla.AddLexerModule(&lmNncrontab);
	catalogueLexilla.AddLexerModule(&lmNsis);
	catalogueLexilla.AddLexerModule(&lmNull);
	//catalogueLexilla.AddLexerModule(&lmOctave);
	//catalogueLexilla.AddLexerModule(&lmOpal);
	//catalogueLexilla.AddLexerModule(&lmOScript);
	catalogueLexilla.AddLexerModule(&lmPascal);
  //catalogueLexilla.AddLexerModule(&lmPB);
	catalogueLexilla.AddLexerModule(&lmPerl);
	//catalogueLexilla.AddLexerModule(&lmPHPSCRIPT);
	//catalogueLexilla.AddLexerModule(&lmPLM);
	//catalogueLexilla.AddLexerModule(&lmPO);
	//catalogueLexilla.AddLexerModule(&lmPOV);
	//catalogueLexilla.AddLexerModule(&lmPowerPro);
	catalogueLexilla.AddLexerModule(&lmPowerShell);
  //catalogueLexilla.AddLexerModule(&lmProgress);
	catalogueLexilla.AddLexerModule(&lmProps);
  //catalogueLexilla.AddLexerModule(&lmPS);
  //catalogueLexilla.AddLexerModule(&lmPureBasic);
	catalogueLexilla.AddLexerModule(&lmPython);
	catalogueLexilla.AddLexerModule(&lmR);
	//catalogueLexilla.AddLexerModule(&lmRaku);
	//catalogueLexilla.AddLexerModule(&lmREBOL);
	catalogueLexilla.AddLexerModule(&lmRegistry);
	catalogueLexilla.AddLexerModule(&lmRuby);
	catalogueLexilla.AddLexerModule(&lmRust);
	//catalogueLexilla.AddLexerModule(&lmSAS);
	//catalogueLexilla.AddLexerModule(&lmScriptol);
	//catalogueLexilla.AddLexerModule(&lmSmalltalk);
	//catalogueLexilla.AddLexerModule(&lmSML);
	//catalogueLexilla.AddLexerModule(&lmSorc);
	//catalogueLexilla.AddLexerModule(&lmSpecman);
	//catalogueLexilla.AddLexerModule(&lmSpice);
	catalogueLexilla.AddLexerModule(&lmSQL);
	//catalogueLexilla.AddLexerModule(&lmSrec);
	//catalogueLexilla.AddLexerModule(&lmStata);
	//catalogueLexilla.AddLexerModule(&lmSTTXT);
	//catalogueLexilla.AddLexerModule(&lmTACL);
	//catalogueLexilla.AddLexerModule(&lmTADS3);
	//catalogueLexilla.AddLexerModule(&lmTAL);
	catalogueLexilla.AddLexerModule(&lmTCL);
	//catalogueLexilla.AddLexerModule(&lmTCMD);
	//catalogueLexilla.AddLexerModule(&lmTEHex);
	//catalogueLexilla.AddLexerModule(&lmTeX);
	//catalogueLexilla.AddLexerModule(&lmTxt2tags);
	catalogueLexilla.AddLexerModule(&lmVB);
	catalogueLexilla.AddLexerModule(&lmVBScript);
	//catalogueLexilla.AddLexerModule(&lmVerilog);
	catalogueLexilla.AddLexerModule(&lmVHDL);
	//catalogueLexilla.AddLexerModule(&lmVisualProlog);
	//catalogueLexilla.AddLexerModule(&lmX12);
	catalogueLexilla.AddLexerModule(&lmXML);
	catalogueLexilla.AddLexerModule(&lmYAML);

  // --- custom lexers ---

  catalogueLexilla.AddLexerModule(&lmAHKL);
  catalogueLexilla.AddLexerModule(&lmCSV);
  catalogueLexilla.AddLexerModule(&lmTOML);

}

}

extern "C" {

EXPORT_FUNCTION int CALLING_CONVENTION GetLexerCount() {
	AddEachLexer();
	return catalogueLexilla.Count();
}

EXPORT_FUNCTION void CALLING_CONVENTION GetLexerName(unsigned int index, char* name, int buflength) {
	AddEachLexer();
	*name = 0;
	const char *lexerName = catalogueLexilla.Name(index);
	if (static_cast<size_t>(buflength) > strlen(lexerName)) {
		strcpy(name, lexerName);
	}
}

EXPORT_FUNCTION LexerFactoryFunction CALLING_CONVENTION GetLexerFactory(unsigned int index) {
	AddEachLexer();
	return catalogueLexilla.Factory(index);
}


EXPORT_FUNCTION void /*ILexer5*/* CALLING_CONVENTION CreateLexerByID(const int language) {
  AddEachLexer();
  for (unsigned int i = 0; i < catalogueLexilla.Count(); i++) {
    const int lngID = catalogueLexilla.LngID(i);
    if (language == lngID) {
      return (void*)catalogueLexilla.Create(i);
    }
  }
  return (void*)nullptr;
}

EXPORT_FUNCTION void /*ILexer5*/ * CALLING_CONVENTION CreateLexerByName(const char* name) {
	AddEachLexer();
	for (unsigned int i = 0; i < catalogueLexilla.Count(); i++) {
		const char *lexerName = catalogueLexilla.Name(i);
		if (0 == strcmp(lexerName, name)) {
			return (void*)catalogueLexilla.Create(i);
		}
	}
	return (void*)nullptr;
}

} // extern "C"
