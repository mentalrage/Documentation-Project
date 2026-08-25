** TARGET-REPORT-UID:0001DO **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0001DO] OptionPane source-quality report

Report-only B-agent pass for:

- Target: `source-3/project-documentation/by-memory/0x0053d820-0x0053e520.OptionPane.md`
- Required coverage note target: `source-3/project-documentation/by-memory/-coverage-report.md`
- Status: report created only. No target/support by-* docs were edited. `by-memory/-coverage-report.md` was not edited.

## Recommendation

Implement this as a split-first correction, not as one large emitted C++ body.

The current [UID:0001DO] page has enough evidence to clear the current 85/85 source gate, but it is not one source construct. It mixes the old `OptionPane` constructor, a non-deleting destructor helper, a vtable command handler, compiler switch dispatch data, an existing server-response callback child, an existing local packet sender child, and a raw server-update helper island. The stale "final C++ blank because source-quality names are unresolved" language should be replaced with a current gate analysis:

- Source route is valid through [UID:0000M7] `OptionPane` / `NexusTK/ui/dialogs/OptionPane.cpp`; [UID:0000M7] is `91/85`.
- Class route is valid through [UID:00009V] `OptionPane`; [UID:00009V] is `86/87`.
- Source-bearing children clear 85/85 when routed either to [UID:00009V] for methods or [UID:0000M7] for file-local helpers.
- The aggregate itself should become a non-emitting split index, like the existing `NewOptionPaneServerOptionHelpers` model, because it includes compiler switch data and child-owned helper ranges.

Recommended target metadata after implementation:

