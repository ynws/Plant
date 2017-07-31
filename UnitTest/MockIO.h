#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "IOBase.h"

using namespace ::testing; // îCà”ÇÃà¯êî

class MockIO : public IOBase {
public:
	MOCK_METHOD6(DrawLine, int(int x1, int y1, int x2, int y2, unsigned int Color, int Thickness));
	MOCK_METHOD2(GetMousePoint, int(int *XBuf, int *YBuf));
	MOCK_METHOD0(MouseLeftClicked, bool(void));
	MOCK_METHOD0(MouseRightClicked, bool(void));
	MOCK_METHOD0(GetMouseWheelRotVol, int());
};