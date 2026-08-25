** TARGET-REPORT-UID:00023K **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00023K - DialogPaneScalarDeletingDestructorIsland Ownership/Split Report

## Final Recommendation

Reclassify [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](../../../../../by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md) as a non-reconstructable split inventory, not a source-owning destructor page. I applied that recommendation to the parent page: `COMPLETION:90`, `CONFIDENCE:92`, `RECONSTRUCTABLE:FALSE`, `AUTOGEN_PARENT_UID` blank.

Create and keep the nine exact child pages created by B001-047. Each child is a single class-owned scalar deleting destructor wrapper with IDA-backed vtable/thunk ownership evidence. Assign only the two children whose direct class parents already clear the strict `85/85` gate:

| UID | Range | Owner decision | Score/parent |
| --- | --- | --- | --- |
| [UID:00038A][0x005426e0-0x00542735.FriendListDialogScalarDeletingDestructor](../../../../../by-memory/0x005426e0-0x00542735.FriendListDialogScalarDeletingDestructor.md) | `0x005426e0-0x00542735` | `FriendListDialog` proven; class/file gate not clear | `86/91`, parent blank |
| [UID:00038B][0x00542740-0x00542795.IntegrateMacroDialogScalarDeletingDestructor](../../../../../by-memory/0x00542740-0x00542795.IntegrateMacroDialogScalarDeletingDestructor.md) | `0x00542740-0x00542795` | `IntegrateMacroDialog` proven; direct class below completion gate | `86/91`, parent blank |
| [UID:00038C][0x005427a0-0x005427f5.MacroDialogScalarDeletingDestructor](../../../../../by-memory/0x005427a0-0x005427f5.MacroDialogScalarDeletingDestructor.md) | `0x005427a0-0x005427f5` | `MacroDialog` proven; direct class below gate | `86/91`, parent blank |
| [UID:00038D][0x00542800-0x00542855.NewMacroDialogScalarDeletingDestructor](../../../../../by-memory/0x00542800-0x00542855.NewMacroDialogScalarDeletingDestructor.md) | `0x00542800-0x00542855` | `NewMacroDialog` proven; direct class below gate | `86/91`, parent blank |
| [UID:00038E][0x00542860-0x00542933.NewOptionPaneScalarDeletingDestructor](../../../../../by-memory/0x00542860-0x00542933.NewOptionPaneScalarDeletingDestructor.md) | `0x00542860-0x00542933` | `NewOptionPane` proven; direct class below gate | `88/91`, parent blank |
| [UID:00038F][0x00542940-0x00542995.OptionPaneScalarDeletingDestructor](../../../../../by-memory/0x00542940-0x00542995.OptionPaneScalarDeletingDestructor.md) | `0x00542940-0x00542995` | `OptionPane` proven; direct class below gate | `86/91`, parent blank |
| [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](../../../../../by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md) | `0x005429a0-0x005429f5` | `ProfileDialog` proven; direct class clears gate | `86/91`, parent [UID:0000AU][ProfileDialog](../../../../../by-class/ProfileDialog.md) |
| [UID:00038H][0x00542a00-0x00542a55.SpellMacroDialogScalarDeletingDestructor](../../../../../by-memory/0x00542a00-0x00542a55.SpellMacroDialogScalarDeletingDestructor.md) | `0x00542a00-0x00542a55` | `SpellMacroDialog` proven; direct class below completion gate | `86/91`, parent blank |
| [UID:00038I][0x00542a60-0x00542ab5.TargetOptionDialogScalarDeletingDestructor](../../../../../by-memory/0x00542a60-0x00542ab5.TargetOptionDialogScalarDeletingDestructor.md) | `0x00542a60-0x00542ab5` | `TargetOptionDialog` proven; direct class clears gate | `86/91`, parent [UID:0000EE][TargetOptionDialog](../../../../../by-class/TargetOptionDialog.md) |

## Concrete Supervisor Actions

