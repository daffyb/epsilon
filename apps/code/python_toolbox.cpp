#include "python_toolbox.h"
#include "../shared/toolbox_helpers.h"
#include <assert.h>
extern "C" {
#include <string.h>
#include <ctype.h>
}

namespace Code {

const ToolboxMessageTree forLoopChildren[] = {
  ToolboxMessageTree::Leaf(I18n::Message::ForInRange1ArgLoopWithArg, I18n::Message::Default, false, I18n::Message::ForInRange1ArgLoop),
  ToolboxMessageTree::Leaf(I18n::Message::ForInRange2ArgsLoopWithArg, I18n::Message::Default, false, I18n::Message::ForInRange2ArgsLoop),
  ToolboxMessageTree::Leaf(I18n::Message::ForInRange3ArgsLoopWithArg, I18n::Message::Default, false, I18n::Message::ForInRange3ArgsLoop),
  ToolboxMessageTree::Leaf(I18n::Message::ForInListLoopWithArg, I18n::Message::Default, false, I18n::Message::ForInListLoop)
};

const ToolboxMessageTree ifStatementChildren[] = {
  ToolboxMessageTree::Leaf(I18n::Message::IfElseStatementWithArg, I18n::Message::Default, false, I18n::Message::IfElseStatement),
  ToolboxMessageTree::Leaf(I18n::Message::IfThenStatementWithArg, I18n::Message::Default, false, I18n::Message::IfThenStatement),
  ToolboxMessageTree::Leaf(I18n::Message::IfElifElseStatementWithArg, I18n::Message::Default, false, I18n::Message::IfElifElseStatement),
  ToolboxMessageTree::Leaf(I18n::Message::IfAndIfElseStatementWithArg, I18n::Message::Default, false, I18n::Message::IfAndIfElseStatement),
  ToolboxMessageTree::Leaf(I18n::Message::IfOrIfElseStatementWithArg, I18n::Message::Default, false, I18n::Message::IfOrIfElseStatement)
};

const ToolboxMessageTree whileLoopChildren[] = {
  ToolboxMessageTree::Leaf(I18n::Message::WhileLoopWithArg, I18n::Message::Default, false, I18n::Message::WhileLoop)
};

const ToolboxMessageTree conditionsChildren[] = {
  ToolboxMessageTree::Leaf(I18n::Message::EqualityConditionWithArg, I18n::Message::Default, false, I18n::Message::EqualityCondition),
  ToolboxMessageTree::Leaf(I18n::Message::NonEqualityConditionWithArg, I18n::Message::Default, false, I18n::Message::NonEqualityCondition),
  ToolboxMessageTree::Leaf(I18n::Message::SuperiorStrictConditionWithArg, I18n::Message::Default, false, I18n::Message::SuperiorStrictCondition),
  ToolboxMessageTree::Leaf(I18n::Message::InferiorStrictConditionWithArg, I18n::Message::Default, false, I18n::Message::InferiorStrictCondition),
  ToolboxMessageTree::Leaf(I18n::Message::SuperiorConditionWithArg, I18n::Message::Default, false, I18n::Message::SuperiorCondition),
  ToolboxMessageTree::Leaf(I18n::Message::InferiorConditionWithArg, I18n::Message::Default, false, I18n::Message::InferiorCondition),
  ToolboxMessageTree::Leaf(I18n::Message::ConditionAnd, I18n::Message::Default, false),
  ToolboxMessageTree::Leaf(I18n::Message::ConditionOr, I18n::Message::Default, false),
  ToolboxMessageTree::Leaf(I18n::Message::ConditionNot, I18n::Message::Default, false)
};

const ToolboxMessageTree loopsAndTestsChildren[] = {
  ToolboxMessageTree::Node(I18n::Message::ForLoopMenu, forLoopChildren),
  ToolboxMessageTree::Node(I18n::Message::IfStatementMenu, ifStatementChildren),
  ToolboxMessageTree::Node(I18n::Message::WhileLoopMenu, whileLoopChildren),
  ToolboxMessageTree::Node(I18n::Message::ConditionsMenu, conditionsChildren)
};

const ToolboxMessageTree MathModuleChildren[] = {
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportMath, I18n::Message::PythonImportMath, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportFromMath, I18n::Message::PythonImportFromMath, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandMathFunction, I18n::Message::PythonMathFunction, false, I18n::Message::PythonCommandMathFunctionWithoutArg),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandConstantE, I18n::Message::PythonConstantE, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandConstantPi, I18n::Message::PythonConstantPi, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandSqrt, I18n::Message::PythonSqrt),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandPower, I18n::Message::PythonPower),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandExp, I18n::Message::PythonExp),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandExpm1, I18n::Message::PythonExpm1),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandLog, I18n::Message::PythonLog),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandLog2, I18n::Message::PythonLog2),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandLog10, I18n::Message::PythonLog10),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandCosh, I18n::Message::PythonCosh),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandSinh, I18n::Message::PythonSinh),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandTanh, I18n::Message::PythonTanh),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandAcosh, I18n::Message::PythonAcosh),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandAsinh, I18n::Message::PythonAsinh),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandAtanh, I18n::Message::PythonAtanh),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandCos, I18n::Message::PythonCos),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandSin, I18n::Message::PythonSin),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandTan, I18n::Message::PythonTan),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandAcos, I18n::Message::PythonAcos),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandAsin, I18n::Message::PythonAsin),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandAtan, I18n::Message::PythonAtan),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandAtan2, I18n::Message::PythonAtan2),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandCeil, I18n::Message::PythonCeil),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandCopySign, I18n::Message::PythonCopySign),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandFabs, I18n::Message::PythonFabs),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandFloor, I18n::Message::PythonFloor),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandFmod, I18n::Message::PythonFmod),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandFrExp, I18n::Message::PythonFrExp),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandLdexp, I18n::Message::PythonLdexp),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandModf, I18n::Message::PythonModf),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandIsFinite, I18n::Message::PythonIsFinite),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandIsInfinite, I18n::Message::PythonIsInfinite),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandIsNaN, I18n::Message::PythonIsNaN),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandTrunc, I18n::Message::PythonTrunc),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandRadians, I18n::Message::PythonRadians),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandDegrees, I18n::Message::PythonDegrees),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandErf, I18n::Message::PythonErf),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandErfc, I18n::Message::PythonErfc),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandGamma, I18n::Message::PythonGamma),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandLgamma, I18n::Message::PythonLgamma)
};

