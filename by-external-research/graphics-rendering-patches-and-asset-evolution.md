*** UID:0000GW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Graphics, Rendering, Patches, And Asset Evolution

Research date: 2026-05-24

Confidence: medium. Archive reports are dated fan/news records, often quoting official notes. Treat as external timeline evidence and string/resource leads.

Scope: public archive references to client rendering, patching, screenshots, equipment graphics, map tiles, animation fixes, and asset database evolution.

## Official Client Baseline

Observed:

- Current official download page lists `Nexus TK 7.52 (227MB)` and a minimum resolution of `1024x768`. Source: [official download page](https://www.nexustk.com/download_2.html).
- Current official download page provides updater repair paths and runtime dependency guidance for .NET Framework 3.5 and Visual C++ 2010 redistributable errors. Source: [official download page](https://www.nexustk.com/download_2.html).
- Official Basic Keys document screenshot controls: Scroll Lock for PNG, Shift+Scroll Lock for BMP, and Ctrl+Shift+3 for BMP. Source: [official Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys).

Reverse-engineering leads:

- Search for screenshot file format handling, Screenshot folder paths, 1024x768 checks, updater executable names, and runtime error strings.

## Late 2005 / Early 2006: High-Resolution Transition

Observed:

- December 2005 Nexus Atlas archive says a coming patch would fix clan banks, make high-resolution client text color customizable, add missing bow-shooting body animations, update some armors to high-resolution graphics, fix black bodies in the low-resolution client, preserve lighting when toggling effects, fix background music, fix worn armor right-click `Value: 0`, and add mouse-left-click auto-walking as a Shift+F12 toggle. Source: [December 2005 archive](https://www.nexusatlas.com/archives/mainpage-archive-12-2005.php).
- January 2006 Nexus Atlas archive says the official website was redesigned to match new client graphics and include new player guide content, path guide content, screenshots, DirectX link, and planned weapons/armor/items/monsters/maps/skills listing. Source: [January 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-1-2006.php).
- January 2006 archive also reports `Nexus 6.59` auto-patch changes: high-resolution emotions/actions, equipment display fixes, low-resolution `Control-w` crash fix, walk-blocking fixes, text color dialog button fixes, clan bank viewing, updated high-resolution death graphic, map tile fixes, carnage host alive-count visibility, and visual updates for rings/subpath items. Source: [January 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-1-2006.php).

Reverse-engineering leads:

- Search for high/low resolution rendering branches and option flags.
- Search for `Shift+F12`, auto-walking, effects/lighting toggles, music toggles, text color dialog, right-click item value formatting, clan bank, death graphic, and animation table references.
- Equipment bugs described in the patch notes point to paper-doll composition by facing/direction, body-part overlays, and gender/path-specific armor graphics.

## Screenshot And Client Directory Notes

Observed:

- January 2006 archive says official screenshot submissions used Scroll Lock; Shift+Scroll Lock created BMP screenshots on Windows XP while plain Scroll Lock created lower-quality JPG screenshots in that report's wording. Source: [January 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-1-2006.php).
- March 2008 archive warns that if auto-patch fails and the user removes Nexus for a full installation, they should move the `Screenshots` folder out of the `NexusTK` directory or screenshots will be deleted. Source: [March 2008 archive](https://www.nexusatlas.com/archives/mainpage-archive-3-2008.php).
- Official current help says screenshot keys now produce PNG/BMP outputs. Source: [official Basic Keys](https://help.nexustk.com/wiki/wiki/7/basic-keys).

Reverse-engineering leads:

- Screenshot format behavior may vary by client era. Do not assume modern PNG behavior applies to older binaries.
- Search for `Screenshots`, `NexusTK`, `.bmp`, `.jpg`, `.png`, and Scroll Lock handling.

## Item, Armor, And Database Presentation Evolution

Observed:

- January 2003 archive mentions fresh face graphics and new weapon/armor/item images for upcoming quests/events. Source: [January 2003 archive](https://www.nexusatlas.com/archives/mainpage-archive-1-2003.php).
- January 2006 and December 2005 archives describe armor/equipment graphic corrections and high-resolution updates. Sources: [January 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-1-2006.php), [December 2005 archive](https://www.nexusatlas.com/archives/mainpage-archive-12-2005.php).
- March 2008 archive reports a new Nexus Atlas item database section, replacing older NeX-Files item lists for active updates. It also reports database search support for armor, weapons, and monsters. Source: [March 2008 archive](https://www.nexusatlas.com/archives/mainpage-archive-3-2008.php).
- March 2008 archive includes recurring item-shop and event graphic updates, including hairstyle, head item, tunic, garb/skirt, pirate outfit, and gown color variants. Source: [March 2008 archive](https://www.nexusatlas.com/archives/mainpage-archive-3-2008.php).

Reverse-engineering leads:

- Search for face/portrait graphics, equipment color variants, item-shop wearable categories, and item database field labels.
- Resource churn across patches suggests old/new assets may coexist in DATs or patches, especially if compatibility with low-resolution graphics remained.

## Map Tiles, Collision, And Event Map Assets

Observed:

- January 2006 archive reports map tile fixes and walk-blocking fixes in the 6.59 patch. Source: [January 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-1-2006.php).
- March 2008 archive says a patch changed the Tree of Reflections graphic and implied many new graphics were added. Source: [March 2008 archive](https://www.nexusatlas.com/archives/mainpage-archive-3-2008.php).
- May 2006 archive says Nexus Atlas's Woodlands map completed a map project that began with the Vortex release week in June 2003. Source: [May 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-5-2006.php).

Reverse-engineering leads:

- Search for tile collision/walkability data, map tile IDs, event map asset injection, and Tree of Reflections resources.
- If the client owns map collision locally, walk-blocking patch notes may correspond to DAT map/tile attributes.

## Client Patch Delivery And Admin/Elevation Notes

Observed:

- Nexus Atlas archive reports multiple auto-patch events, including Nexus 6.59 and 6.90. Sources: [January 2006 archive](https://www.nexusatlas.com/archives/mainpage-archive-1-2006.php), [April 2011 archive](https://www.nexusatlas.com/archives/mainpage-archive-4-2011.php).
- April 2011 archive says Windows Vista/7 users should run NexusTK as administrator if the client auto-patches to 6.90. Source: [April 2011 archive](https://www.nexusatlas.com/archives/mainpage-archive-4-2011.php).
- Current official download page supplies current updater repair downloads. Source: [official download page](https://www.nexustk.com/download_2.html).

Reverse-engineering leads:

- Search for updater file paths, write-permission errors, patch manifest/parsing code, and version string checks.
- If local target includes updater code, version strings such as `6.59`, `6.90`, or `7.52` may not be in the game binary itself but can seed resource/package searches.

## Open-Question Resolution Notes 2026-05-24

- Rendering-era matching remains local, but public anchors are stronger now: 2003 5.x-style client requirements, 2005-2006 high/low-resolution 6.5/6.59 transition, 2011 Nexus 6.90, and current 7.52 with 1024x768 minimum.
- High/low asset implementation remains unresolved. Public 6.5/6.59 sources prove separate high-resolution and low-resolution behavior/bugs, but not whether assets are separate resource sets, generated variants, or renderer branches.
- Screenshot formats are era-specific: current Basic Keys says PNG for Scroll Lock and BMP for Shift+Scroll Lock / Ctrl+Shift+3, while 2006 archive evidence describes JPG/BMP-era behavior. Treat screenshot output as a versioned behavior.
- Map collision/tile blocking remains unresolved. January 2006 walk-blocking and map-tile fixes are good leads, but public notes do not prove whether blocking data is local, server-side, or mixed.

## Open Questions

- Which rendering era matches the target binary: pre-6.x, 6.x high-resolution transition, or later 7.x?
- Are high/low-resolution sprites separate resource sets or generated from shared assets?
- Does the target client own map collision/tile blocking locally?
- Are screenshot formats and output paths hard-coded or option-driven?
