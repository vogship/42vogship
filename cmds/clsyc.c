/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clsyc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:39:21 by amenadue          #+#    #+#             */
/*   Updated: 2022/08/31 21:18:37 by amenadue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libvg/vogship.h"

const int	g_cmdindex = 1;

int	main(void)
{
	#ifdef OSX
	
	int	freeS;
	char c;
	t_str auto_fclean_pref = vg_get_pref("auto_fclean", "unknown");
	
	freeS = ft_atoi(vg_run("df -Hk ~ | grep -oE '[0-9]+ +[0-9]+%'"));
	if (!ft_strncmp(auto_fclean_pref, "false", 6))
	{
		c = 'n';
	}
	else if (!ft_strncmp(auto_fclean_pref, "true", 5))
	{
		c = 'y';
	}
	else
	{
		ft_printf("Would to like to run a deep clean?\n");
		ft_printf("(This has a very slim chance of unexpected behaviour)\n");
		ft_printf("y: yes | n: no | a: always, no need to ask | d: no and don't ever me ask again\n");
		ft_printf("[Y|n|a|d] "); scanf("%c", &c);
	}

	vg_runp("rm -rf '~/Library/Caches/*'");

	if (c == 'a' || c == 'A')
		vg_set_pref("auto_fclean", "true");
	else if (c == 'd' || c == 'D')
		vg_set_pref("auto_fclean", "false");
	if (c != 'n' && c != 'N' && c != 'd' && c != 'D')
	{
		/* Thanks to 𝒐𝒃𝒐𝒖𝒚𝒌𝒐𝒖 for writing the shell version at https://github.com/ombhd/Cleaner_42/blob/master/Cleaner_42.sh */
		vg_runp("rm -rf '~/Library/*.42'");
		vg_runp("rm -rf '~/*.42'");
		vg_runp("rm -rf '~/Library/Application Support/Slack/Service Worker/CacheStorage/*'");
		vg_runp("rm -rf '~/Library/Application Support/Code/User/workspaceStorage/*'");
		vg_runp("rm -rf '~/Library/Application Support/discord/Cache/*'");
		vg_runp("rm -rf '~/Library/Application Support/discord/Code Cache/*'");
		vg_runp("rm -rf '~/Library/Application Support/Google/Chrome/Profile [0-9]/Service Worker/CacheStorage/*'");
		vg_runp("rm -rf '~/Library/Application Support/Google/Chrome/Default/Service Worker/CacheStorage/*'");
		vg_runp("rm -rf '~/Library/Application Support/Google/Chrome/Profile [0-9]/Application Cache/*'");
		vg_runp("rm -rf '~/Library/Application Support/Google/Chrome/Default/Application Cache/*'");

		vg_runp("find ~/Desktop -name .DS_Store -depth -exec /bin/rm {} \\; ");

		vg_runp("rm -rf '~/Library/Application Support/Chromium/Default/File System'");
		vg_runp("rm -rf '~/Library/Application Support/Chromium/Profile [0-9]/File System'");
		vg_runp("rm -rf '~/Library/Application Support/Google/Chrome/Default/File System'");
		vg_runp("rm -rf '~/Library/Application Support/Google/Chrome/Profile [0-9]/File System'");
	}
	ft_printf("\e[92mBefore Cleanup: %d Available\e[0m\n", freeS);
	freeS = ft_atoi(vg_run("df -Hk ~ | grep -oE '[0-9]+ +[0-9]+%'"));
	ft_printf("\e[92mAfter Cleanup: %d Available\e[0m\n", freeS);
	return (0);
	
	#else

	ft_printf("\e[94mCommand is only for Campus Machines.\e[0m\n");

	#endif
}