const ToolboxMessageTree KandinskyModuleChildren[] = {
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportKandinsky, I18n::Message::PythonImportKandinsky, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportFromKandinsky, I18n::Message::PythonImportFromKandinsky, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandKandinskyFunction, I18n::Message::PythonKandinskyFunction, false, I18n::Message::PythonCommandKandinskyFunctionWithoutArg),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandGetPixel, I18n::Message::PythonGetPixel),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandSetPixel, I18n::Message::PythonSetPixel),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandColor, I18n::Message::PythonColor),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandDrawString, I18n::Message::PythonDrawString),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandFillRect, I18n::Message::PythonFillRect)
};

const ToolboxMessageTree RandomModuleChildren[] = {
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportRandom, I18n::Message::PythonImportRandom, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportFromRandom, I18n::Message::PythonImportFromRandom, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandRandomFunction, I18n::Message::PythonRandomFunction, false, I18n::Message::PythonCommandRandomFunctionWithoutArg),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandGetrandbits, I18n::Message::PythonGetrandbits),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandSeed, I18n::Message::PythonSeed),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandRandrange, I18n::Message::PythonRandrange),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandRandint, I18n::Message::PythonRandint),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandChoice, I18n::Message::PythonChoice),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandRandom, I18n::Message::PythonRandom, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandUniform, I18n::Message::PythonUniform)
};

