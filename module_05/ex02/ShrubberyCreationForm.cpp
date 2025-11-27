#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)  : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm constructor is called" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) : AForm(form)
{
	std::cout << "ShrubberyCreationForm copy constructor is called" << std::endl;
	this->_target = form._target;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor is called for " << this->getName() << std::endl;
}

// Getters and Setters
std::string &ShrubberyCreationForm::getTarget()
{
	return (this->_target);
}
	
// Member functions
bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (getSignedStatus() == false)
		throw FormIsNotSigned();
	if (executor.getGrade() >= getGradeToExecute())
		throw ExecutorGradeTooLow();
	std::string file_name = this->_target + "_shrubbery";
	std::ofstream shrubbery_file(file_name);
	if (!shrubbery_file.is_open())
	{
        std::cerr << "Error opening file: " << file_name << std::endl;
        throw ShrubberyFileError();
    }
	else
	{
		shrubbery_file << \
		"                                                                        #                                                                          \n" \
		<< "                                                                       #                                                                              \n" \
		<< "                                                                      #                                                                               \n" \
		<< "                                                                     #                                                                                \n" \
		<< "                                                                     #                            +                                                   \n" \
		<< "                                                                     #    #*     #               +*+                                                  \n" \
		<< "                                                      #              #                       =    *                                                   \n" \
		<< "                           ++    #              +++*%  #     *  +*   #   #                   +=   #                                                   \n" \
		<< "                          ***#++             #+*****     #    #*+    #  #      #             =+# %**+        #                                        \n" \
		<< "                                  #                       ##         ###   #  #                #    +                                                 \n" \
		<< "                             #     %            #              ##    ## =   #    *++    #     #                 *+     # -==+++                       \n" \
		<< "                              #     #             #              ##  ##=+=   #    *#+#        #  #*+#           **    #  -==                          \n" \
		<< "                     +*+       ##     #    #       #               #%##=++= * #      #        #  +*+#            =  #                                 \n" \
		<< "                      **+        ##    #          ###                ## -*= #  #      #      #     *  #     *      #                                  \n" \
		<< "                      +**=         ##   #             ##***#*        ##  +- #   #            #               #   ##                                   \n" \
		<< "                        #           ##  #%             ##*           ##     #    #   #       #     #  ++      # #                                     \n" \
		<< "                        ###           ## #     #        ## #*   %    ##     #    #   *       #   #   =#=      ##     ==+                              \n" \
		<< "                       =++++  #*        ##        #      #    %#*######     # #  #          ##   #      **+  # #   +++==         +*+                  \n" \
		<< "                     +===       #        ##%          %###           ##     #    #   *      #    #  #+  +**##  * *+==-         *#**                   \n" \
		<< "                                 ###       ##    #++*     *          ##    ##    ##  #     ##   #    +    #    #              #*+*                    \n" \
		<< "                         #           %#*## ####    ***   %##         ##%   *      # ##     ##  #        ##    ##   ######                             \n" \
		<< "                        ==   +++#  %       # ##*    +*+    #*        ###   #      ###      # #%        ##    *###      =++=                           \n" \
		<< "                 #  #   =+=  ++*#= # *+        ##*      % * %*       ###  *% #     ##     #*#         ##    #%          =+=+=                         \n" \
		<< "      =+++=-       #  # =++=       #  *+        ##*    #  *+ %*      ### #%         ##   ##           #   ####            ==++    +*#*                \n" \
		<< "        =+++=           #++=                     ###      *   %*     #####    #      ####*           # ####   %#*                +**++                \n" \
		<< "       ##    -       #    +         #  ***        #*           ###   ####     #       ##            *###            %##    #   %## #                  \n" \
		<< "                   #  %     ##        %           ##   #         %## ###      #     ###        #**#%#                  #       #                      \n" \
		<< "                   %   ##**#####      *           ##   #          ######      #    ###########%%  *#                 +*+ *         # =+=              \n" \
		<< "       ===++++-  #              ##     #          ##   %             ###           ##       #    *####               *+   #        =++==              \n" \
		<< "        -===-  #                  ##   #           ## *              ###       #  ##    # #     ###    #*%                 #      =++=-               \n" \
		<< "     #                              ## #           ####  %           ####       #%#     #       #          %#                     --                  \n" \
		<< "   ##  #                      **      ##            ###  #           ####       %##   *        ##            ##                ##        **+          \n" \
		<< "  +**     #              ++#  **        ##           ##* #           ####       #*            ##                 ###        ##      =+= *+*+          \n" \
		<< "               #%      ***+     ####*#######          ###*           ####      %*    #      ###                          ##       =++===+*            \n" \
		<< "                 ##     #      #            ###        %##           ####      ##   %     ### #                       ##         =++=                 \n" \
		<< "               ##############                 #*       #%*          ####      ##  *%    ###                  %     ##          ##-*##%#####           \n" \
		<< "       *     ##              #######*          #*      # %*#        ####      %###    ##%#######       ##       ########**#####                       \n" \
		<< "       =+  #                     ## ##*         ##    #   %##       ####%     ##    *#%      #    *          ###               + #            **+     \n" \
		<< "    +*    #                     *%    ##        %#    *    %#*       ####     ##% ##%#    #   #           *##                 +*+   #         **      \n" \
		<< "   *+   #*                   *#%        ###      ##  %#     %#*#     #*###    ###*#%                    #####%%                *                      \n" \
		<< "     ##                 #                 ####*#  ## %#       %##     #*##%    #*#%                    ##     # *%                            ##      \n" \
		<< "  #  *         ++**** #                  %#**##%#**####        #####  #*###   ###%      #   +**+       #      %   ##    #    %      #     #           \n" \
		<< "    =# %      *****+#                #            %%###**##############**##% ###%      #  =***+       ##       #    #                    #            \n" \
		<< "    +*+    #                              ++#  *      ###           ###**#####%%      #   +*= *+    ###         =##* ####        #   ##               \n" \
		<< "    +*+       ####                    %       #         ##             ***###%%       *        ++ ###           #         ##    ###%                  \n" \
		<< "                   ####                  # ####%####%    ##*           #**##%%         #        ####                   #      # #                     \n" \
		<< "                        ####         +**              ######*%         #**#%%          ##      *#                     #     ##                        \n" \
		<< "                            ####     *+             *###    %#*        %**#%%          #     *######%         #       *    #                          \n" \
		<< "             #                 ####*###    ########          #%#*       **#%%          #   *#%        *##   #        ##*                              \n" \
		<< "               #               ##  ####*                       #%#*#    **##%#        # #*#%             ##        %#                                 \n" \
		<< "           =++#%% ##       #           ##*                       #%###  #*####       ###%#           %#    ###  %##                          =+=      \n" \
		<< "         +***+       *#####              #*                        ######*###########%#           %*           #*  ##%                      ++=       \n" \
		<< "        +*++                 *#%         ###    ==#     +**          ####*##########            ##           ###                       ### #      *+*+\n" \
		<< "                    **          ##    #######+***#** #                  #*#####            #%%%%###%%####%  ###                 ####              #   \n" \
		<< "             #####     %######***####%%#    ###         #   #**+        #######    #%##*****############%#####        ########         +**+           \n" \
		<< "       ###               %                    ####       #  #           ####### ####                      ##  #*####*#                ++++            \n" \
		<< "                       #                         ####       #           ##########                         %#       ##*#      ##*    %#*              \n" \
		<< "                    #                              ##*#       #         #######%                            %*                       #                \n" \
		<< "                  #            ###+++** ##          ##%#*      #%       ########                              %#             *   +++                  \n" \
		<< "                                ++****=                 %#**#   #%      ########                  +***          #           ++    =                   \n" \
		<< "               #                **++                       %##*# ##     ####### ###              =#*+              #*             #                   \n" \
		<< "                                                               %###############        #%    ###             +*++    #                                \n" \
		<< "                                                                    ###########          #       #%              #    #                               \n" \
		<< "                                                                       #*######        +*  ##***                 #+*+                                 \n" \
		<< "                                                                      ##*#####%             #                      ++*                                \n" \
		<< "                                                                      #**#####                                                                        \n" \
		<< "                                                                      #*######                                                                        \n" \
		<< "                                                                     #**######                                                                        \n" \
		<< "                                                                     #**#####                                                                         \n" \
		<< "                                                                     #*####%#                                                                         \n" \
		<< "                                                                    #**###%%#                                                                         \n" \
		<< "                                                                    #**###%%#                                                                         \n" \
		<< "                                                                    #**###%%#                                                                         \n" \
		<< "                                                                   #***##%%%                                                                          \n" \
		<< "                                                                   #***##%%%                                                                          \n" \
		<< "                                                                   #**###%%%                                                                          \n" \
		<< "                                                                   #**###%%%                                                                          \n" \
		<< "                                                                   #***##%%%                                                                          \n" \
		<< "                                                                   #**###%%%#                                                                         \n" \
		<< "                                                                   #**###%%%#                                                                         \n" \
		<< "                                                                   #**###%%%%                                                                         \n" \
		<< "                                                                   #**###%%%%#                                                                        \n" \
		<< "                                                                   ##*###%%%%%                                                                        \n" \
		<< "                                                                   ######%%%%%#                                                                       \n" \
		<< "                                                                   ######%%%%%%                                                                       \n" \
		<< "                                                                   ######%%%%%%#                                                                      \n" \
		<< "                                                                   %#####%%%%%%%                                                                      \n" \
		<< "                                                                   %#####%%%%%%%#                                                                     \n" \
		<< "                                                                   %#####%%%%%%%%                                                                     \n" \
		<< "                                                                   %#####%%%%%%%%                                                                     \n" \
		<< "                                                                   %#####%%%%%%%%#                                                                    \n" \
		<< "                                                                   %######%%%%%%%#                                                                    \n" \
		<< "                                                                   #########%%%%%#                                                                    \n" \
		<< "                                                                    ##############                                                                    " << std::endl;
        shrubbery_file.close();
		std::cout << "Execution of ShrubberyForm was succesfull. See created file." << std::endl;
		return (true);
	}
	return (false);
}

// Operators
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm copy assignment is called for ShrubberyCreationForm " << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream &os, ShrubberyCreationForm &form)
{
	os << BLUE << "-------- Form Info: --------\n" \
	<< "Form name: " << form.getName() << "\n" \
	<< "Grade to sign: " << form.getGradeToSign() << "\n" \
	<< "Grade to execute: " << form.getGradeToExecute() << "\n" \
	<< "Form signed: " << form.getSignedStatus() << "\n" \
	<< "Form target: " << form.getTarget() << "\n" \
	<< "----------------------------" << DEFAULT;
	return (os);
}
