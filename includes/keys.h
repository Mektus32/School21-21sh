/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 13:41:32 by ojessi            #+#    #+#             */
/*   Updated: 2020/01/18 13:41:43 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __linux__
/*
** keys to move cursor
*/
#  define LEFT_ARROW 4479771
#  define RIGHT_ARROW 4414235
#  define CTR_UP_ARROW 71696882162459
#  define CTR_DOWN_ARROW 72796393790235

/*
** keys to check history
*/
#  define UP_ARROW 4283163
#  define DOWN_ARROW 4348699

/*
** keys to copying text
** //TODO change on vim keys
*/
#  define CTR_A_LEFT_ARROW 7499541704577499
#  define CTR_A_RIGHT_ARROW 73895905418011
#  define CTR_A_UP_ARROW 71696882162459
#  define CTR_A_DOWN_ARROW 72796393790235

/*
** key to paste text
*/
#  define CTR_P 16

/*
** keys to movement according to
*/
#  define CTR_LEFT 74995417045787
#  define CTR_RIGHT 73895905418011

/*
** keys home/end
*/
#  define HOME 4741916
#  define END 4610843
# elif __APPLE__
/*
** keys to move cursor
*/
#  define LEFT_ARROW 4479771
#  define RIGHT_ARROW 4414235
#  define CTR_UP_ARROW 1096489755
#  define CTR_DOWN_ARROW 1113266971

/*
** keys to check history
*/
#  define UP_ARROW 4283163
#  define DOWN_ARROW 4348699

/*
** keys to copying text
*/
#  define CTR_H 39371
#  define CTR_J 8816866
#  define CTR_K 39627
#  define CTR_L 44226

/*
** key to paste text
*/
#  define CTR_P 32975

/*
** keys to movement according to
*/
#  define CTR_LEFT 1146821403
#  define CTR_RIGHT 1130044187

/*
** keys home/end
*/
#  define HOME 4741916
#  define END 4610843
# endif
#endif
