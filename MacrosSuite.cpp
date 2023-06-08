#include "pch.h"
#include "headers/Space.h"
//#include "sources/Macros.cpp"


class SpaceTestFixture : public ::testing::Test {
public:
    SpaceTestFixture() {
        // initialization code here
    }

    void SetUp() {
        // code here will execute just before the test ensues 
        program = mcrs::Program(path, "", path, "");
    }

    void TearDown() {
        // code here will be called just after the test completes
        // ok to through exceptions from here if need be
    }

    ~SpaceTestFixture() {
        // cleanup any pending stuff, but no exceptions allowed
        // TODO close opened programs
    }

    // put in any custom data members that you need
public:
    mcrs::Program program;
    std::string path = "C:\\Windows\\System32\\notepad.exe";
};


TEST_F(SpaceTestFixture, LaunchProgram_ProgramExist) {
    program.path_ = "C:\\Windows\\System32\\notepad.exe";
    program.cmd_ = program.path_;
    ASSERT_EQ(mcrs::LaunchProgram(program), true);
}

TEST_F(SpaceTestFixture, LaunchProgramNegative_ProgramNotExist) {
    program.path_ = "T:\\ghost123.exe";
    program.cmd_ = program.path_;
    EXPECT_EQ(mcrs::LaunchProgram(program), false);
}