const ToolboxMessageTree CMathModuleChildren[] = {
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportCmath, I18n::Message::PythonImportCmath, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportFromCmath, I18n::Message::PythonImportFromCmath, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandCmathFunction, I18n::Message::PythonCmathFunction, false, I18n::Message::PythonCommandCmathFunctionWithoutArg),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandConstantE, I18n::Message::PythonConstantE, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandConstantPi, I18n::Message::PythonConstantPi, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandPhase, I18n::Message::PythonPhase),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandPolar, I18n::Message::PythonPolar),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandRect, I18n::Message::PythonRect),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandExpComplex, I18n::Message::PythonExp),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandLogComplex, I18n::Message::PythonLog),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandSqrtComplex, I18n::Message::PythonSqrt),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandCosComplex, I18n::Message::PythonCos),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandSinComplex, I18n::Message::PythonSin)
};

const ToolboxMessageTree TurtleModuleChildren[] = {
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportTurtle, I18n::Message::PythonImportTurtle, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportFromTurtle, I18n::Message::PythonImportFromTurtle, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandTurtleFunction, I18n::Message::PythonTurtleFunction, false, I18n::Message::PythonCommandTurtleFunctionWithoutArg),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandForward, I18n::Message::PythonTurtleForward),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandBackward, I18n::Message::PythonTurtleBackward),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandRight, I18n::Message::PythonTurtleRight),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandLeft, I18n::Message::PythonTurtleLeft),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandGoto, I18n::Message::PythonTurtleGoto),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandSetheading, I18n::Message::PythonTurtleSetheading),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandCircle, I18n::Message::PythonTurtleCircle),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandSpeed, I18n::Message::PythonTurtleSpeed),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandPosition, I18n::Message::PythonTurtlePosition, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandHeading, I18n::Message::PythonTurtleHeading, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandPendown, I18n::Message::PythonTurtlePendown, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandPenup, I18n::Message::PythonTurtlePenup, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandPensize, I18n::Message::PythonTurtlePensize),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandIsdown, I18n::Message::PythonTurtleIsdown, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandReset, I18n::Message::PythonTurtleReset, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandShowturtle, I18n::Message::PythonTurtleShowturtle, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandHideturtle, I18n::Message::PythonTurtleHideturtle, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandColor, I18n::Message::PythonTurtleColor, false, I18n::Message::PythonTurtleCommandColorWithoutArg),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandBlue, I18n::Message::PythonTurtleBlue, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandRed, I18n::Message::PythonTurtleRed, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandGreen, I18n::Message::PythonTurtleGreen, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandYellow, I18n::Message::PythonTurtleYellow, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandBrown, I18n::Message::PythonTurtleBrown, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandBlack, I18n::Message::PythonTurtleBlack, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandWhite, I18n::Message::PythonTurtleWhite, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandPink, I18n::Message::PythonTurtlePink, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandOrange, I18n::Message::PythonTurtleOrange, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandPurple, I18n::Message::PythonTurtlePurple, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandGrey, I18n::Message::PythonTurtleGrey, false)
};

const ToolboxMessageTree modulesChildren[] = {
  ToolboxMessageTree::Node(I18n::Message::MathModule, MathModuleChildren),
  ToolboxMessageTree::Node(I18n::Message::CmathModule, CMathModuleChildren),
  ToolboxMessageTree::Node(I18n::Message::RandomModule, RandomModuleChildren),
  ToolboxMessageTree::Node(I18n::Message::TurtleModule, TurtleModuleChildren),
  ToolboxMessageTree::Node(I18n::Message::KandinskyModule, KandinskyModuleChildren)
};

