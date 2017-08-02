#include "MockIO.h"
#include "LSystemView.h"

TEST(LSview, Draw)
{
	MockIO mock;
	// �^��ɐi��ŁA����]����1���i�񂾌�E��]���Đ^��ɐi��
	LSystem model("F+f-F");
	LSystemView view(&mock, &model);

	EXPECT_CALL(mock, DrawLine(600, 360, 600, 353, 0, 1)).Times(1);
	EXPECT_CALL(mock, DrawLine(594, 353, 594, 346, 0, 1)).Times(1);
	view.Draw(0);
}

TEST(LSview, SetAngle)
{
	MockIO mock;
	// ����]����1���i��
	LSystem model("+F");
	LSystemView view(&mock, &model);

	EXPECT_CALL(mock, DrawLine(600, 360, 593, 360, 0, 1)).Times(1);
	view.Draw(0);

	// �p�x�w��ŋt�����ɂȂ�
	model.SetAngle(-90.0);
	EXPECT_CALL(mock, DrawLine(600, 360, 607, 360, 0, 1)).Times(1);
	view.Draw(0);
}

TEST(LSview, NotDraw)
{
	MockIO mock;
	LSystem model("+X-");
	LSystemView view(&mock, &model);

	EXPECT_CALL(mock, DrawLine(_, _, _, _, _, _)).Times(0);
	view.Draw(0);
}

TEST(LSview, SetStepSize)
{
	MockIO mock;
	LSystem model("");
	LSystemView view(&mock, &model);
	view.SetScale(10);
	ASSERT_EQ(view.GetScale(), 10);
	view.SetScale(5);
	ASSERT_EQ(view.GetScale(), 5);
}

TEST(LSview, SetStepSizeMin)
{
	MockIO mock;
	LSystem model("");
	LSystemView view(&mock, &model);
	view.SetScale(10);
	// �w�肪����������ꍇ�A�ŏ��l�܂Ń��T�C�Y
	view.SetScale(1);
	ASSERT_EQ(view.GetScale(), 2);
}

TEST(LSview, Stack)
{
	MockIO mock;
	// ��ԕۑ����Ă���ړ��B�Ō�ɏ�����Ԃŕ`��
	LSystem model("[Ff+]F");
	LSystemView view(&mock, &model);

	EXPECT_CALL(mock, DrawLine(600, 360, 600, 353, 0, 1)).Times(2);
	view.Draw(0);
}

TEST(LSview, StackEmpty)
{
	MockIO mock;
	// 2��ڂ̏����o���͂ł��Ȃ��̂ŁA��������
	LSystem model("[Ff+]]F");
	LSystemView view(&mock, &model);

	EXPECT_CALL(mock, DrawLine(600, 360, 600, 353, 0, 1)).Times(2);
	view.Draw(0);
}
