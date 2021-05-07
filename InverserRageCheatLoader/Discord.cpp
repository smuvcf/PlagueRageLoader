#include "Discord.h"

void Discord::Initialize()
{
	DiscordEventHandlers Handle;
	memset(&Handle, 0, sizeof(Handle));
	Discord_Initialize("805101021293838336",&Handle ,1, NULL); // api key
}
void Discord::Update()
{
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.state = "Plague FREE FN Cheat";
    discordPresence.details = "discord.gg/X2C3pDQhMX";
  //  discordPresence.startTimestamp = 1; //time steps idk how it work tho atm
    discordPresence.largeImageText = "Plague FREE FN Cheat";
    discordPresence.largeImageKey = "ic";
    discordPresence.smallImageKey = "ic";
    Discord_UpdatePresence(&discordPresence);
}