const ToolboxMessageTree catalogChildren[] = {
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandPound, I18n::Message::PythonPound, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandPercent, I18n::Message::PythonPercent, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommand1J, I18n::Message::Python1J, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandLF, I18n::Message::PythonLF, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandTab, I18n::Message::PythonTab, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandAmpersand, I18n::Message::PythonAmpersand, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandSymbolExp, I18n::Message::PythonSymbolExp, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandVerticalBar, I18n::Message::PythonVerticalBar, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandSingleQuote, I18n::Message::PythonSingleQuote, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandAbs, I18n::Message::PythonAbs),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandAcos, I18n::Message::PythonAcos),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandAcosh, I18n::Message::PythonAcosh),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandAsin, I18n::Message::PythonAsin),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandAsinh, I18n::Message::PythonAsinh),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandAtan, I18n::Message::PythonAtan),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandAtan2, I18n::Message::PythonAtan2),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandAtanh, I18n::Message::PythonAtanh),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandBackward, I18n::Message::PythonTurtleBackward),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandBin, I18n::Message::PythonBin),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandBlack, I18n::Message::PythonTurtleBlack, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandBlue, I18n::Message::PythonTurtleBlue,  false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandBrown, I18n::Message::PythonTurtleBrown, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandCeil, I18n::Message::PythonCeil),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandChoice, I18n::Message::PythonChoice),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandCircle, I18n::Message::PythonTurtleCircle),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandCmathFunction, I18n::Message::PythonCmathFunction, false, I18n::Message::PythonCommandCmathFunctionWithoutArg),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandColor, I18n::Message::PythonColor),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandComplex, I18n::Message::PythonComplex),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandCopySign, I18n::Message::PythonCopySign),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandCos, I18n::Message::PythonCos),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandCosh, I18n::Message::PythonCosh),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandDegrees, I18n::Message::PythonDegrees),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandDivMod, I18n::Message::PythonDivMod),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandDrawString, I18n::Message::PythonDrawString),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandConstantE, I18n::Message::PythonConstantE, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandErf, I18n::Message::PythonErf),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandErfc, I18n::Message::PythonErfc),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandEval, I18n::Message::PythonEval),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandExp, I18n::Message::PythonExp),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandExpm1, I18n::Message::PythonExpm1),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandFabs, I18n::Message::PythonFabs),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandFillRect, I18n::Message::PythonFillRect),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandFloat, I18n::Message::PythonFloat),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandFloor, I18n::Message::PythonFloor),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandForward, I18n::Message::PythonTurtleForward),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandFmod, I18n::Message::PythonFmod),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandFrExp, I18n::Message::PythonFrExp),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportFromCmath, I18n::Message::PythonImportFromCmath, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportFromKandinsky, I18n::Message::PythonImportFromKandinsky, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportFromMath, I18n::Message::PythonImportFromMath, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportFromRandom, I18n::Message::PythonImportFromRandom, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportFromTurtle, I18n::Message::PythonImportFromTurtle, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandGamma, I18n::Message::PythonGamma),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandGetPixel, I18n::Message::PythonGetPixel),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandGetrandbits, I18n::Message::PythonGetrandbits),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandGoto, I18n::Message::PythonTurtleGoto),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandGreen, I18n::Message::PythonTurtleGreen, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandGrey, I18n::Message::PythonTurtleGrey, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandHeading, I18n::Message::PythonTurtleHeading, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandHex, I18n::Message::PythonHex),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandHideturtle, I18n::Message::PythonTurtleHideturtle, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportCmath, I18n::Message::PythonImportCmath, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportKandinsky, I18n::Message::PythonImportKandinsky, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportMath, I18n::Message::PythonImportMath, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportRandom, I18n::Message::PythonImportRandom, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImportTurtle, I18n::Message::PythonImportTurtle, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandInput, I18n::Message::PythonInput),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandInt, I18n::Message::PythonInt),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandIsdown, I18n::Message::PythonTurtleIsdown, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandIsFinite, I18n::Message::PythonIsFinite),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandIsInfinite, I18n::Message::PythonIsInfinite),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandIsNaN, I18n::Message::PythonIsNaN),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandKandinskyFunction, I18n::Message::PythonKandinskyFunction, false, I18n::Message::PythonCommandKandinskyFunctionWithoutArg),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandLdexp, I18n::Message::PythonLdexp),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandLeft, I18n::Message::PythonTurtleLeft),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandLength, I18n::Message::PythonLength),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandLgamma, I18n::Message::PythonLgamma),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandLog, I18n::Message::PythonLog),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandLog10, I18n::Message::PythonLog10),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandLog2, I18n::Message::PythonLog2),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandMathFunction, I18n::Message::PythonMathFunction, false, I18n::Message::PythonCommandMathFunctionWithoutArg),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandMax, I18n::Message::PythonMax),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandMin, I18n::Message::PythonMin),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandModf, I18n::Message::PythonModf),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandOct, I18n::Message::PythonOct),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandOrange, I18n::Message::PythonTurtleOrange, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandPendown, I18n::Message::PythonTurtlePendown, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandPenup, I18n::Message::PythonTurtlePenup, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandPensize, I18n::Message::PythonTurtlePensize),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandPhase, I18n::Message::PythonPhase),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandConstantPi, I18n::Message::PythonConstantPi, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandPink, I18n::Message::PythonTurtlePink, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandPolar, I18n::Message::PythonPolar),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandPosition, I18n::Message::PythonTurtlePosition, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandPower, I18n::Message::PythonPower),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandPrint, I18n::Message::PythonPrint),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandPurple, I18n::Message::PythonTurtlePurple, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandRadians, I18n::Message::PythonRadians),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandRandint, I18n::Message::PythonRandint),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandRandom, I18n::Message::PythonRandom, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandRandomFunction, I18n::Message::PythonRandomFunction, false, I18n::Message::PythonCommandRandomFunctionWithoutArg),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandRandrange, I18n::Message::PythonRandrange),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandRangeStartStop, I18n::Message::PythonRangeStartStop),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandRangeStop, I18n::Message::PythonRangeStop),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandRect, I18n::Message::PythonRect),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandRed, I18n::Message::PythonTurtleRed, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandReset, I18n::Message::PythonTurtleReset, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandRight, I18n::Message::PythonTurtleRight),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandRound, I18n::Message::PythonRound),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandSetheading, I18n::Message::PythonTurtleSetheading),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandSetPixel, I18n::Message::PythonSetPixel),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandSeed, I18n::Message::PythonSeed),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandShowturtle, I18n::Message::PythonTurtleShowturtle, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandSin, I18n::Message::PythonSin),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandSinh, I18n::Message::PythonSinh),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandSorted, I18n::Message::PythonSorted),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandSpeed, I18n::Message::PythonTurtleSpeed),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandSqrt, I18n::Message::PythonSqrt),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandSum, I18n::Message::PythonSum),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandTan, I18n::Message::PythonTan),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandTanh, I18n::Message::PythonTanh),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandTrunc, I18n::Message::PythonTrunc),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandTurtleFunction, I18n::Message::PythonTurtleFunction, false, I18n::Message::PythonCommandTurtleFunctionWithoutArg),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandUniform, I18n::Message::PythonUniform),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandWhite, I18n::Message::PythonTurtleWhite, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonTurtleCommandYellow, I18n::Message::PythonTurtleYellow, false),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandImag, I18n::Message::PythonImag, false, I18n::Message::PythonCommandImagWithoutArg),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandReal, I18n::Message::PythonReal, false, I18n::Message::PythonCommandRealWithoutArg)
};

