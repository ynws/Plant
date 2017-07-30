#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "IOBase.h"

class MockIO : public IOBase {
public:
	MOCK_METHOD6(DrawLine, int(int x1, int y1, int x2, int y2, unsigned int Color, int Thickness));
	MOCK_METHOD2(GetMousePoint, int(int *XBuf, int *YBuf));
	MOCK_METHOD0(GetMouseInput, int(void));
	MOCK_METHOD0(GetMouseWheelRotVol, int());
};