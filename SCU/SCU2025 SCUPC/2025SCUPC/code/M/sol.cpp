#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <unordered_map>
#include <chrono>
#include <iomanip>
using namespace std;
 
// 牌的结构体
struct Card {
    int value;  // 2-14 (2-A)
    int suit;   // 0-3 (♠,♥,♣,♦)
    
    Card(int v, int s) : value(v), suit(s) {}
    bool operator==(const Card& other) const {
        return value == other.value && suit == other.suit;
    }
};
 
// 牌型枚举
enum HandRank {
    HIGH_CARD,
    PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH
};
 
// 前向声明
bool isFlush(const vector<Card>& cards);
bool isStraight(const vector<Card>& cards);
bool isStraightFlush(const vector<Card>& cards);
HandRank getHandRank(const vector<Card>& cards);
 
// 解析牌面字符串
Card parseCard(const string& cardStr) {
    static unordered_map<char, int> valueMap = {
        {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8},
        {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}
    };
    static unordered_map<char, int> suitMap = {
        {'S', 0}, {'H', 1}, {'C', 2}, {'D', 3}
    };
    
    return Card(valueMap[cardStr[0]], suitMap[cardStr[1]]);
}
// 获取花色符号
string getSuitSymbol(int suit) {
    switch (suit) {
        case 0: return "♠";
        case 1: return "♥";
        case 2: return "♣";
        case 3: return "♦";
        default: return "?";
    }
}
 
// 获取点数符号
string getValueSymbol(int value) {
    switch (value) {
        case 14: return "A";
        case 13: return "K";
        case 12: return "Q";
        case 11: return "J";
        case 10: return "T";
        default: return to_string(value);
    }
}
// 获取牌型名称
string getHandRankName(HandRank rank) {
    switch (rank) {
        case STRAIGHT_FLUSH: return "同花顺";
        case FOUR_OF_A_KIND: return "四条";
        case FULL_HOUSE: return "葫芦";
        case FLUSH: return "同花";
        case STRAIGHT: return "顺子";
        case THREE_OF_A_KIND: return "三条";
        case TWO_PAIR: return "两对";
        case PAIR: return "一对";
        case HIGH_CARD: return "高牌";
        default: return "未知";
    }
}
 
