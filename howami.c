#ifdef _WIN32
#define ENV_VAR "USERNAME"
#else
#define ENV_VAR "USER"
#endif

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char *feelings[] = {
	"happy",
	"sad",
	"bored",
	"angry",
	"animosity",
	"defensive",
	"defiant",
	"disturbed",
	"exasperated",
	"exploited",
	"frustrated",
	"hateful",
	"hostile",
	"intolerant",
	"irrational",
	"irritated",
	"mad",
	"provoked",
	"reluctant",
	"revengeful",
	"stubborn",
	"superior",
	"uncomfortable",
	"comfortable",
	"apprehensive",
	"bewildered",
	"cautious",
	"confused",
	"discontent",
	"distracted",
	"hesitant",
	"impatient",
	"obligated",
	"overwhelmed",
	"surprised",
	"suspicious",
	"unsafe",
	"safe",
	"uneasy",
	"unsure",
	"sure",
	"worried",
	"apethic",
	"ashamed",
	"defeated",
	"depressed",
	"desperate",
	"despondent",
	"discouraged",
	"forlorn",
	"hopeless",
	"hurt",
	"inferior",
	"insecure",
	"lonely",
	"misunderstood",
	"afraid",
	"anxious",
	"fearful",
	"helpless",
	"hesitant",
	"powerless",
	"resentful",
	"annoyed",
	"agitated",
	"disgusted",
	"outraged",
	"furious",
	"seething",
	"livid",
	"bitter",
	"timid",
	"tense",
	"threatened",
	"frightened",
	"intimidated",
	"horrified",
	"terrified",
	"troubled",
	"perplexed",
	"disoriented",
	"stunned",
	"shocked",
	"trapped",
	"frozen",
	"hysterical",
	"paralyzed",
	"down",
	"gloomy",
	"unhappy",
	"awful",
	"distressed",
	"miserable",
	"heartbroken",
	"terrible",
	"crushed",
	"devestated",
	"thirsty",
	"hungry",
	"tired",
	"sore",
	"shaky",
	"sick",
	"ill",
	"impotent",
	"frail",
	"exhausted",
	"stressed",
	"fragile",
	"vulnerable",
	"defenseless",
	"curious",
	"clever",
	"inquisitive",
	"motivated",
	"stimulated",
	"active",
	"energetic",
	"intrigued",
	"engaged",
	"constructive",
	"productive",
	"creative",
	"eager",
	"bold",
	"artistic",
	"fascinated",
	"confident",
	"focused",
	"determined",
	"inspired",
	"inventive",
	"ambitious",
	"absorbed",
	"obsessed",
	"helpful",
	"attentive",
	"considerate",
	"loving",
	"relaxed",
	"glad",
	"amused",
	"cheerful",
	"comical",
	"silly",
	"optimistic",
	"alive",
	"delighted",
	"giggly",
	"spontaneous",
	"imaginative",
	"whimsical",
	"joyful",
	"spirited",
	"energized",
	"excited",
	"bouncy",
	"lively",
	"animated",
	"elated",
	"ecstatic",
	"flirtatious",
	"affectionate",
	"tender",
	"cuddly",
	"frisky",
	"romantic",
	"amorous",
	"aroused",
	"desirous",
	"stimulated",
	"passionate",
	"flustered",
	"pleased",
	"glad",
	"grateful",
	"content",
	"enthusiastic",
	"charmed",
	"jealous",
	"betrayed",
	"blissful",
	"fit",
	"lustful",
	"refreshed"
};

static unsigned int get_user_hash() {
	char *user = getenv(ENV_VAR);
	
	unsigned int result = 0;
	for (int i = 0; user[i] != '\0'; i++) {
		result += i * user[i];
	}
	
	return result;
}

static unsigned int get_day() {
	unsigned long epoch = time(NULL);
	unsigned int days = epoch / 86400;
	return days;
}

static unsigned int get_seed() {
	unsigned int user_hash = get_user_hash();
	unsigned int day = get_day();
	return user_hash * day;
}

int main(int argc, char *argv[]) {
	unsigned int seed = get_seed();
	srand(seed);
	int count = sizeof(feelings) / sizeof(char *);
	char *feeling = feelings[rand() % count];
	printf("%s\n", feeling);
	return 0;
}