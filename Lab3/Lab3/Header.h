#pragma once

//function definitions
int messageFunct(const char * programName);

//enum definitions
enum inputs { programName, inputFile, commandLineArguments };

enum results { success, userQuit, drawResult, commandLineFail, unableToOpenFileFailure, cannotExtractDemensions, inputFileWrongSize, wrongBoardDimensions, cannotReadLine, badColor, unableToExtract, cantReadPieces }; //specify each failure

  