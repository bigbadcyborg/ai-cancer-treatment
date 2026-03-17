CXX      = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -Wpedantic

SRCS = main.cpp \
       ruleBase/ruleBase.cpp \
       factBase/factBase.cpp \
       decisionTree/decisionTree.cpp

TARGET = cancer-expert-system

.PHONY: all clean test-rulebase test-dt

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# ── Individual test targets ──────────────────────────────────────────────────

test-rulebase:
	$(CXX) $(CXXFLAGS) \
	    ruleBase/testRuleBase.cpp \
	    ruleBase/ruleBase.cpp \
	    factBase/factBase.cpp \
	    decisionTree/decisionTree.cpp \
	    -o /tmp/test-rulebase && /tmp/test-rulebase

test-dt:
	$(CXX) $(CXXFLAGS) \
	    decisionTree/test-decisionTree.cpp \
	    ruleBase/ruleBase.cpp \
	    factBase/factBase.cpp \
	    decisionTree/decisionTree.cpp \
	    -o /tmp/test-dt

clean:
	rm -f $(TARGET)