1. Accept the applied parent change for [UID:00023K]: `90/92`, `RECONSTRUCTABLE:FALSE`, parent blank.
2. Accept the nine new exact child pages [UID:00038A] through [UID:00038I].
3. Keep [UID:00038G] assigned to [UID:0000AU] and [UID:00038I] assigned to [UID:0000EE].
4. Leave [UID:00038A], [UID:00038B], [UID:00038C], [UID:00038D], [UID:00038E], [UID:00038F], and [UID:00038H] parent-blank until their direct class pages clear `85/85`; do not attach them to file-level parents as a shortcut.
5. Apply the coverage-report replacement below. I did not edit `by-memory/-coverage-report.md` because the temporary ban is active.
6. Optional follow-up: repair stale one-byte exclusive-end mentions in class pages after acquiring leases: `MacroDialog` `0x005427a0-0x005427f4` -> `0x005427a0-0x005427f5`; `NewMacroDialog` `0x00542800-0x00542854` -> `0x00542800-0x00542855`; `OptionPane` `0x00542940-0x00542994` -> `0x00542940-0x00542995`; `SpellMacroDialog` `0x00542a00-0x00542a54` -> `0x00542a00-0x00542a55`; `TargetOptionDialog` text `0x00542a60-0x00542ab4` -> half-open `0x00542a60-0x00542ab5`.

## Coverage Report Text For Supervisor

Placement: in `by-memory/-coverage-report.md`, replace the current single [UID:00023K] row between the padding rows `0x005426d5-0x005426e0` and `0x00542ab5-0x00542ac0`.

Current row to replace:

```markdown
    - [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md) 0x005426e0-0x00542ab5 | destructor-island | DialogPaneScalarDeletingDestructorIsland : reconstructable : 85% : strong : Batch 172 live IDA recheck reconfirms all nine modeled scalar deleting destructor wrappers, wrapper sizes including NewOptionPane `0xd3`/211, two adjustor-thunk code xrefs plus one vtable/data xref per wrapper, surrounding `0xcc` padding, and representative decompiled bodies for FriendListDialog, NewOptionPane, and TargetOptionDialog. Parent remains blank because the island is a source-declared/generated-binary multi-owner ABI aggregate; per-owner exact wrapper splits are required before assignment.
```

Replacement text:

