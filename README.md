"Philosophy ought to imitate the successful sciences in its methods, so far as to proceed only from tangible premisses which can be
subjected to careful scrutiny, and to trust rather to the multitude and variety of its arguments than to the conclusiveness
of any one. Its reasoning should not form a chain which is no stronger than its weakest link, but a cable whose fibres may
be ever so slender, provided they are sufficiently numerous and intimately connected." <br> ( "Some Consequences of Four Incapacities", Charles S. Peirce ) <br><br>
I used to always say, "We live in the best time because, with computers, we have the world at our fingertips."
 
While I still believe that is very true, I now give a more accurate depiction instead:<br><br>
"We live in the best time because we have infinite knowledge at our fingertips."

My goal is to develop this ai model in a way that 
i can implement other types of queries such as advice referencing any material e.g. cancer diagnosis, treatments, documentation/researches, animal diagnosis/treatments, The Holy Bible references, and so much more.

Humans are active participants in knowledge-making. And our dynamic and interactive inquiries based on experience provides us our knowledge which is what adds to our rule set and fact set. I am developing a fact/rule based artificial intelligence program which uses a knowledge base. Over time, I will develop the knowledge base to be trained based on inquiries from deep learning algorithms as well as developer-set rules.

“In **rule-based AI**, the **fact base** provides input, the **rule base** processes it, and the **knowledge base** contains all necessary relationships.”

# Table of Contents
[ruleBase](/ai-cancer-treatment/ruleBase/) <br>
[knowledgeBase](/ai-cancer-treatment/knowledgeBase/) creates rules using facts (will use a Rule Base and and a Fact Base) <br>

[forwardChaining](/ai-cancer-treatment/forwardChaining/) <br>
[backwardChaining](/ai-cancer-treatment/backwardChaining/) <br>

![Data Structure Differences](data-structure-differences.png)
![Rule Based Intelligent Expert System Configuration](rule-based-intelligent-expert-system-config.png)

![Base-Matrix](knowledgeBase-RuleBase-FactBase-chart.png)

# Driver flow
![Flowchart](drawio.drawio.png)

# Rules
![Rules](SS0.png) <br>

# Backward Chaining
![flowchart-backwardChaining](/ai-cancer-treatment/backwardChaining/flowchart-backwardChaining.png) <br>

# Testing backwardChaining::userValidClauseVect and backwardChaining::generateSubsets
![test-backwardChaining-userValidClauseVect](/ai-cancer-treatment/backwardChaining/test-backwardChaining-generateSubsets.png) <br>

# Testing backwardChaining.cpp's Determination of Possible Conclusions
![possibleSolution](/ai-cancer-treatment/backwardChaining/test-backwardChaining-possibleConclusions.png)

# Testing backwardChaining.cpp's Diagnosis
![diagnosis](/ai-cancer-treatment/backwardChaining/test-backwardChaining-diagnosis.png)

# Testing decisionTree.h
![dt](/ai-cancer-treatment/decisionTree/test-decisionTree.png)