```text
COMPLETION:89
CONFIDENCE:90
CANONICAL_OWNER:0000M7
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

Implementation readiness: ready after splitting. First-draft C++ is ready for the constructor, source destructor, command handler, server-response callback, local packet sender, and raw helper children. Do not place first-draft C++ on [UID:0001DO] itself after it becomes the split index.

## Evidence checked

- Read current target [UID:0001DO] and support pages [UID:0000M7] `by-file/OptionPane.md`, [UID:00009V] `by-class/OptionPane.md`, [UID:000097] `by-class/NewOptionPane.md`.
- Read existing child pages [UID:0001DP] `0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse`, [UID:0001DQ] `0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B`, [UID:00023I] `0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers`, and [UID:00038F] `0x00542940-0x00542995.OptionPaneScalarDeletingDestructor`.
- Read sibling/shared option helper pages [UID:0001DX] `NewOptionPaneServerOptionHelpers`, [UID:0001DY] `SendOptionPacket11B`, [UID:0001DW] `NewOptionPane`, and [UID:0000TL] `SendOptionPacket11B_540E50`.
- Read global/support pages [UID:00028Q] `g_pConfig`, [UID:00028R] `g_pSoundManager`, [UID:0002XU] `g_pIconsPane`, [UID:0003FW] `RegistryConfigOptionStringData`, alias ledger, project structure, and inference guidance.
- Performed read-only PE/Capstone checks against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDA MCP was attempted at `127.0.0.1:13337` and was unavailable in this run. The conclusions below use local binary evidence plus current checked-in docs.

## Split plan

Recommended split inventory:

| Range | Proposed page | Owner/emitter | Reconstructable | C++ disposition |
|---|---|---|---|---|
| `0x0053d820-0x0053dd4f` | `OptionPaneConstructor` | [UID:00009V] | TRUE | Add first-draft constructor C++ |
| `0x0053dd50-0x0053dd6f` | `OptionPaneDestructor` or `OptionPaneNonDeletingDestructor` | [UID:00009V] | TRUE | Source destructor is empty; binary helper is compiler-shaped |
| `0x0053ddb0-0x0053e191` | `OptionPaneOnOptionCommand` | [UID:00009V] | TRUE | Add first-draft command-handler C++ |
| `0x0053e191-0x0053e1e0` | `OptionPaneOnOptionCommandDispatchData` or ignored switch data row | [UID:00009V] or none | FALSE | No C++; compiler switch dispatch table/selector bytes/alignment |
| `0x0053e1e0-0x0053e377` | existing [UID:0001DP] | [UID:00009V] | TRUE | Rename/describe as `OptionPane::OnServerOptionResponse`; add first-draft C++ |
| `0x0053e380-0x0053e3c1` | existing [UID:0001DQ] | [UID:0000M7] | TRUE | File-local `OptionPaneSendOptionPacket11B`; add first-draft C++ |
| `0x0053e3c1-0x0053e3d0` | existing ignored padding | none | FALSE | Keep ignored |
| `0x0053e3d0-0x0053e41b` | new `OptionPaneSendOptionPacket11BSubcommand63` | [UID:0000M7] | TRUE | File-local raw helper, no direct xrefs |
| `0x0053e41b-0x0053e420` | ignored padding | none | FALSE | Add/keep ignored padding |
| `0x0053e420-0x0053e520` | new `OptionPaneApplyServerOptionStates` | [UID:00009V] | TRUE | Raw method-shaped helper, no direct xrefs |

The existing [UID:00023I] page should become a non-emitting helper-island container after the two source-bearing raw helpers and the internal padding are split out.

## Names and fields

Resolved globals:

- `dword_67A7C8` is `g_pConfig`, not a generic option object.
- `dword_67A7D0` is `g_pSoundManager`. The current target wording that treats it as runtime option/control state should be removed.
- `dword_69B41C` is `g_pIconsPane`.

Recommended `g_pConfig` offset names from this pass:

| Offset | Best name / role | Evidence |
|---|---|---|
| `+0x28de32` | `m_showAllIcons` or icon display mode byte | Old command id 1 writes control id 6; calls `IconsPane` show-all/reduced helpers. |
| `+0x28de48` | `m_soundEffectsEnabled` | Existing docs and `MusicControlDialog` support identify `Sound`; old constructor mirrors it to `this+0x270`. |
| `+0x28de50` | `m_musicEnabled` or MIDI/music enabled byte | Old command id 1 writes it with sound-manager field `+4` and calls `0x005260b0/0x005260d0`. |
| `+0x28de75` | `m_mapMovementStatusOption` | Existing config page and old command/control id 8; stored as inverse of checked state. |
| `+0x28de5a` | `m_doubleClick` | Registry key `DoubleClick`; old control id 9. |
| `+0x28de5e` | `m_shadow` | Registry key `Shadow`; old control id 10. |
| `+0x28de76` | `m_seeThrough` | Registry key `SeeThrough`; old control id 11. |
| `+0x28de59` | `m_sayWithEnter` | Registry key `SayWithEnter`; old control id 12. |
| `+0x28de77` | `m_hearEmotions` | Registry key `HearEmotions`; old control id 13. |
| `+0x28de5d` | `m_legacyOption14Flag` / unresolved original name | Constructor initializes control id 14; no registry save/load name found in current docs or this pass. |
| `+0x28de58` | `m_mapEffect` | Registry key `MapEffect`; constructor initializes control id 15. |

Important caveat: the constructor initializes control ids 14 and 15 from `+0x28de5d` and `+0x28de58`, but the reviewed `OnOptionCommand` apply path only writes controls 8-13 back to config. Do not invent symmetric writes for controls 14/15 unless later IDA/source evidence proves them.

Recommended `OptionPane` fields:

- `this+0x1fc`: child/control lookup list when the full `OptionPane *this` is used. Existing code repeatedly calls its virtual slot `+0x10` with command/control ids.
- Adjusted secondary-subobject `this+0x15c`: the same child/control lookup list when the server-response vtable callback receives `this` adjusted by `-0xa0`.
- Full object `this+0x26c..+0x270`: five server option state bytes.
- Adjusted secondary-subobject `this+0x1cc..+0x1d0`: the same five server option state bytes as above, seen through the adjusted callback `this`.

This resolves the apparent two-block ambiguity: `+0x1cc..+0x1d0` and `+0x26c..+0x270` are the same logical `m_serverOptionBytes[5]` field under different `this` bases.

## Constructor

Range: `0x0053d820-0x0053dd4f`.

Key evidence:

- Calls `DialogPane` base constructor at `0x0049d8a0` with string/resource pointer `0x0062127c`, plus arguments `3` and `1`.
- Installs three `OptionPane` vtables: primary `0x00620c74`, secondary `0x00620cd4`, and tertiary `0x00620d04`.
- Copies `g_pConfig+0x28de48` into full object `this+0x270`, the fifth byte of `m_serverOptionBytes`.
- Reads `DLGOPT.EPD` through pointer data at `0x0066dee4`; support pages also document the paired `DLGOPT.PAL` resource data.
- Constructs and adds the old option controls, initializes control states through helper `0x00496110`, and allocates buttons with ids `0x3a..0x3d`.
- Initializes controls 2 and 3 through `g_pSoundManager` probes at `0x0057a3d0` and `0x0057a750`.
- Initializes control 6 through `g_pIconsPane` probe `0x004cf290`.
- Initializes controls 8-15 from `g_pConfig` offsets listed above.
- Sends an initial three-byte `0x011b` packet with option byte zero through `g_packetSender`/`0x00574bb0`.

Recommended constructor source shape after split:

```cpp
OptionPane::OptionPane()
    : DialogPane(L"Option", 3, true)
{
    m_serverOptionBytes[4] = g_pConfig->m_soundEffectsEnabled;

    LoadOptionDialogResources(g_pOptionPaneDlgOptEpd);
    CreateLegacyOptionControls();

    SetOptionChecked(2, !g_pSoundManager->IsMusicDisabled());
    SetOptionChecked(3, !g_pSoundManager->IsSoundEffectsDisabled());
    SetOptionChecked(6, !g_pIconsPane->IsReducedIconMode());
    SetOptionChecked(8, g_pConfig->m_mapMovementStatusOption == 0);
    SetOptionChecked(9, g_pConfig->m_doubleClick == 0);
    SetOptionChecked(10, g_pConfig->m_shadow == 0);
    SetOptionChecked(11, g_pConfig->m_seeThrough == 0);
    SetOptionChecked(12, g_pConfig->m_sayWithEnter == 0);
    SetOptionChecked(13, g_pConfig->m_hearEmotions == 0);
    SetOptionChecked(14, g_pConfig->m_legacyOption14Flag == 0);
    SetOptionChecked(15, g_pConfig->m_mapEffect == 0);

    AddLegacyOptionButtons();
    FinishDialogLayout();
    OptionPaneSendOptionPacket11B(0);
}
```

The helper names in this snippet are source-quality placeholders for repeated constructor setup blocks. The control ids, global names, and field offsets are evidence-backed.

## Destructor relationship

Range: `0x0053dd50-0x0053dd6f`.

The helper stores the three `OptionPane` vtables and jumps to base `DialogPane` teardown at `0x0049d9f0`. This is the non-deleting destructor body/compiler output for the source destructor. It should not be confused with [UID:00038F] `0x00542940`, which is the scalar deleting destructor ABI wrapper referenced by the primary vtable and adjustor thunks.

Recommended source-level C++ child:

```cpp
OptionPane::~OptionPane()
{
}
```

Recommended scalar-deleting destructor handling:

- Keep [UID:00038F] as a compiler ABI wrapper page.
- Do not emit handwritten source C++ for [UID:00038F].
- Document that [UID:00038F] is generated from the source destructor above, with optional delete through `0x004f4ac0`.

## Command handler and dispatch table

Command-handler range: `0x0053ddb0-0x0053e191`.

Dispatch data range: `0x0053e191-0x0053e1e0`.

Key evidence:

- `0x0053ddb0` has a `.rdata` vtable/data pointer at `0x00620cbc`.
- Function returns with `ret 8`; the first stack argument is the command/control id and the second is unused in the reviewed body. Recommended signature is `void OptionPane::OnOptionCommand(unsigned int commandId, ControlPane *sender)` until exact callback type is proven.
- Switch is compiled as `commandId - 1`, selector bytes at `0x0053e1c0`, jump table at `0x0053e194`, and alignment/data beginning at `0x0053e191`.
- Selector bytes for command ids 1-19 are:

```text
00 0a 01 02 03 0a 04 05 0a 0a 0a 0a 0a 0a 0a 06 07 08 09
```

Resolved command map:

| Command id | Action |
|---|---|
| `1` | Apply main legacy option selections, update config/sound/icons, save config, refresh map/UI. |
| `3` | Send inline five-byte `0x011b/0x63/0x0d/<state>` packet for control id 3. |
| `4` | Compare control id 4 to `m_serverOptionBytes[1]`; if changed send local code `5`. |
| `5` | Compare control id 5 to `m_serverOptionBytes[0]`; if changed send local code `6`. |
| `7` | Compare control id 7 to `m_serverOptionBytes[2]`; if changed send local code `4`. |
| `8` | Compare control id 8 to `m_serverOptionBytes[3]`; if changed send local code `9`. |
| `16` | Allocate and construct `SpellMacroDialog` at `0x0053e960`. |
| `17` | Allocate and construct `MacroDialog` at `0x0053e520`. |
| `18` | Allocate and construct `FriendListDialog` at `0x0053f2c0`. |
| `19` | Allocate and construct `ProfileDialog` at `0x0053f940`. |
| Other ids | Default/no-op. |

First-draft command-handler source:

```cpp
void OptionPane::OnOptionCommand(unsigned int commandId, ControlPane *sender)
{
    (void)sender;

    switch (commandId) {
    case 1:
        ApplyLegacyOptionSelections();
        break;

    case 3:
        OptionPaneSendOptionPacket11BSubcommand63(0x0d, IsOptionChecked(3));
        break;

    case 4:
        SendServerOptionIfChanged(4, 1, 5);
        break;

    case 5:
        SendServerOptionIfChanged(5, 0, 6);
        break;

    case 7:
        SendServerOptionIfChanged(7, 2, 4);
        break;

    case 8:
        SendServerOptionIfChanged(8, 3, 9);
        break;

    case 16:
        new SpellMacroDialog;
        break;

    case 17:
        new MacroDialog;
        break;

    case 18:
        new FriendListDialog;
        break;

    case 19:
        new ProfileDialog;
        break;
    }
}
```

The helper `ApplyLegacyOptionSelections` should preserve the proven side effects:

- Control 2 toggles music/MIDI path: `0x005260b0/0x005260d0`, `g_pSoundManager` calls `0x0057a400/0x0057a3e0`, `g_pConfig+0x28de50`, and `g_pSoundManager+4`.
- Control 3 toggles sound effects: `g_pSoundManager` calls `0x0057a760/0x0057a770`, `g_pConfig+0x28de48`, and `g_pSoundManager+5`.
- Control 6 toggles icons: `g_pConfig+0x28de32`, `g_pIconsPane` calls `0x004cf2a0/0x004cf2d0`.
- Controls 8-13 store inverse checked states into `+0x28de75`, `+0x28de5a`, `+0x28de5e`, `+0x28de76`, `+0x28de59`, and `+0x28de77`.
- It then calls the config save virtual slot `+0x0c` if `g_pConfig` is non-null, refreshes active map/UI state if globals are present, invalidates the dialog, and notifies through `0x00469180`.

The dispatch table child should be non-reconstructable/no-C++. It is compiler support for this switch, not source-owned handwritten data.

## Server response helper

Existing child: [UID:0001DP] `0x0053e1e0-0x0053e377`.

Recommended name and ownership: `OptionPane::OnServerOptionResponse` or `OptionPane::HandleServerOptionResponse`, owner/emitter [UID:00009V].

Key evidence:

- Vtable/data pointer at `.rdata 0x00620ce4`.
- No direct code callers, consistent with virtual callback dispatch.
- Payload byte `0x21` opens localized alert id `61`.
- Payload byte `0x23` copies five payload bytes into the server option byte field and updates controls `5,4,7,8,3`.
- Apparent offsets `this+0x1cc..+0x1d0` and list `this+0x15c` are adjusted-this views of full-object `+0x26c..+0x270` and `+0x1fc`.

First-draft C++:

```cpp
bool OptionPane::OnServerOptionResponse(const unsigned char *payload)
{
    switch (payload[0]) {
    case 0x21:
        ShowLocalizedAlert(61);
        return true;

    case 0x23:
        ApplyServerOptionStates(payload + 1);
        return true;
    }

    return false;
}

