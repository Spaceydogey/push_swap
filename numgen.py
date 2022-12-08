# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    numgen.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 10:57:13 by hdelmas           #+#    #+#              #
#    Updated: 2022/12/08 10:57:19 by hdelmas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import random
n = int(input())
lst = []
for i in range(n):
    rand = random.randint(0,n)
    while (rand in lst):
        rand = random.randint(0,n)
    lst.append(rand)
for i in lst:
    print(i, end = ' ')
