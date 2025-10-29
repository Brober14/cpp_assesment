#include "Gene.h"
#include <cassert>
#include <sstream>
#include <iostream>

// ============================================================================
// TEST HELPER FUNCTION - Displays errors only (quiet on success)
// ============================================================================
void reportTest(const std::string testName) {
    std::cerr << "FAILED: " << testName << std::endl;
}

// ============================================================================
// TEST 1: Default Constructor
// ============================================================================
bool testDefaultConstructor() {
    Gene g;

    assert(g.getId() == "");
    assert(g.getSequence() == "");
    assert(g.getPropensity() == 0.0);

    return true;
}

// ============================================================================
// TEST 2: Parameterized Constructor
// ============================================================================
bool testParamConstructor() {
    //Prepare test data
    std::string testId = "testI";
    std::string testSeq = "testS";

    //Create Gene with test data
    Gene g(testId, testSeq);

    //Verify all members are correctly initialized
    assert(g.getId() == "testI");
    assert(g.getSequence() == "testS");
    assert(g.getPropensity() == 0.0);

    return true;
}

// ============================================================================
// TEST 3: Getter/Setter Methods
// ============================================================================
bool testGettersAndSetters() {
    //Prepare test data
    std::string testId = "testI";
    std::string testSeq = "testS";
    double testProp = 2.5;

    //Initialize the Gene
    Gene g;

    //Set test values via Setters
    g.setId(testId);
    g.setSequence(testSeq);
    g.setPropensity(testProp);

    //Verify all members correctly changed values
    assert(g.getId() == "testI");
    assert(g.getSequence() == "testS");
    assert(g.getPropensity() == 2.5);

    
    return true;
}

// ============================================================================
// TEST 4: toString() Method
// ============================================================================
bool testToString() {
    //Prepare test data
    Gene g("FAAS012", "gcggcaaa");
    g.setPropensity(2.5);

    //Call toString method
    std::string result = g.toString();

    //Verify the data
    assert(result.find("FAAS012") != std::string::npos);
    assert(result.find("gcggcaaa") != std::string::npos);
    assert(result.find(2.5) != std::string::npos);

    return true;
}

// ============================================================================
// TEST 5: Test < Operator
// ============================================================================
bool testLessOperator() {
    //Prepare test data
    Gene g1;
    Gene g2;
    g1.setPropensity(2.5);
    g2.setPropensity(5.0);

    //Compare data
    bool result1 = g1 < g2;  //True
    bool result2 = g2 < g1;  //False
    bool result3 = g1 < g1;  //False

    //Verify data
    assert(result1 == true);
    assert(result2 == false);
    assert(result3 == false);

    return true;
}

// ============================================================================
// TEST 6: Test <= Operator
// ============================================================================
bool testLessOrEqualsOperator() {
    //Prepare test data
    Gene g1;
    Gene g2;
    g1.setPropensity(2.5);
    g2.setPropensity(5.0);

    //Compare data
    bool result1 = g1 < g2;  //True
    bool result2 = g2 < g1;  //False
    bool result3 = g1 <= g1;  //True

    //Verify data
    assert(result1 == true);
    assert(result2 == false);
    assert(result3 == true);

    return true;
}

// ============================================================================
// TEST 7: Test > Operator
// ============================================================================
bool testGreaterOperator() {
    //Prepare test data
    Gene g1;
    Gene g2;
    g1.setPropensity(2.5);
    g2.setPropensity(5.0);

    //Compare data
    bool result1 = g1 > g2;  //False
    bool result2 = g2 > g1;  //True
    bool result3 = g1 > g1;  //False

    //Verify data
    assert(result1 == false);
    assert(result2 == true);
    assert(result3 == false);

    return true;
}

// ============================================================================
// TEST 8: Test >= Operator
// ============================================================================
bool testGreaterOrEqualsOperator() {
    //Prepare test data
    Gene g1;
    Gene g2;
    g1.setPropensity(2.5);
    g2.setPropensity(5.0);

    //Compare data
    bool result1 = g1 > g2;  //False
    bool result2 = g2 > g1;  //True
    bool result3 = g1 >= g1;  //True

    //Verify data
    assert(result1 == false);
    assert(result2 == true);
    assert(result3 == true);

    return true;
}