// 格式化输出手牌
string formatHand(const vector<Card>& cards) {
    string result;
    for (const auto& card : cards) {
        result += getValueSymbol(card.value) + getSuitSymbol(card.suit) + " ";
    }
    return result;
}
// 获取最大的5张牌和牌型
pair<HandRank, vector<Card>> getBestFiveCards(const vector<Card>& cards) {
    vector<Card> result;
    vector<int> valueCount(15, 0);
    for (const auto& card : cards) {
        valueCount[card.value]++;
    }
    
    // 检查是否为同花
    vector<int> suitCount(4, 0);
    for (const auto& card : cards) {
        suitCount[card.suit]++;
    }
    
    // 找出最多的花色
    int maxSuit = 0;
    int maxCount = 0;
    for (int i = 0; i < 4; i++) {
        if (suitCount[i] > maxCount) {
            maxCount = suitCount[i];
            maxSuit = i;
        }
    }
    
    // 如果某个花色至少有5张牌
    if (maxCount >= 5) {
        vector<int> flushValues;
        for (const auto& card : cards) {
            if (card.suit == maxSuit) {
                flushValues.push_back(card.value);
            }
        }
        sort(flushValues.begin(), flushValues.end());
        
        // 检查是否为同花顺
        bool foundBigStraight = false;
        for (int i = flushValues.size() - 1; i >= 4; i--) {
            bool isStraight = true;
            for (int j = 0; j < 5; j++) {
                if (flushValues[i - j] != flushValues[i] - j) {
                    isStraight = false;
                    break;
                }
            }
            if (isStraight) {
                for (int j = 0; j < 5; j++) {
                    for (const auto& card : cards) {
                        if (card.value == flushValues[i - j] && card.suit == maxSuit) {
                            result.push_back(card);
                            break;
                        }
                    }
                }
                foundBigStraight = true;
                break;
            }
        }
        
        // 如果没有找到其他同花顺，再检查A2345
        if (!foundBigStraight) {
            bool hasAce = false;
            bool has2345 = true;
            for (int i = 2; i <= 5; i++) {
                bool found = false;
                for (const auto& card : cards) {
                    if (card.value == i && card.suit == maxSuit) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    has2345 = false;
                    break;
                }
            }
            for (const auto& card : cards) {
                if (card.value == 14 && card.suit == maxSuit) {
                    hasAce = true;
                    break;
                }
            }
            
            if (hasAce && has2345) {
                // 输出A2345
                for (int i = 2; i <= 5; i++) {
                    for (const auto& card : cards) {
                        if (card.value == i && card.suit == maxSuit) {
                            result.push_back(card);
                            break;
                        }
                    }
                }
                for (const auto& card : cards) {
                    if (card.value == 14 && card.suit == maxSuit) {
                        result.push_back(card);
                        break;
                    }
                }
                return {STRAIGHT_FLUSH, result};
            }
        } else {
            return {STRAIGHT_FLUSH, result};
        }
        
        // 如果不是同花顺，就是同花
        sort(flushValues.rbegin(), flushValues.rend());
        // 取最大的5张
        for (int i = 0; i < 5; i++) {
            for (const auto& card : cards) {
                if (card.value == flushValues[i] && card.suit == maxSuit) {
                    result.push_back(card);
                    break;
                }
            }
        }
        return {FLUSH, result};
    }
    
    // 统计相同点数的牌
    vector<int> fourOfAKindValues;
    vector<int> threeOfAKindValues;
    vector<int> pairValues;
    for (int i = 14; i >= 2; i--) {  // 从大到小遍历，确保排序
        if (valueCount[i] == 4) {
            fourOfAKindValues.push_back(i);
        } else if (valueCount[i] == 3) {
            threeOfAKindValues.push_back(i);
        } else if (valueCount[i] == 2) {
            pairValues.push_back(i);
        }
    }
    
    // 四条
    if (!fourOfAKindValues.empty()) {
        // 找出四条的点数
        int fourValue = fourOfAKindValues[0];  // 最大的四条
        // 先加入四条
        for (const auto& card : cards) {
            if (card.value == fourValue) {
                result.push_back(card);
            }
        }
        // 加入最大的单牌
        for (int i = 14; i >= 2; i--) {
            if (i != fourValue && valueCount[i] > 0) {
                for (const auto& card : cards) {
                    if (card.value == i) {
                        result.push_back(card);
                        break;
                    }
                }
                break;
            }
        }
        return {FOUR_OF_A_KIND, result};
    }
    
    // 葫芦
    if (threeOfAKindValues.size()+pairValues.size() >= 2 && !threeOfAKindValues.empty()) {
        // 如果有多个三条，选择最大的三条作为三条部分，次大的三条作为对子部分
        int threeValue = threeOfAKindValues[0];  // 最大的三条
        int pairValue;
        
        if (threeOfAKindValues.size() > 1) {
            // 如果有多个三条，用次大的三条作为对子
            pairValue = threeOfAKindValues[1];
        } else {
            // 如果只有一个三条，用最大的对子
            pairValue = pairValues[0];
        }
        
        // 先加入三条（只取3张）
        int threeCount = 0;
        for (const auto& card : cards) {
            if (card.value == threeValue && threeCount < 3) {
                result.push_back(card);
                threeCount++;
            }
        }
        // 加入对子（只取2张）
        int pairCount = 0;
        for (const auto& card : cards) {
            if (card.value == pairValue && pairCount < 2) {
                result.push_back(card);
                pairCount++;
            }
        }
        return {FULL_HOUSE, result};
    }
    
    // 顺子
    vector<int> straightValues;
    for (const auto& card : cards) {
        straightValues.push_back(card.value);
    }
    // 去重并排序
    sort(straightValues.begin(), straightValues.end());
    straightValues.erase(unique(straightValues.begin(), straightValues.end()), straightValues.end());
    
    // 先尝试找出最大的顺子
    bool foundBigStraight = false;
    for (int i = straightValues.size() - 1; i >= 4; i--) {
        bool isStraight = true;
        for (int j = 0; j < 5; j++) {
            if (straightValues[i - j] != straightValues[i] - j) {
                isStraight = false;
                break;
            }
        }
        if (isStraight) {
            // 找到顺子后，从原始牌中选择对应的牌
            for (int j = 0; j < 5; j++) {
                int targetValue = straightValues[i - j];
                // 从原始牌中选择一张该点数的牌
                for (const auto& card : cards) {
                    if (card.value == targetValue) {
                        result.push_back(card);
                        break;
                    }
                }
            }
            foundBigStraight = true;
            break;
        }
    }
    
    // 如果没有找到其他顺子，再检查A2345
    if (!foundBigStraight) {
        bool hasAce = false;
        bool has2345 = true;
        for (int i = 2; i <= 5; i++) {
            if (find(straightValues.begin(), straightValues.end(), i) == straightValues.end()) {
                has2345 = false;
                break;
            }
        }
        if (find(straightValues.begin(), straightValues.end(), 14) != straightValues.end()) {
            hasAce = true;
        }
        
        if (hasAce && has2345) {
            // 输出A2345
            for (int i = 2; i <= 5; i++) {
                for (const auto& card : cards) {
                    if (card.value == i) {
                        result.push_back(card);
                        break;
                    }
                }
            }
            for (const auto& card : cards) {
                if (card.value == 14) {
                    result.push_back(card);
                    break;
                }
            }
            return {STRAIGHT, result};
        }
    } else {
        return {STRAIGHT, result};
    }
    
    // 三条
    if (!threeOfAKindValues.empty()) {
        // 找出三条的点数
        int threeValue = threeOfAKindValues[0];  // 最大的三条
        // 先加入三条
        for (const auto& card : cards) {
            if (card.value == threeValue) {
                result.push_back(card);
            }
        }
        // 加入最大的两张单牌
        int count = 0;
        for (int i = 14; i >= 2; i--) {
            if (i != threeValue && valueCount[i] > 0) {
                for (const auto& card : cards) {
                    if (card.value == i) {
                        result.push_back(card);
                        count++;
                        break;
                    }
                }
                if (count == 2) break;
            }
        }
        return {THREE_OF_A_KIND, result};
    }
    
    // 两对
    if (pairValues.size() >= 2) {
        // 找出两对和单牌的点数
        int kicker = 0;
        // 从大到小遍历，找到最大的单牌作为踢脚
        for (int i = 14; i >= 2; i--) {
            if (valueCount[i] == 1) {
                kicker = i;
                break;
            }
        }
        // 如果有第三个对子，比较第三个对子和单牌，选择较大的作为踢脚
        if (pairValues.size() >= 3) {
            kicker = max(kicker, pairValues[2]);
        }
        
        // 先加入较大的对子
        int pairCount = 0;
        for (const auto& card : cards) {
            if (card.value == pairValues[0] && pairCount < 2) {
                result.push_back(card);
                pairCount++;
            }
        }
        // 加入较小的对子
        pairCount = 0;
        for (const auto& card : cards) {
            if (card.value == pairValues[1] && pairCount < 2) {
                result.push_back(card);
                pairCount++;
            }
        }
        // 加入踢脚
        if (kicker != 0) {
            for (const auto& card : cards) {
                if (card.value == kicker) {
                    result.push_back(card);
                    break;
                }
            }
        }
        return {TWO_PAIR, result};
    }
    
    // 一对
    if (!pairValues.empty()) {
        // 找出对子和单牌的点数
        int pairValue = pairValues[0];  // 最大的对子
        vector<int> kickers;
        for (int i = 14; i >= 2; i--) {
            if (i != pairValue && valueCount[i] == 1) {
                kickers.push_back(i);
            }
        }
        // 先加入对子
        for (const auto& card : cards) {
            if (card.value == pairValue) {
                result.push_back(card);
            }
        }
        // 加入最大的三张单牌
        for (int i = 0; i < 3; i++) {
            for (const auto& card : cards) {
                if (card.value == kickers[i]) {
                    result.push_back(card);
                    break;
                }
            }
        }
        return {PAIR, result};
    }
    
    // 高牌
    vector<int> highCardValues;
    for (const auto& card : cards) {
        highCardValues.push_back(card.value);
    }
    sort(highCardValues.rbegin(), highCardValues.rend());
    for (int i = 0; i < 5; i++) {
        for (const auto& card : cards) {
            if (card.value == highCardValues[i]) {
                result.push_back(card);
                break;
            }
        }
    }
    return {HIGH_CARD, result};
}
 
