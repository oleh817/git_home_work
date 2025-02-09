#!/bin/bash

depth=1
recursively=false
# Display the help message
display_help() {
    echo "Usage: $0 path_to_directory [-r] [-h]"
    echo
    echo "This script finds and lists executable files and soft links in the specified directory."
    echo "If no directory is provided, the current directory will be used."
    echo
    echo "Options:"
    echo "  -h      Display this help message"
    echo "  -r      Search recursively"
}

# Check the input arguments and set necessary variables
check_input_arguments() {
    if [ "$1" == "-h" ]; then
        display_help
        exit 0
    fi

    if [ $# -gt 2 ]; then
        echo "Error: Too many arguments."
        exit 1
    fi
    if [ $# -eq 0 ]; then
        directory="$PWD"
        echo "The directory was not provided, so the current one will be used instead: $directory"
    elif [ ! -d "$1" ]; then
        echo "Error: '$1' is not a valid directory."
        exit 1
    else
        directory="$1"
        echo "The directory provided: $directory"
    fi
    if [ "$2" == "-r" ]; then
        recursively=true
        echo "Searching recursively."
    fi
}




# List executable files in the specified directory
list_executable_files() {
    # Find all executable files
    if [ "$recursively" == false ]; then
        all_executable_files_from_dir=$(find "$directory" -maxdepth "$depth" -type f -perm +111)
    else
        all_executable_files_from_dir=$(find "$directory" -type f -perm +111)
    fi

    if [ -n "$all_executable_files_from_dir" ]; then
        echo  # Add empty line before printing
        for file_name in $all_executable_files_from_dir; do
            echo "File $file_name is executable"
        done
        echo  # Add empty line after printing
    else
        echo "No executable files found."
    fi
}

# List soft links in the specified directory
list_soft_links() {
    # Find all soft links
    if [ "$recursively" == false ]; then
        all_soft_links_in_dir=$(find "$directory" -maxdepth "$depth" -type l)
    else
        all_soft_links_in_dir=$(find "$directory" -type l)
    fi

    if [ -n "$all_soft_links_in_dir" ]; then
        echo  # Add empty line before printing
        for file_name in $all_soft_links_in_dir; do
            echo "File $file_name is a soft link"
        done
        echo  # Add empty line after printing
    else
        echo "No soft links found."
    fi
}

# Process the input arguments and run the functions
check_input_arguments "$@"
if [ "$1" != "-h" ]; then
    list_executable_files "$directory"
    list_soft_links "$directory"
fi