void OptionPane::ApplyServerOptionStates(const unsigned char *state)
{
    for (int i = 0; i != 5; ++i)
        m_serverOptionBytes[i] = state[i];

    SetOptionChecked(5, state[0] == 0);
    SetOptionChecked(4, state[1] == 0);
    SetOptionChecked(7, state[2] == 0);
    SetOptionChecked(8, state[3] == 0);
    SetOptionChecked(3, state[4] == 0);
}
```

The exact callback parameter type should be adjusted to the existing server packet/block type when that type page is updated. The payload byte behavior is source-ready.

## Packet helpers

Existing child [UID:0001DQ] `0x0053e380-0x0053e3c1`:

- Four direct callers from the old command handler at `0x0053dfff`, `0x0053e033`, `0x0053e067`, and `0x0053e09b`.
- Sends a three-byte packet: opcode word `0x011b` plus one option-code byte.
- Uses [UID:0000Q5] `g_packetSender` / `0x00574bb0` with length `3`.
- This is physically distinct from the shared sibling [UID:0001DY] at `0x00540e50`.
- Best source name remains file-local `OptionPaneSendOptionPacket11B`.

First-draft C++:

```cpp
static void OptionPaneSendOptionPacket11B(unsigned char optionCode)
{
    unsigned char packet[4] = {};
    *reinterpret_cast<unsigned short *>(packet) = 0x011b;
    packet[2] = optionCode;
    g_packetSender->Send(packet, 3);
}
```

Raw helper `0x0053e3d0-0x0053e41b`:

- No direct rel32 callers and no VA/RVA/dword pointer refs were found in this pass.
- Body is function-shaped and ends `ret 8`.
- Sends `0x011b`, subcommand `0x63`, and two caller-provided bytes with length `5`.
- The command handler inlines the same pattern for command id 3 instead of calling this helper.
- Best-supported direction: retained file-local helper or missed indirect/raw-call metadata, not padding and not class-owned.

Recommended name: `OptionPaneSendOptionPacket11BSubcommand63`.

First-draft C++:

```cpp
static void OptionPaneSendOptionPacket11BSubcommand63(unsigned char first, unsigned char second)
{
    unsigned char packet[6] = {};
    *reinterpret_cast<unsigned short *>(packet) = 0x011b;
    packet[2] = 0x63;
    packet[3] = first;
    packet[4] = second;
    g_packetSender->Send(packet, 5);
}
```

Raw helper `0x0053e420-0x0053e520`:

- No direct rel32 callers and no VA/RVA/dword pointer refs were found in this pass.
- Method-shaped body on the full `OptionPane *this`.
- Copies payload bytes to full-object `m_serverOptionBytes[0..4]` at `+0x26c..+0x270` and updates controls through `+0x1fc`.
- Equivalent to the server-response `0x23` state-application branch, but using primary/full-object `this`.
- Best-supported direction: `OptionPane::ApplyServerOptionStates`, retained or raw no-xref helper.

This should be a class method child if split, with a no-direct-xref caveat and a moderate score cap. It should not stay as an unresolved passive blocker.

## Old/new source split

Recommended source placement remains:

```text
NexusTK/ui/dialogs/OptionPane.cpp
```

The old `OptionPane` and page-based `NewOptionPane` are sibling classes in the same source module. The old local `OptionPaneSendOptionPacket11B` at `0x0053e380` and the shared `SendOptionPacket11B` at `0x00540e50` should both remain under file owner [UID:0000M7], with explicit notes that they are duplicate-but-separate helper bodies. Do not move old `OptionPane` to `NewOptionPane`, `SelfLookPane`, `IconsPane`, `SoundManager`, or protocol/global owners; those are dependencies/consumers only.

## Recommended target changes

For [UID:0001DO] `0x0053d820-0x0053e520.OptionPane.md`:

1. Replace the current reconstructable aggregate stance with the split-index stance:

```text
COMPLETION:89
CONFIDENCE:90
CANONICAL_OWNER:0000M7
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