// 比较两手牌的大小，返回-1表示hand1赢，1表示hand2赢，0表示平局
int compareHands(const vector<Card>& hand1, const vector<Card>& hand2) {
    auto [rank1, bestFive1] = getBestFiveCards(hand1);
    auto [rank2, bestFive2] = getBestFiveCards(hand2);
    
    
    // 先比较牌型
    if (rank1 != rank2) return rank1 > rank2 ? -1 : 1;
    
    // 如果牌型相同，比较组成牌型的5张牌
    for (int i = 0; i < 5; i++) {
        if (bestFive1[i].value > bestFive2[i].value) return -1;
        if (bestFive1[i].value < bestFive2[i].value) return 1;
    }
    /*
    cout<<formatHand(hand1)<<endl;
    cout<<formatHand(hand2)<<endl;
    cout<<getHandRankName(rank1)<<endl;
    cout<<getHandRankName(rank2)<<endl;
    cout<<formatHand(bestFive1)<<endl;
    cout<<formatHand(bestFive2)<<endl;*/
    return 0; // 完全相等，平局
}
 
// 生成一副完整的牌
vector<Card> generateDeck() {
    vector<Card> deck;
    for (int v = 2; v <= 14; v++) {
        for (int s = 0; s < 4; s++) {
            deck.emplace_back(v, s);
        }
    }
    return deck;
}
 