```markdown
    - [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md) 0x005426e0-0x00542ab5 | split-inventory | DialogPaneScalarDeletingDestructorIsland : not_reconstructable : 90% : very strong : B001-047 split repair reclassified the broad mixed-owner ABI wrapper island as a non-emitting parent-blank inventory. Exact children [UID:00038A] through [UID:00038I] carry per-class scalar deleting destructor evidence and ownership routing; ProfileDialog and TargetOptionDialog children attach to direct class parents now, while FriendList/Macro/Option children remain parent-blank pending direct class pages clearing the strict 85/85 gate.
        - [UID:00038A][0x005426e0-0x00542735.FriendListDialogScalarDeletingDestructor](by-memory/0x005426e0-0x00542735.FriendListDialogScalarDeletingDestructor.md) 0x005426e0-0x00542735 | scalar-deleting-destructor | FriendListDialogScalarDeletingDestructor : reconstructable : 86% : very strong : Exact split child; owner proven by primary vtable `0x00620ee4`, adjustor thunks `0x005425b5`/`0x005425c0`, raw pointer locality, and class vtable stores. Parent blank until direct FriendListDialog documentation clears 85/85.
        - [UID:00038B][0x00542740-0x00542795.IntegrateMacroDialogScalarDeletingDestructor](by-memory/0x00542740-0x00542795.IntegrateMacroDialogScalarDeletingDestructor.md) 0x00542740-0x00542795 | scalar-deleting-destructor | IntegrateMacroDialogScalarDeletingDestructor : reconstructable : 86% : very strong : Exact split child; owner proven by primary vtable `0x00621130`, adjustor thunks `0x005425cb`/`0x005425d6`, raw pointer locality, and class vtable stores. Parent blank until direct IntegrateMacroDialog documentation clears 85/85.
        - [UID:00038C][0x005427a0-0x005427f5.MacroDialogScalarDeletingDestructor](by-memory/0x005427a0-0x005427f5.MacroDialogScalarDeletingDestructor.md) 0x005427a0-0x005427f5 | scalar-deleting-destructor | MacroDialogScalarDeletingDestructor : reconstructable : 86% : very strong : Exact split child; owner proven by primary vtable `0x00620d10`, adjustor thunks `0x005425e1`/`0x005425ec`, raw pointer locality, and class vtable stores. Parent blank until direct MacroDialog documentation clears 85/85.
        - [UID:00038D][0x00542800-0x00542855.NewMacroDialogScalarDeletingDestructor](by-memory/0x00542800-0x00542855.NewMacroDialogScalarDeletingDestructor.md) 0x00542800-0x00542855 | scalar-deleting-destructor | NewMacroDialogScalarDeletingDestructor : reconstructable : 86% : very strong : Exact split child; owner proven by primary vtable `0x00620e48`, adjustor thunks `0x005425f7`/`0x00542602`, raw pointer locality, and class vtable stores. Parent blank until direct NewMacroDialog documentation clears 85/85.
        - [UID:00038E][0x00542860-0x00542933.NewOptionPaneScalarDeletingDestructor](by-memory/0x00542860-0x00542933.NewOptionPaneScalarDeletingDestructor.md) 0x00542860-0x00542933 | scalar-deleting-destructor | NewOptionPaneScalarDeletingDestructor : reconstructable : 88% : very strong : Exact split child; owner proven by primary vtable `0x006210a4`, adjustor thunks `0x0054260d`/`0x00542618`, raw pointer locality, NewOptionPane vtable stores, four owned pointer releases through `0x00544690`, and teardown call `0x005450d0`. Parent blank until direct NewOptionPane documentation clears 85/85.
        - [UID:00038F][0x00542940-0x00542995.OptionPaneScalarDeletingDestructor](by-memory/0x00542940-0x00542995.OptionPaneScalarDeletingDestructor.md) 0x00542940-0x00542995 | scalar-deleting-destructor | OptionPaneScalarDeletingDestructor : reconstructable : 86% : very strong : Exact split child; owner proven by primary vtable `0x00620c74`, adjustor thunks `0x00542623`/`0x0054262e`, raw pointer locality, and class vtable stores. Parent blank until direct OptionPane documentation clears 85/85.
        - [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md) 0x005429a0-0x005429f5 | scalar-deleting-destructor | ProfileDialogScalarDeletingDestructor : reconstructable : 86% : very strong : Exact split child assigned to direct class parent [UID:0000AU]; owner proven by primary vtable `0x00620f80`, adjustor thunks `0x00542639`/`0x00542644`, raw pointer locality, and class vtable stores.
        - [UID:00038H][0x00542a00-0x00542a55.SpellMacroDialogScalarDeletingDestructor](by-memory/0x00542a00-0x00542a55.SpellMacroDialogScalarDeletingDestructor.md) 0x00542a00-0x00542a55 | scalar-deleting-destructor | SpellMacroDialogScalarDeletingDestructor : reconstructable : 86% : very strong : Exact split child; owner proven by primary vtable `0x00620dac`, adjustor thunks `0x0054264f`/`0x0054265a`, raw pointer locality, and class vtable stores. Parent blank until direct SpellMacroDialog documentation clears 85/85.
        - [UID:00038I][0x00542a60-0x00542ab5.TargetOptionDialogScalarDeletingDestructor](by-memory/0x00542a60-0x00542ab5.TargetOptionDialogScalarDeletingDestructor.md) 0x00542a60-0x00542ab5 | scalar-deleting-destructor | TargetOptionDialogScalarDeletingDestructor : reconstructable : 86% : very strong : Exact split child assigned to direct class parent [UID:0000EE]; owner proven by primary vtable `0x006211cc`, adjustor thunks `0x00542665`/`0x00542670`, raw pointer locality, and class vtable stores.
```

## Evidence And Research Log

### IDA Session

- IDA MCP endpoint was queried directly on 2026-06-11.
- IDB identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Live function map confirms:
  - `0x005426e0-0x00542735`, `0x00542740-0x00542795`, `0x005427a0-0x005427f5`, `0x00542800-0x00542855`, `0x00542940-0x00542995`, `0x005429a0-0x005429f5`, `0x00542a00-0x00542a55`, and `0x00542a60-0x00542ab5` are `0x55` bytes each.
  - `0x00542860-0x00542933` is `0xd3` bytes for `NewOptionPane`.
  - `tools/int_convert.py` verified `0x55` = 85, `0xd3` = 211, and `0xb` = 11.
  - `0x005426d5-0x005426e0` and `0x00542ab5-0x00542ac0` are `0xcc` padding, not function body.

### Per-Wrapper IDA Ownership Evidence