2. Replace the stale C++ blocker with:

```text
This page is now a reviewed split index for the old OptionPane cluster. It is not emitted as one C++ unit because the range combines source methods, compiler switch dispatch data, existing child-owned callbacks/helpers, raw no-xref helper bodies, and padding. Source-bearing children clear the current 85/85 gate through OptionPane class [UID:00009V] or OptionPane file [UID:0000M7]. First-draft C++ belongs on the child pages listed in the split inventory; the aggregate remains blank by split-index proof, not by unresolved below-95 naming.
```

3. Add the split inventory table from this report, including exact ranges and the existing child relationships.

4. Replace raw/global names:

```text
dword_67A7C8 -> g_pConfig
dword_67A7D0 -> g_pSoundManager
dword_69B41C -> g_pIconsPane
```

5. Add the adjusted-this field note:

```text
The server-option bytes at adjusted callback offsets +0x1cc..+0x1d0 are the same full-object field as +0x26c..+0x270. The control lookup/list at adjusted +0x15c is the same full-object member as +0x1fc.
```

6. Add the raw reachability note:

```text
Read-only PE/Capstone scan found no rel32 caller or VA/RVA/dword pointer route to raw starts 0x0053e3d0 or 0x0053e420. They are function-shaped retained/raw helpers, not padding. The first is best named file-local OptionPaneSendOptionPacket11BSubcommand63; the second is best named OptionPane::ApplyServerOptionStates.
```

