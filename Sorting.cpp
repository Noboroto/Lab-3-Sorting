#include "Command.h"


int main (int32_t argc, char** argv)
{
    if (argc < 5)
    {
        PrintError("Not enough parameters!");
        return 0;
    }

    if ((string)argv[1] == "-a")
    {
        int8_t algo_index = GetSortIndex(argv[2]);
        if (algo_index < 0)
        {
            PrintError("Invalid algorithm!");
            return 0;
        }

        //Command 1 checker
        if (!IsNumber(argv[3]))
        {
            int8_t output_parameter = GetOutpuParameterIndex(argv[4]);
            if (output_parameter < 0)
            {
                PrintError("Invalid output parameters!");
                return 0;
            }
            Command_1(algo_index, argv[3], output_parameter);
        }
        // Command 2 checker
        else if (argc == 6)
        {
            int8_t output_parameter = GetOutpuParameterIndex(argv[5]);
            int8_t input_order = GetInputOrderIndex(argv[4]);
            int32_t input_size = GetIntFromString(argv[3]);
            if (output_parameter < 0)
            {
                PrintError("Invalid output parameters!");
                return 0;
            }
            if (input_order < 0)
            {
                PrintError("Invalid intput order!");
                return 0;
            }
            if (input_size < 0)
            {
                PrintError("Invalid intput size!");
                return 0;
            }
            Command_2(algo_index, input_size, input_order, output_parameter);
        }

        // Command 3 checker
        else if (argc == 5)
        {
            int32_t input_size = GetIntFromString(argv[3]);
            int8_t output_parameter = GetOutpuParameterIndex(argv[4]);
            if (output_parameter < 0)
            {
                PrintError("Invalid output parameters!");
                return 0;
            }
            if (input_size < 0)
            {
                PrintError("Invalid intput size!");
                return 0;
            }
            Command_3(algo_index, input_size, output_parameter);
        }
        else 
        {
            PrintError("Too much parameter!");
        }
    }
    else if ((string)argv[1] == "-c")
    {
        int8_t first_index = GetSortIndex(argv[2]);
        if (first_index < 0)
        {
            PrintError("Invalid first algorithm!");
            return 0;
        }

        int8_t second_index = GetSortIndex(argv[3]);
        if (second_index < 0)
        {
            PrintError("Invalid second algorithm!");
            return 0;
        }

        // Command 4 checker
        if (argc == 5)
        {
            if (!IsNumber(argv[4]))
            {
                Command_4(first_index, second_index, argv[4]);
            }
        }
        // Command 5 checker
        else if (argc == 6)
        {
            int32_t input_size = GetIntFromString(argv[4]);
            if (input_size < 0)
            {
                PrintError("Invalid input size!");
            }

            int8_t input_order = GetInputOrderIndex(argv[5]);
            if (input_order < 0)
            {
                PrintError("Invalid input order!");
            }

            Command_5(first_index, second_index, input_size, input_order);
        }
        else
        {
            PrintError("Too much parameter!");
        }
    }
    else
    {
        PrintError("Wrong mode");
    }
    return 0;
}