#pragma once

//function definitions
int messageFunct(const char * programName);

int fileFailure();

//enum definitions
enum inputs { programName, inputFile, commandLineArguments };

enum results { success, userQuit, invalidSquare, commandLineFail, unableToOpenFileFailure, cannotExtractDemensions, inputFileWrongSize, wrongBoardDimensions, cannotReadLine, badColor, unableToExtract, cantReadPieces }; //specify each failure