## Recommended support-doc changes

For `by-class/OptionPane.md`, add/update:

```text
Old OptionPane source-quality refresh: B004 resolves dword_67A7C8 as g_pConfig, dword_67A7D0 as g_pSoundManager, and dword_69B41C as g_pIconsPane. The old constructor, source destructor, OnOptionCommand, server-response callback, and server-option state helpers clear the current 85/85 source gate through this class page and file parent [UID:0000M7]. The broad [UID:0001DO] range should be treated as a split index; first-draft C++ belongs on the source-bearing child pages, while compiler switch data and scalar deleting destructor wrappers remain no-C++ compiler output.
```

Add a field note:

```text
Known old OptionPane fields: full-object +0x1fc is the legacy child/control lookup list; full-object +0x26c..+0x270 is m_serverOptionBytes[5]. In the server-response vtable callback, the adjusted this pointer makes these appear as +0x15c and +0x1cc..+0x1d0.
```

Add method/source map:

```text
0x0053d820-0x0053dd4f OptionPane::OptionPane()
0x0053dd50-0x0053dd6f OptionPane::~OptionPane() non-deleting destructor body
0x0053ddb0-0x0053e191 OptionPane::OnOptionCommand(unsigned int commandId, ControlPane *sender)
0x0053e191-0x0053e1e0 compiler switch dispatch data for OnOptionCommand
0x0053e1e0-0x0053e377 OptionPane::OnServerOptionResponse / HandleServerOptionResponse
0x0053e420-0x0053e520 OptionPane::ApplyServerOptionStates raw no-xref helper
0x00542940-0x00542995 compiler scalar deleting destructor wrapper generated from OptionPane::~OptionPane()
```

