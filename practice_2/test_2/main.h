struct linkstack
{
    char element;
    struct linkstack *next;
};
struct numberstack
{
    double element;
    struct numberstack *next;
};
struct single_number_count_stack
{
    int element;
    struct single_number_count_stack *next;
};

struct linkstack *stack_top_of_expression_input = NULL;//free
struct linkstack *stack_top_of_expression_input_reverse=NULL;//free

struct numberstack *top_of_number_stack=NULL;//free 
struct numberstack *top_of_opearator_stack=NULL;//free

//include accept expression functions
#include "./function/function_of_char_stack/accept_expression/function_push_char.c"
#include "./function/function_of_char_stack/accept_expression/function_input_expression.c"
#include "./function/function_of_char_stack/accept_expression/function_creat_reverse_stack.c"
#include "./function/function_of_char_stack/accept_expression/function_link_stack_print.c"

//include expression process functions
#include "./function/function_of_char_stack/expression_prossess/function_pop_char.c"
#include "./function/function_of_char_stack/expression_prossess/function_check_expression_correction.c"
#include "./function/function_of_char_stack/expression_prossess/function_convert_middle_bracket_to_small_bracket.c"

//include number stack functions
#include "function/function_of_number_stack/function_push_single_number_to_stack.c"
#include "function/function_of_number_stack/function_convert_single_stack_number_to_double_number.c"
#include "function/function_of_number_stack/function_push_number.c"
#include "function/function_of_number_stack/function_clear_single_number_stack.c"
#include "function/function_of_number_stack/function_convert_opeartor_to_minus.c"
#include "function/function_of_number_stack/function_convert_char_to_number_stack.c"

//include expression convert functions
#include"function/function_of_convert_expression/function_push_operate_number.c"
#include"function/function_of_convert_expression/function_pop_operate_number.c"
#include"function/function_of_convert_expression/calculate_two_number.c"
#include"function/function_of_convert_expression/function_convert_infix_to_postfix.c"
