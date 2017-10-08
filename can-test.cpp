#include "can.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace testing;

class MockSpiDriver : public SpiDriver {
public:
	MOCK_METHOD0(select, void());
	MOCK_METHOD0(deselect, void());
	MOCK_METHOD0(read, uint8_t());
	MOCK_METHOD1(write, void(uint8_t));
};

class Mcp2515CoreTest : public Test {
};

TEST_F(Mcp2515CoreTest, construction) {
	MockSpiDriver spiDriver;
	Mcp2515Core mcp{spiDriver};
}

TEST_F(Mcp2515CoreTest, reset) {
	MockSpiDriver spiDriver;
	Mcp2515Core mcp{spiDriver};

	InSequence inSequence;
	EXPECT_CALL(spiDriver, select());
	EXPECT_CALL(spiDriver, write(0xC0));
	EXPECT_CALL(spiDriver, deselect());

	mcp.reset();
}