For `by-file/OptionPane.md`, add/update:

```text
Old/new split: old OptionPane and page-based NewOptionPane remain sibling classes in NexusTK/ui/dialogs/OptionPane.cpp. The old local OptionPaneSendOptionPacket11B at 0x0053e380 and the shared SendOptionPacket11B at 0x00540e50 are duplicate-but-separate file-local packet helpers. The raw old helper at 0x0053e3d0 is best treated as file-local OptionPaneSendOptionPacket11BSubcommand63 despite no direct xrefs; the raw old helper at 0x0053e420 is best treated as OptionPane::ApplyServerOptionStates.
```

For [UID:0001DP], update owner/name and C++ readiness:

```text
Treat this as OptionPane::OnServerOptionResponse / HandleServerOptionResponse, not as a generic file helper. The vtable pointer at 0x00620ce4 supplies the callback route. The callback receives an adjusted this pointer, so +0x1cc..+0x1d0 maps to full-object OptionPane +0x26c..+0x270.
```

For [UID:0001DQ], replace the final-C++ blocker with:

```text
First-draft C++ is ready as a file-local OptionPaneSendOptionPacket11B(unsigned char optionCode). This helper clears the 85/85 gate through file parent [UID:0000M7]. Keep the duplicate-but-separate note for shared [UID:0001DY].
```

For [UID:00023I], convert to a non-emitting container after child splits:

```text
This page is a raw helper-island split index. Split 0x0053e3d0-0x0053e41b as file-local OptionPaneSendOptionPacket11BSubcommand63, ignore 0x0053e41b-0x0053e420 as padding, and split 0x0053e420-0x0053e520 as OptionPane::ApplyServerOptionStates. No aggregate C++ should be emitted.
```

For [UID:00028Q] `g_pConfig`, add the offset names in the table above, including the explicit unresolved caveat for `+0x28de5d`.

For [UID:00028R] `g_pSoundManager`, add:

```text
Old OptionPane uses g_pSoundManager for controls 2 and 3 in the constructor and command handler. It probes music/sound state at 0x0057a3d0 and 0x0057a750, toggles through 0x0057a400/0x0057a3e0 and 0x0057a760/0x0057a770, and mirrors enabled flags to sound-manager bytes +4 and +5.
```

For [UID:0002XU] `g_pIconsPane`, keep existing ownership and add only if missing:

```text
Old OptionPane control id 6 reads g_pIconsPane at 0x0053da72 and 0x0053dec2, probes reduced-icon state through 0x004cf290, and applies show-all/reduced modes through 0x004cf2a0/0x004cf2d0. IconsPane is a dependency, not the source owner for OptionPane.
```

## Validator needs