const ToolboxMessageTree functionsChildren[] = {
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandDefWithArg, I18n::Message::Default, false, I18n::Message::PythonCommandDef),
  ToolboxMessageTree::Leaf(I18n::Message::PythonCommandReturn, I18n::Message::Default)
};

const ToolboxMessageTree menu[] = {
  ToolboxMessageTree::Node(I18n::Message::LoopsAndTests, loopsAndTestsChildren),
  ToolboxMessageTree::Node(I18n::Message::Modules, modulesChildren),
  ToolboxMessageTree::Node(I18n::Message::Catalog, catalogChildren),
  ToolboxMessageTree::Node(I18n::Message::Functions, functionsChildren)
};

const ToolboxMessageTree toolboxModel = ToolboxMessageTree::Node(I18n::Message::Toolbox, menu);


PythonToolbox::PythonToolbox() :
  Toolbox(nullptr, rootModel()->label())
{
}

bool PythonToolbox::handleEvent(Ion::Events::Event event) {
  if (Toolbox::handleEvent(event)) {
    return true;
  }
  if (event.hasText() && strlen(event.text()) == 1 ) {
    char c = event.text()[0];
    if (UTF8Helper::CodePointIsLetter(c)) {
      scrollToLetter(c);
      return true;
    }
  }
  return false;
}