| Wrapper | Primary vtable data ref | Adjustor thunk refs | Raw pointer search result |
| --- | --- | --- | --- |
| `FriendListDialog` `0x005426e0` | `0x00620ee4` `??_7FriendListDialog@@6B@` | `0x005425b5`, `0x005425c0` tail to body via `0x005425bb`, `0x005425c6`; thunk data refs `0x00620f44`, `0x00620f74` | only xref-aware `.rdata` occurrence at `0x00620ee4` |
| `IntegrateMacroDialog` `0x00542740` | `0x00621130` `??_7IntegrateMacroDialog@@6B@` | `0x005425cb`, `0x005425d6` via `0x005425d1`, `0x005425dc`; data refs `0x00621190`, `0x006211c0` | only `0x00621130` |
| `MacroDialog` `0x005427a0` | `0x00620d10` `??_7MacroDialog@@6B@` | `0x005425e1`, `0x005425ec` via `0x005425e7`, `0x005425f2`; data refs `0x00620d70`, `0x00620da0` | only `0x00620d10` |
| `NewMacroDialog` `0x00542800` | `0x00620e48` `??_7NewMacroDialog@@6B@` | `0x005425f7`, `0x00542602` via `0x005425fd`, `0x00542608`; data refs `0x00620ea8`, `0x00620ed8` | only `0x00620e48` |
| `NewOptionPane` `0x00542860` | `0x006210a4` `??_7NewOptionPane@@6B@` | `0x0054260d`, `0x00542618` via `0x00542613`, `0x0054261e`; data refs `0x006210f4`, `0x00621124` | only `0x006210a4` |
| `OptionPane` `0x00542940` | `0x00620c74` `??_7OptionPane@@6B@` | `0x00542623`, `0x0054262e` via `0x00542629`, `0x00542634`; data refs `0x00620cd4`, `0x00620d04` | only `0x00620c74` |
| `ProfileDialog` `0x005429a0` | `0x00620f80` `??_7ProfileDialog@@6B@` | `0x00542639`, `0x00542644` via `0x0054263f`, `0x0054264a`; data refs `0x00620fe0`, `0x00621010` | only `0x00620f80` |
| `SpellMacroDialog` `0x00542a00` | `0x00620dac` `??_7SpellMacroDialog@@6B@` | `0x0054264f`, `0x0054265a` via `0x00542655`, `0x00542660`; data refs `0x00620e0c`, `0x00620e3c` | only `0x00620dac` |
| `TargetOptionDialog` `0x00542a60` | `0x006211cc` `??_7TargetOptionDialog@@6B@` | `0x00542665`, `0x00542670` via `0x0054266b`, `0x00542676`; data refs `0x0062122c`, `0x0062125c` | only `0x006211cc` |

### Decompilation Evidence

IDA decompilation shows eight standard wrappers reset the class primary/secondary/tertiary vtable pointers at object offsets `+0x00`, `+0xa0`, and `+0xa4`, call the shared DialogPane/base teardown target at `0x0049d9f0` (IDA currently labels it as `boost::exception::~exception`), then conditionally call delete helper `0x004f4ac0` when `(flags & 1) != 0` and `(flags & 4) == 0`.

`NewOptionPane` is larger and source-relevant inside the generated wrapper: it writes the `NewOptionPane` vtables, reads four pointer slots at `Block[1201]` through `Block[1204]`, calls `0x00544690` for each non-null slot, calls `0x005450d0(Block)`, then performs the same scalar-delete flag guard and `0x004f4ac0` call. That is why [UID:00038E] is `88/91` rather than the surrounding `86/91`.

### Documentation Evidence

- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](../../../../../by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md) already records the matching two adjustor thunks per class.
- [UID:0001Y1][MacroDialogFamilyVtables](../../../../../by-type/by-vtable/MacroDialogFamilyVtables.md) independently documents macro-dialog primary vtable slots matching `0x00542740`, `0x005427a0`, `0x00542800`, and `0x00542a00`.
- Direct owner pages and gate state checked:
  - [UID:00005J][FriendListDialog](../../../../../by-class/FriendListDialog.md) `80/88`, [UID:0000JN][FriendListDialog](../../../../../by-file/FriendListDialog.md) `84/82`.
  - [UID:00006L][IntegrateMacroDialog](../../../../../by-class/IntegrateMacroDialog.md) `82/88`, [UID:0000KY][MacroDialogs](../../../../../by-file/MacroDialogs.md) `88/85`.
  - [UID:00007I][MacroDialog](../../../../../by-class/MacroDialog.md) `80/84`, [UID:0000KY][MacroDialogs](../../../../../by-file/MacroDialogs.md) `88/85`.
  - [UID:000094][NewMacroDialog](../../../../../by-class/NewMacroDialog.md) `82/84`, [UID:0000KY][MacroDialogs](../../../../../by-file/MacroDialogs.md) `88/85`.
  - [UID:000097][NewOptionPane](../../../../../by-class/NewOptionPane.md) `84/82`, [UID:0000M7][OptionPane](../../../../../by-file/OptionPane.md) `91/85`.
  - [UID:00009V][OptionPane](../../../../../by-class/OptionPane.md) `84/82`, [UID:0000M7][OptionPane](../../../../../by-file/OptionPane.md) `91/85`.
  - [UID:0000AU][ProfileDialog](../../../../../by-class/ProfileDialog.md) `85/86`, [UID:0000MR][ProfileDialog](../../../../../by-file/ProfileDialog.md) `86/86`.
  - [UID:0000DP][SpellMacroDialog](../../../../../by-class/SpellMacroDialog.md) `80/86`, [UID:0000KY][MacroDialogs](../../../../../by-file/MacroDialogs.md) `88/85`.
  - [UID:0000EE][TargetOptionDialog](../../../../../by-class/TargetOptionDialog.md) `86/88`, [UID:0000OG][TargetOptionDialog](../../../../../by-file/TargetOptionDialog.md) `86/86`.

### Accepted And Rejected Owners

- Accepted: exact per-class ownership. The strongest owner evidence is the primary vtable slot plus the paired secondary/tertiary adjustor thunks and class-specific vtable stores in each wrapper.
- Accepted for immediate parent assignment: [UID:00038G] -> [UID:0000AU] and [UID:00038I] -> [UID:0000EE], because both direct class pages clear `85/85`.
- Rejected: assigning [UID:00023K] to `DialogPane`. The page is adjacent to DialogPane ABI glue, but the vtable slots and wrapper bodies name the derived classes; DialogPane is only common infrastructure/base teardown context.
- Rejected: assigning [UID:00023K] to `MacroDialogs`, `OptionPane`, `FriendListDialog`, `ProfileDialog`, or `TargetOptionDialog`. Any one of those would cover only a subset of the nine wrappers.
- Rejected: assigning child pages to file-level parents when the direct class pages are below gate. The file pages are useful source-family context, but by-structure ownership should not bypass an uncleared direct class owner.
- Rejected: creating a new source/source-file parent for the island. No IDA or documentation evidence suggests a handwritten source file containing all nine wrappers. The grouping is compiler/linker adjacency around destructor/vtable ABI output.

### Split And File Creation Implications

The exact child pages should remain as by-memory children. They are not a new source grouping; they are per-owner wrapper records that point back to existing source/class documentation. Likely source locations remain:

- Friend list wrapper -> FriendListDialog class/file family.
- Integrate/Macro/NewMacro/SpellMacro wrappers -> `MacroDialogs`.
- NewOption/Option wrappers -> `OptionPane`.
- Profile wrapper -> `ProfileDialog`.
- TargetOption wrapper -> `TargetOptionDialog`.

No broad `DialogPaneScalarDeletingDestructorIsland.cpp` or equivalent should be introduced.

### Low-Confidence Facts

- IDA's label for the shared base teardown target at `0x0049d9f0` is polluted as `boost::exception::~exception`; the call behavior is stable, but the final source-facing name should be derived from the owner/base hierarchy, not that label.
- The exact source expression that led MSVC to emit each scalar deleting destructor is inferred from MSVC ABI behavior. The generated wrapper bodies should not be treated as handwritten source.
- Seven child pages are intentionally parent-blank despite strong direct owner evidence, because direct class pages have not yet cleared the strict gate.

### Validation And Scope Notes

- Leases were acquired for the existing parent and all new child pages before metadata edits.
- New child UIDs were allocated with `python tools/validator.py --mode file --file <child> --uid-only --apply`.
- Header/registry updates were validated with file-scoped `--uid-only --apply`; UID link annotations were validated with file-scoped `--reference-only --apply`.
- The validator updated `tools/validator.ini` and `project-level/-auto-completion-stats.md`. It did not report a `by-memory/-coverage-report.md` update; the coverage report was not manually edited under the active ban.
- Documentation pages edited by B001-047: the parent [UID:00023K] and the nine new child pages [UID:00038A] through [UID:00038I]. No by-class or by-file owner pages were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00023K-DialogPaneScalarDeletingDestructorIsland.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"00023K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