// ============================================================================
// TEST 9: Test == Operator
// ============================================================================
bool testEqualsOperator() {
    //Prepare test data
    Gene g1;
    Gene g2;
    g1.setPropensity(2.5);
    g2.setPropensity(5.0);

    //Compare data
    bool result1 = g1 == g2;  //False
    bool result2 = g1 == g1;  //True

    //Verify data
    assert(result1 == false);
    assert(result2 == true);

    return true;
}

// ============================================================================
// TEST 10: Test != Operator
// ============================================================================
bool testNotEqualsOperator() {
    //Prepare test data
    Gene g1;
    Gene g2;
    g1.setPropensity(2.5);
    g2.setPropensity(5.0);

    //Compare data
    bool result1 = g1 != g2;  //True
    bool result2 = g1 != g1;  //False

    //Verify data
    assert(result1 == true);
    assert(result2 == false);

    return true;
}

// ============================================================================
// TEST 11: Test Stream Output Operator (<<)
// ============================================================================
bool testStreamOutput() {
    //Prepare test data
    Gene g("FAS012", "acgtaa");
    g.setPropensity(2.5);

    //Write to stringstream
    std::stringstream ss;
    ss << g;
    std::string output = ss.str();

    //Verify data
    assert(output.find("FAS012") != std::string::npos);
    assert(output.find("acgtaa") != std::string::npos);
    assert(output.find("2.5") != std::string::npos);
    assert(output.find(",") != std::string::npos);
    assert(output.find("\"") != std::string::npos);

    return true;
}

// ============================================================================
// TEST 12: Test Stream Input Operator (>>)
// ============================================================================
bool testStreamInput() {
    //Prepare test data
    std::stringstream ss("\"FAS012\",\"acgtaa\",\"2.5\"");
    Gene g;

    //Read from stringstream
    ss >> g;

    //Verify data
    assert(g.getId() == "FAS012");
    assert(g.getSequence() == "acgtaa");
    assert(g.getPropensity() == 2.5);

    return true;
}

// ============================================================================
// TEST 13: Test I/O Round-Trip (Write then Read)
// ============================================================================
bool testStreamIO() {
    //Prepare Original gene
    Gene g_original("FAS012", "acgtaa");
    g_original.setPropensity(2.5);

    //Write to stream
    std::stringstream ss;
    ss << g_original;

    //Read back from the stream
    Gene g_readback;
    ss >> g_readback;

    //Verify the data
    assert(g_readback.getId() == g_original.getId());
    assert(g_readback.getSequence() == g_original.getSequence());
    assert(g_readback.getPropensity() == g_original.getPropensity());

    return true;
}

// ============================================================================
// MAIN TEST FUNCTION
// ============================================================================
bool testGene() {
    bool allPassed = true;

    if(!testDefaultConstructor()) {
        reportTest("Test 1: Default Constructor");
        allPassed = false;
    }

    if(!testParamConstructor()) {
        reportTest("Test 2: Parameterized Constructor");
        allPassed = false;
    }

    if(!testGettersAndSetters()) {
        reportTest("Test 3: Getters and Setters");
        allPassed = false;
    }

    if(!testToString()) {
        reportTest("Test 4: ToString Method");
        allPassed = false;
    }

    if(!testLessOperator()) {
        reportTest("Test 5: < Operator");
        allPassed = false;
    }

    if(!testLessOrEqualsOperator()) {
        reportTest("Test 6: <= Operator");
        allPassed = false;
    }

    if(!testGreaterOperator()) {
        reportTest("Test 7: > Operator");
        allPassed = false;
    }

    if(!testGreaterOrEqualsOperator()) {
        reportTest("Test 8: >= Operator");
        allPassed = false;
    }

    if(!testEqualsOperator()) {
        reportTest("Test 9: == Operator");
        allPassed = false;
    }

    if(!testNotEqualsOperator()) {
        reportTest("Test 10: != Operator");
        allPassed = false;
    }

    if(!testStreamOutput()) {
        reportTest("Test 11: Stream Output");
        allPassed = false;
    }

    if(!testStreamInput()) {
        reportTest("Test 12: Stream Input");
        allPassed = false;
    }

    if(!testStreamIO()) {
        reportTest("Test 13: Stream I/O");
        allPassed = false;
    }

    return allPassed;
}


// ============================================================================
// Function for Standalone testing
// ============================================================================
int main() {
    return testGene() ? 0:1;
}

