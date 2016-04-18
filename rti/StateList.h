/*
 * StateList.h
 *
 *  Created on: Apr 15, 2016
 *      Author: Brandon
 */

#ifndef STATELIST_H_
#define STATELIST_H_

#include <string>

using namespace std;

class StateList
{
	public:
		string getKindergarten();
		string getFirstGrade();
		string getSecondGrade();
		string getThirdGrade();
		string getFourthGrade();

	private:
		const string kindergarten[] = {"a","am","an","and","at"
		,"can","do","go","he","I","in","is","it","like","me","my"
		,"no","on","see","so","the","to","up","we","you"};

		const string firstgrade[] = {"all","be","big","has","how","if","not","she",
			"as","back","by","came","come","did","get","had","have","her","him","his","look","make","now","of","one","or","out","was",
			"are","away","been","but","from","here","into","little","man","our","play","put","said","saw","that","us","very","what",
			"who","your","after","because","before","could","going","just","mother","over","then","there","they",
			"this","too","two","went","were","when","where","will","with"};

		const string secondgrade[] = {"able", "above", "across", "again", "almost", "always", "any", "anything","ask","bad","bail",
				"become", "begin", "behind", "between", "books", "both", "boy", "brother", "bus","can't", "car", "carry", "cat"
				"catch", "change", "children", "city", "close", "dad", "dark", "deep", "does", "drag", "door", "down", "during", "each", "eat", "end",
				"enough", "even", "every", "fast", "father", "feel", "find", "first", "fish", "five", "food", "four", "friend", "fun", "funny",
				"game", "gave", "give", "goes", "gone", "good", "got", "grade", "great", "grew", "grow", "happy", "help", "hid", "hide", "hill", "home", "house", "inside", "jump",
				"just", "knew", "know", "last", "let", "light", "live", "love", "much", "must", "name", "new", "night", "outside", "paper", "part",
				"party", "pick", "place", "rain", "ran", "right", "room", "run", "same", "sat", "say", "school", "sea", "second", "seen", "should",
				"sit", "sky", "sleep", "snow", "something", "start", "stay", "stop", "story", "street", "take", "teach", "tell", "ten", "than",
				"their", "them", "things", "third", "through", "time", "today", "together", "top", "try", "under", "until", "use", "view",
				"wait", "walk", "wall", "want", "watch", "way", "week", "why", "winter", "work", "world", "worn", "write", "wrong", "wrote", "year",
				"you're"};

		const string thirdgrade[] = {"add", "air", "along", "also", "baby", "being", "below", "best", "better", "boat", "body", "boot", "buy", "care", "check", "circle",
				"class", "clean", "cold", "dark", "died", "dry", "fact", "fair", "feet", "fell", "few", "fire", "free", "full", "goes", "great",
				"hand", "hard", "head", "hear", "hold", "hope", "I'd", "job", "land", "left", "less", "life", "line", "list", "lost", "lot", "lots", "love",
				"mind", "miss", "more", "move", "near", "need", "nice", "old", "own", "pair", "park", "past", "plan", "real", "rest", "room", "save", "seen",
				"set", "ship", "show", "sick", "side", "small", "soon"};

		const string fourthgrade[] = {"among", "animal", "around", "asked", "became", "began", "bring", "build", "couldn't", "cried", "dinner", "doing", "draw",
				"dream", "early", "earth", "east", "everyone", "everything", "filled", "front", "getting", "group", "having", "heard",
				"heart", "high", "himself", "hurt", "idea", "inside", "instead", "keep", "kids", "killed", "kind", "knew", "learn", "leave",
				"letter", "listen", "lived", "lives", "long", "looking", "making", "mean", "money", "next", "nothing", "passed", "stand", "state",
				"still", "such", "talk", "teach", "teacher", "than", "that's", "think", "those", "throw", "told", "took" "true", "trying", "turned",
				"wanted", "warm", "wasn't", "watch", "wish", "myself", "yourself"};
};

	string StateList::getKindergarten()
	{
		return kindergarten;
	}
	string StateList::getFirstGrade()
	{
		return firstgrade;
	}
	string StateList::getSecondGrade()
	{
		return secondgrade;
	}
	string StateList::getThirdGrade()
	{
		return thirdgrade;
	}
	string StateList::getFourthGrade()
	{
		return fourthgrade;
	}

#endif /* STATELIST_H_ */