KDCoordinate PythonToolbox::rowHeight(int j) {
  if (typeAtLocation(0, j) == Toolbox::LeafCellType && m_messageTreeModel->label() == I18n::Message::IfStatementMenu) {
      /* To get the exact height needed for each cell, we have to compute its
       * text size, which means scan the text char by char to look for '\n'
       * chars. This is very costly and ruins the speed performance when
       * scrolling at the bottom of a long table: to compute a position on the
       * kth row, we call cumulatedHeightFromIndex(k), which calls rowHeight k
       * times.
       * We thus decided to compute the real height only for the ifStatement
       * children of the toolbox, which is the only menu that has special height
       * rows. */
    const ToolboxMessageTree * messageTree = static_cast<const ToolboxMessageTree *>(m_messageTreeModel->children(j));
    return k_font->stringSize(I18n::translate(messageTree->label())).height() + 2*Metric::TableCellLabelTopMargin + (messageTree->text() == I18n::Message::Default ? 0 : Toolbox::rowHeight(j));
  }
  return Toolbox::rowHeight(j);
}

bool PythonToolbox::selectLeaf(int selectedRow) {
  m_selectableTableView.deselectTable();
  ToolboxMessageTree * node = (ToolboxMessageTree *)m_messageTreeModel->children(selectedRow);
  const char * editedText = I18n::translate(node->insertedText());
  if (node->stripInsertedText()) {
    int strippedEditedTextMaxLength = strlen(editedText)+1;
    char strippedEditedText[k_maxMessageSize];
    assert(strippedEditedTextMaxLength <= k_maxMessageSize);
    Shared::ToolboxHelpers::TextToInsertForCommandMessage(node->insertedText(), strippedEditedText, strippedEditedTextMaxLength, true);
    editedText = strippedEditedText;
  }
  sender()->handleEventWithText(editedText, true);
  app()->dismissModalViewController();
  return true;
}

const ToolboxMessageTree * PythonToolbox::rootModel() {
  return &toolboxModel;
}

MessageTableCellWithMessage * PythonToolbox::leafCellAtIndex(int index) {
  assert(index >= 0 && index < k_maxNumberOfDisplayedRows);
  return &m_leafCells[index];
}

MessageTableCellWithChevron* PythonToolbox::nodeCellAtIndex(int index) {
  assert(index >= 0 && index < k_maxNumberOfDisplayedRows);
  return &m_nodeCells[index];
}

int PythonToolbox::maxNumberOfDisplayedRows() {
 return k_maxNumberOfDisplayedRows;
}

void PythonToolbox::scrollToLetter(char letter) {
  assert(UTF8Helper::CodePointIsLetter(letter));
  /* We look for a child MessageTree that starts with the wanted letter. If we
   * do not find one, we scroll to the first child MessageTree that starts with
   * a letter higher than the wanted letter. */
  char lowerLetter = tolower(letter);
  int index = -1;
  for (int i = 0; i < m_messageTreeModel->numberOfChildren(); i++) {
    char l = tolower(I18n::translate(m_messageTreeModel->children(i)->label())[0]);
    if (l == lowerLetter) {
      index = i;
      break;
    }
    if (index < 0 && l >= lowerLetter && UTF8Helper::CodePointIsLowerCaseLetter(l)) {
      index = i;
    }
  }
  if (index >= 0) {
    scrollToAndSelectChild(index);
  }
}

void PythonToolbox::scrollToAndSelectChild(int i) {
  assert(i >=0 && i<m_messageTreeModel->numberOfChildren());
  m_selectableTableView.deselectTable();
  m_selectableTableView.scrollToCell(0, i);
  m_selectableTableView.selectCellAtLocation(0, i);
}

}