// 生成所有可能的公共牌组合
void generateAllCombinations(vector<Card>& deck, vector<Card>& current, int start, int remaining,
                           vector<vector<Card>>& result) {
    if (remaining == 0) {
        result.push_back(current);
        return;
    }
    
    for (int i = start; i <= deck.size() - remaining; i++) {
        current.push_back(deck[i]);
        generateAllCombinations(deck, current, i + 1, remaining - 1, result);
        current.pop_back();
    }
}
// 主函数
int main() {
    string hand1, hand2, community;
    //cout << "请输入玩家1的手牌 (例如: 7DAS): ";
    cin >> hand1;
    //cout << "请输入玩家2的手牌 (例如: TSAD): ";
    cin >> hand2;
    //cout << "请输入公共牌 (例如: 2S2H4S...): ";
    cin >> community;
    
    // 解析输入
    vector<Card> player1Cards = {parseCard(hand1.substr(0,2)), parseCard(hand1.substr(2,2))};
    vector<Card> player2Cards = {parseCard(hand2.substr(0,2)), parseCard(hand2.substr(2,2))};
    vector<Card> communityCards;
    
    for (int i = 0; i < community.length(); i += 2) {
        if (community[i] != '*') {
            communityCards.push_back(parseCard(community.substr(i,2)));
        }
    }
    
    //cout << "\n当前牌面：" << endl;
    //cout << "玩家1手牌: " << formatHand(player1Cards) << endl;
    //cout << "玩家2手牌: " << formatHand(player2Cards) << endl;
    //cout << "公共牌: " << formatHand(communityCards) << endl;
    
    // 生成一副完整的牌
    vector<Card> deck = generateDeck();
    
    // 移除已知的牌
    auto removeCard = [&deck](const Card& card) {
        deck.erase(remove_if(deck.begin(), deck.end(),
            [&card](const Card& c) { return c == card; }), deck.end());
    };
    
    for (const auto& card : player1Cards) removeCard(card);
    for (const auto& card : player2Cards) removeCard(card);
    for (const auto& card : communityCards) removeCard(card);
    
    // 计算需要补充的公共牌数量
    int remainingCards = 5 - communityCards.size();
    
    // 生成所有可能的公共牌组合
    vector<vector<Card>> allCombinations;
    vector<Card> current;
    generateAllCombinations(deck, current, 0, remainingCards, allCombinations);
    
    // 统计胜率
    int totalCombinations = allCombinations.size();
    int player1Wins = 0;
    int player2Wins = 0;
    int ties = 0;
    
    for (const auto& combination : allCombinations) {
        // 组合成完整的手牌
        vector<Card> hand1 = player1Cards;
        hand1.insert(hand1.end(), communityCards.begin(), communityCards.end());
        hand1.insert(hand1.end(), combination.begin(), combination.end());
        
        vector<Card> hand2 = player2Cards;
        hand2.insert(hand2.end(), communityCards.begin(), communityCards.end());
        hand2.insert(hand2.end(), combination.begin(), combination.end());
        
        // 比较大小
        int result = compareHands(hand1, hand2);
        if (result < 0) {
            player1Wins++;
        } else if (result > 0) {
            player2Wins++;
        } else {
            ties++;
        }
    }
    
    // 输出结果
    double player1Odds = (double)player1Wins / totalCombinations ;
    double player2Odds = (double)player2Wins / totalCombinations ;
    double tieOdds = (double)ties / totalCombinations ;
    
    //cout << "\n胜率统计：" << endl;
    cout << fixed << setprecision(15) << player1Odds << endl;
    cout << fixed << setprecision(15) << player2Odds << endl;
    cout << fixed << setprecision(15) << tieOdds  << endl;
    //cout << "总组合数: " << totalCombinations << endl;
    
    return 0;
}