For an implementation callback, validate every touched/new doc from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0001DO-OptionPane-source-quality-removed.md](0001DO-OptionPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If new child docs are created, validate each new child with `--apply --queue-timeout 240` before validating `by-memory/-coverage-report.md` so TMP/new UID references resolve. If formal C++ is generated or target stats move, run:

> Executable block R002 was removed from this report and preserved verbatim in [0001DO-OptionPane-source-quality-removed.md](0001DO-OptionPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Exact pending coverage text

Do not edit `by-memory/-coverage-report.md` during this report-only task. Pending replacement for the existing [UID:0001DO] row:

```text
    - [UID:0001DO][0x0053d820-0x0053e520.OptionPane](by-memory/0x0053d820-0x0053e520.OptionPane.md) 0x0053d820-0x0053e520 | split-index/class-cluster | OptionPane : not_reconstructable : 89% : very strong : B004 source-quality pass converts the stale reconstructable old OptionPane aggregate into a non-emitting split index for the constructor, source destructor, OnOptionCommand switch, compiler dispatch data, server-response callback, local option-packet sender, and raw server-update helper island; read-only PE/Capstone evidence resolves dword_67A7C8 as g_pConfig, dword_67A7D0 as g_pSoundManager, dword_69B41C as g_pIconsPane, full-object server option bytes +0x26c..+0x270 as the same adjusted-this block seen at +0x1cc..+0x1d0, full-object control list +0x1fc as adjusted +0x15c, vtable dispatch for 0x0053ddb0 and 0x0053e1e0, direct old packet-helper callers at 0x0053dfff/0x0053e033/0x0053e067/0x0053e09b, no rel32 or pointer route to raw starts 0x0053e3d0 or 0x0053e420, and first-draft C++ readiness for source-bearing children only.
```

If the supervisor accepts the split implementation, also replace/update the existing child rows and add new rows after validator assigns UIDs. Exact text with `UID:TBD` placeholders:

```text
        - [UID:TBD][0x0053d820-0x0053dd4f.OptionPaneConstructor](by-memory/0x0053d820-0x0053dd4f.OptionPaneConstructor.md) 0x0053d820-0x0053dd4f | constructor | OptionPaneConstructor : reconstructable : 88% : very strong : Old OptionPane constructor through class owner/emitter [UID:00009V]; B004 PE/Capstone pass confirms DialogPane base setup, three OptionPane vtable installs, DLGOPT.EPD resource use, legacy option/control construction, g_pSoundManager/g_pIconsPane/g_pConfig initialization paths, server option byte +0x270 seed from g_pConfig+0x28de48, initial 0x011b option-request packet, and first-draft source C++ readiness with original helper/control names still below final-source certainty.
        - [UID:TBD][0x0053dd50-0x0053dd6f.OptionPaneDestructor](by-memory/0x0053dd50-0x0053dd6f.OptionPaneDestructor.md) 0x0053dd50-0x0053dd6f | destructor | OptionPaneDestructor : reconstructable : 87% : very strong : Non-deleting OptionPane destructor body generated from an empty source destructor; binary resets the three OptionPane vtables and jumps to DialogPane teardown at 0x0049d9f0, while scalar deleting destructor [UID:00038F] remains a separate compiler ABI wrapper.
        - [UID:TBD][0x0053ddb0-0x0053e191.OptionPaneOnOptionCommand](by-memory/0x0053ddb0-0x0053e191.OptionPaneOnOptionCommand.md) 0x0053ddb0-0x0053e191 | method | OptionPaneOnOptionCommand : reconstructable : 87% : very strong : Old OptionPane command handler through class owner/emitter [UID:00009V]; B004 resolves the switch selector map, ret-8 callback shape, option apply side effects, SoundManager/IconPane/Config routes, server option compare/send cases, macro/friend/profile dialog allocations, and first-draft C++ readiness with exact callback typedef and original helper names still caveated.
        - [UID:TBD][0x0053e191-0x0053e1e0.OptionPaneOnOptionCommandDispatchData](by-memory/0x0053e191-0x0053e1e0.OptionPaneOnOptionCommandDispatchData.md) 0x0053e191-0x0053e1e0 | compiler-switch-data | OptionPaneOnOptionCommandDispatchData : not_reconstructable : 88% : very strong : Compiler-generated switch alignment, jump table, selector bytes, and padding for OptionPane::OnOptionCommand; no source C++ should be emitted and ownership is explanatory through [UID:00009V].
    - [UID:0001DP][0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse](by-memory/0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse.md) 0x0053e1e0-0x0053e377 | method | OptionPaneServerOptionResponse : reconstructable : 88% : very strong : OptionPane server-response vtable callback through [UID:00009V]; B004 resolves payload bytes 0x21/0x23, alert id 61, adjusted-this field mapping from +0x1cc..+0x1d0 to full +0x26c..+0x270, adjusted control list +0x15c to full +0x1fc, control updates 5/4/7/8/3, vtable pointer 0x00620ce4, and first-draft C++ readiness with packet callback typedef caveat.
    - [UID:0001DQ][0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B](by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md) 0x0053e380-0x0053e3c1 | function | OptionPaneSendOptionPacket11B : reconstructable : 87% : very strong : Old OptionPane file-local three-byte 0x011b packet sender through [UID:0000M7]; B004 confirms four direct OnOptionCommand callers at 0x0053dfff/0x0053e033/0x0053e067/0x0053e09b, opcode plus one option-code byte, g_packetSender/0x00574bb0 length 3, duplicate-but-separate shared sibling [UID:0001DY], and first-draft C++ readiness.
    - [UID:00023I][0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers](by-memory/0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers.md) 0x0053e3d0-0x0053e520 | raw-helper-island | OptionPaneServerOptionUpdateHelpers : not_reconstructable : 88% : strong : Non-emitting split index for old OptionPane raw server-option helpers; B004 confirms 0x0053e3d0-0x0053e41b is file-local OptionPaneSendOptionPacket11BSubcommand63, 0x0053e41b-0x0053e420 is padding, 0x0053e420-0x0053e520 is OptionPane::ApplyServerOptionStates, and no rel32 caller or pointer route exists to either raw helper start.
        - [UID:TBD][0x0053e3d0-0x0053e41b.OptionPaneSendOptionPacket11BSubcommand63](by-memory/0x0053e3d0-0x0053e41b.OptionPaneSendOptionPacket11BSubcommand63.md) 0x0053e3d0-0x0053e41b | function | OptionPaneSendOptionPacket11BSubcommand63 : reconstructable : 86% : strong : Function-shaped old OptionPane file-local raw helper through [UID:0000M7] that sends 0x011b/0x63 plus two caller bytes with length 5 through g_packetSender; B004 found no direct rel32 caller or VA/RVA/dword pointer route, so retained/helper-metadata-gap caveat caps confidence but first-draft C++ is ready.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0053e41b-0x0053e420 | padding | OptionPane subcommand-63 sender to server-option state applier alignment : ignored : 100% : strong : Confirmed 0xcc alignment bytes between the raw sender helper ending at 0x0053e41b and the raw state applier starting at 0x0053e420.
        - [UID:TBD][0x0053e420-0x0053e520.OptionPaneApplyServerOptionStates](by-memory/0x0053e420-0x0053e520.OptionPaneApplyServerOptionStates.md) 0x0053e420-0x0053e520 | method | OptionPaneApplyServerOptionStates : reconstructable : 86% : strong : Function-shaped old OptionPane raw method through [UID:00009V] that copies five server option bytes into full-object +0x26c..+0x270 and updates controls 5/4/7/8/3 through +0x1fc; B004 found no direct rel32 caller or VA/RVA/dword pointer route, so retained/helper-metadata-gap caveat caps confidence but first-draft C++ is ready.
```

## Remaining issues

- IDA MCP was unavailable, so final implementation should let the validator and, if possible, an IDA pass confirm newly assigned child UIDs and any existing IDA labels before archiving.
- Exact original source names remain unproven for helper wrappers such as `SetOptionChecked`, `CreateLegacyOptionControls`, `ApplyLegacyOptionSelections`, `SendServerOptionIfChanged`, and the server packet callback typedef. The report provides best-supported descriptive names so these are no longer passive blockers.
- `g_pConfig+0x28de5d` remains unresolved by registry-key evidence. It is only safely describable as the old control id 14 legacy flag in this pass.
- Raw helpers `0x0053e3d0` and `0x0053e420` have source-shaped bodies but no direct caller/pointer route. Treat them as retained raw helpers or metadata gaps, not as padding and not as proof that the parent aggregate should emit C++.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0001DO-OptionPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"0001DO"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001DO-OptionPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0001DO-OptionPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001DO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
