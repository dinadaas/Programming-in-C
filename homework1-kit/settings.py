# ======= GENERAL SETTINGS: Adapt these per assignment =============
ASSIGNMENT = "Duke ECE/CS 250 Homework 1"
SEMESTER = "Fall 2017"
TEST_DIR = 'tests' # where test files are located
IS_GRADER = False # if true, we'll expect to see a 'points' parameter in test setup

SPIM_BINARY = 'spim' # location of spim executable (or just 'spim' if in path); only needed if mode is SPIM
LOGISIM_JAR = 'logisim_cli.jar' # location of logisim_cli.jar; only needed if mode is LOGISIM

# modes: 
#   EXECUTABLE - for C programs, etc.
#   SPIM       - run with command line spim
#   LOGISIM    - run with logisim command-line front-end
MODE = 'EXECUTABLE'

NON_ZERO_EXIT_STATUS_PENALTY = 0.75 # multiply score by this if exit status is non-zero
VALGRIND_PENALTY = 0.5 # multiply score by this if a valgrind test showed a leak

# ============= TEST SETUP ========================
suite_names = ('byseven', 'recurse', 'PizzaCalc')
suites = {
    "byseven": [
        { "desc": "n = 1", "args": ['1'], 'valgrind':True },
        { "desc": "n = 2", "args": ['2'], 'valgrind':True },
        { "desc": "n = 3", "args": ['3'], 'valgrind':True },
        { "desc": "n = 4", "args": ['4'], 'valgrind':True },
    ],
    "recurse": [
        { "desc": "n = 1", "args": ['1'], 'valgrind':True },
        { "desc": "n = 2", "args": ['2'], 'valgrind':True },
        { "desc": "n = 3", "args": ['3'], 'valgrind':True },
        { "desc": "n = 4", "args": ['4'], 'valgrind':True },
    ],
    "PizzaCalc": [
        { "desc": "One pizza",                     "args": ['tests/PizzaCalc_input_0.txt'], 'diff': hoopstat_diff, 'valgrind':True },
        { "desc": "Two pizzas, in order",          "args": ['tests/PizzaCalc_input_1.txt'], 'diff': hoopstat_diff, 'valgrind':True },
        { "desc": "Two pizzas, out of order",      "args": ['tests/PizzaCalc_input_2.txt'], 'diff': hoopstat_diff, 'valgrind':True },
        { "desc": "Six pizzas",                    "args": ['tests/PizzaCalc_input_3.txt'], 'diff': hoopstat_diff, 'valgrind':True },
        { "desc": "Don't print after DONE",        "args": ['tests/PizzaCalc_input_4.txt'], 'diff': hoopstat_diff, 'valgrind':True },
        { "desc": "Check for 0.00 in diameter",    "args": ['tests/PizzaCalc_input_5.txt'], 'diff': hoopstat_diff, 'valgrind':True },
        { "desc": "Check for 0.00 in price",       "args": ['tests/PizzaCalc_input_6.txt'], 'diff': hoopstat_diff, 'valgrind':True },
        { "desc": "100 pizzas",                    "args": ['tests/PizzaCalc_input_7.txt'], 'diff': hoopstat_diff, 'valgrind':True },
        { "desc": "Correct output on empty file",  "args": ['tests/PizzaCalc_input_8.txt'], 'diff': hoopstat_diff, 'valgrind':True },
    ]
}
