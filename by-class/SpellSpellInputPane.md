*** UID:0000DT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SpellSpellInputPane : public CharInputPane
{
public:
    SpellSpellInputPane();
    virtual ~SpellSpellInputPane();

    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnAccept();
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SpellSpellInputPane

## Status

- Confidence: very strong for behavior, vtable identity, current `SpellInputPanes` placement, accepted exact child method names, and generated `SpellManager`/`g_pSpellMan` rejection; medium-high for final project-wide local-player global/helper spellings.
- Likely source file: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- Address range: [UID:0001MO][0x005b6120-0x005b62c8.SpellSpellInputPane](by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md)
- Vtable page: [UID:0003HL][SpellSpellInputPaneVtables](by-type/by-vtable/SpellSpellInputPaneVtables.md), split from aggregate [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- Vtable data: [UID:0002N7][0x0063041c-0x006304a4.SpellSpellInputPaneVtableData](by-memory/0x0063041c-0x006304a4.SpellSpellInputPaneVtableData.md)
- Reconstruction handling: attached to [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md). The class page now emits a declaration-only `CharInputPane` shell with `[[CHILDREN]]`; [UID:0001MN][0x005b6120-0x005b61e7.SpellSpellInputPaneConstructor](by-memory/0x005b6120-0x005b61e7.SpellSpellInputPaneConstructor.md), [UID:0001MP][0x005b61f0-0x005b625c.SpellSpellInputPaneHandleKeyOrTextEvent](by-memory/0x005b61f0-0x005b625c.SpellSpellInputPaneHandleKeyOrTextEvent.md), and [UID:0001MQ][0x005b6260-0x005b62c8.SpellSpellInputPaneAccept](by-memory/0x005b6260-0x005b62c8.SpellSpellInputPaneAccept.md) carry the method C++.

## Class Purpose

`SpellSpellInputPane` is a spell-selection prompt used when a spell command needs another spell as the argument. It formats a localized prompt with available spell shortcut/range text, handles help shortcut input, and converts a single letter to a local-player command/spell slot.

## Source Declaration Shape

Current source-facing declaration direction:

```cpp
class SpellSpellInputPane : public CharInputPane {
public:
    SpellSpellInputPane();
    bool OnKeyInput(const InputEvent *event);
    void OnAccept();
};
```

This declaration shape now emits from this page without duplicating method bodies. The exact child method pages remain the body emitters.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SpellSpellInputPane` | [UID:0001MN][0x005b6120-0x005b61e7.SpellSpellInputPaneConstructor](by-memory/0x005b6120-0x005b61e7.SpellSpellInputPaneConstructor.md) | Constructs the localized prompt from available spell shortcut/range text and installs vtables. |
| `OnKeyInput` | [UID:0001MP][0x005b61f0-0x005b625c.SpellSpellInputPaneHandleKeyOrTextEvent](by-memory/0x005b61f0-0x005b625c.SpellSpellInputPaneHandleKeyOrTextEvent.md) | Handles the `?` help-panel shortcut, then falls back to `CharInputPane::OnKeyInput`. |
| `OnAccept` | [UID:0001MQ][0x005b6260-0x005b62c8.SpellSpellInputPaneAccept](by-memory/0x005b6260-0x005b62c8.SpellSpellInputPaneAccept.md) | Maps `a-z`/`A-Z` to slots `1`..`52` and dispatches through the local-player command/spell-slot helper. |

## Evidence Notes

- 2026-06-04 live IDA MCP confirms the three method functions: constructor `0x005b6120-0x005b61e7`, key handler `0x005b61f0-0x005b625c`, and accept handler `0x005b6260-0x005b62c8`.
- Live IDA confirms the constructor stores the three `SpellSpellInputPane` vtable bases at `0x0063041c`, `0x0063046c`, and `0x0063049c` into offsets `+0x00`, `+0xa0`, and `+0xa4`.
- Live IDA reports the same vtable stores from command/spell factory paths `0x005a5bd0-0x005a7422` and `0x005a9e10-0x005a9ef3`, plus the constructor stores at `0x005b6167`, `0x005b616d`, and `0x005b6177`.
- Live vtable cells tie primary accept slot `0x00630464` to `0x005b6260`, secondary key slot `0x00630474` to `0x005b61f0`, and secondary/tertiary deleting slots to shared adjustor thunks `0x005b77c8` / `0x005b77d3`.
- Live key handler evidence confirms spell help-panel behavior: `do_narrow`, tab switch helper `0x004b8650`, sound/helper call `0x0057a5c0`, and fallback through base key handler `0x004f2920`.
- Live accept-handler evidence confirms spell selection behavior: input decode helpers `0x004f2310` / `0x004f2300`, player/spell data read through [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / `dword_67A748`, range checks, and final selection call `0x005a4530`.
- Live boundary checks confirm padding at `0x005b61e7-0x005b61f0`, `0x005b625c-0x005b6260`, and `0x005b62c8-0x005b62d0` before the next function.
- 2026-06-17 B001 source-quality reanalysis resolves method names and source placement for the three exact children, rejects generated `SpellManager` / `g_pSpellMan` names, treats `dword_67A748` as a broad local-player/UserPane spell-state pointer in this context, names helper `0x005a4310` descriptively as `BuildAvailableSpellSlotRangeText`, and ties accept dispatch to [UID:0003UC][0x005a4530-0x005a4908.UserPaneUseCommandSlot](by-memory/0x005a4530-0x005a4908.UserPaneUseCommandSlot.md).
- 2026-06-19 B013 local PE recheck reconfirmed the exact child bodies and all-`0xcc` padding, found no direct code route to constructor/key/accept starts, confirmed virtual reachability through `0x00630474 -> 0x005b61f0` and `0x00630464 -> 0x005b6260`, and kept [UID:0001MO][0x005b6120-0x005b62c8.SpellSpellInputPane](by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md) as a non-emitting index over the three method children.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 87 | The class records exact method pages, live function ranges, vtable slots/stores, factory/context refs, key and accept behavior, prompt helper role, local-player spell-state dependency, padding boundaries, parent file placement, and child-page C++ emission policy. |
| Confidence | 90 | Confidence is very strong because live IDA and B001 source-quality review tie all three methods and all three vtable views to `SpellSpellInputPane`, reject generated owner/name pollution, and place the class in `SpellInputPanes`; final local-player global and dispatch-helper spellings remain inferred. |
| Reconstructable | true | The class is NexusTK-owned source behavior; this page emits the declaration shell while exact child pages emit the method bodies. |

## Cross-References

- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0003HL][SpellSpellInputPaneVtables](by-type/by-vtable/SpellSpellInputPaneVtables.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0001MO][0x005b6120-0x005b62c8.SpellSpellInputPane](by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md)
- [UID:0002N7][0x0063041c-0x006304a4.SpellSpellInputPaneVtableData](by-memory/0x0063041c-0x006304a4.SpellSpellInputPaneVtableData.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)

## Changes

### 2026-07-20 UID0001MP callback

- Installed the complete source declaration from R2 and closed `SpellSpellInputPane` before `[[CHILDREN]]`, so constructor, HandleKeyOrTextEvent, and accept definitions emit at namespace scope rather than inside the class.
- Replaced the historical `OnKeyInput(const InputEvent *)` declaration with canonical `HandleKeyOrTextEvent(Event *)`. The exact secondary table cell `0x00630474 -> 0x005b61f0`, complete-object `+0xa0` EventHandler view, and constructor stores at `+0x00/+0xa0/+0xa4` prove the slot/ABI/source cause.
- UID0001MP is exact `[0x005b61f0,0x005b625c)`, 108 bytes, body SHA256 `7053F6C7A78221785AAD841CA73A13F4F9EAF6D505400E30BA85F6492BCA2CCA`, vtable-only live, and performs EventMan translation, exact Shift+`?` key-down testing, tab-3/null then effect-`0x198`/100 ordering, true return, and CharInputPane base forwarding.
- Scores become `90/93`: declaration/child placement and shared Event contracts are complete; private lexical spelling remains the confidence cap. Owner/emitter UID0000O0, reconstructable true, blank optional position, exact layout, constructor/accept evidence, vtable/thunk compiler exclusions, and unrelated current class content remain unchanged.
- The old `InputEvent`, `OnKeyInput`, `NarrowInputKey`, CRT `do_narrow`, and child-before-class-close statements are retained only as superseded history. No raw vtable/RTTI, adjusted-this expression, cookie, or compiler wrapper is emitted manually.

- 2026-06-30 B002 SpellInputPanes implementation callback:
  - Added the accepted declaration-only `SpellSpellInputPane : public CharInputPane` formal C++ block with constructor, destructor declaration, `OnKeyInput`, `OnAccept`, and `[[CHILDREN]]`.
  - Preserved exact child method bodies on [UID:0001MN][0x005b6120-0x005b61e7.SpellSpellInputPaneConstructor](by-memory/0x005b6120-0x005b61e7.SpellSpellInputPaneConstructor.md), [UID:0001MP][0x005b61f0-0x005b625c.SpellSpellInputPaneHandleKeyOrTextEvent](by-memory/0x005b61f0-0x005b625c.SpellSpellInputPaneHandleKeyOrTextEvent.md), and [UID:0001MQ][0x005b6260-0x005b62c8.SpellSpellInputPaneAccept](by-memory/0x005b6260-0x005b62c8.SpellSpellInputPaneAccept.md).
- 2026-06-07 A005 resolved-name cleanup:
  - Before: spell-data selection evidence used only historical `dword_67A748`.
  - After: the page records canonical `g_pCollectionData` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A748` to `g_pCollectionData`; existing IDA-backed evidence already ties the reference to player/spell data reads used by spell selection.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `80`, confidence `76`.
- Evidence: the page documents spell-selection prompt behavior, constructor/key/accept memory docs, vtable family, IDA-confirmed vtable views, and spell-domain placement rationale; confidence remains capped by final spell-input versus command-input source placement.
- 2026-06-04: Completion/confidence changed from `80/76` to `86/86`, `RECONSTRUCTABLE:TRUE` was set, and the class was attached to [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md). Evidence: live IDA MCP confirmed all method boundaries, constructor/vtable stores, vtable slots for accept/key/thunks, factory-path vtable stores, key/accept callee behavior, and exact padding around the method cluster. C++ remains blank because the page is below the final reconstruction bar.
- 2026-06-12 A004 Batch 313 cross-reference update: added [UID:0003HL][SpellSpellInputPaneVtables](by-type/by-vtable/SpellSpellInputPaneVtables.md) as the source-local reconstructable vtable page for this class. Scores stay `86/86`; the direct-parent gate was already closed by the 2026-06-04 evidence and the exact vtable-data child remains linked.
- 2026-06-17 B001 source-quality execution:
  - Before: `86/86`, class-level C++ blank, and method/global/helper names were still provisional.
  - After: `87/90`, class-level C++ remains blank by exact-child emission policy; child pages [UID:0001MN][0x005b6120-0x005b61e7.SpellSpellInputPaneConstructor](by-memory/0x005b6120-0x005b61e7.SpellSpellInputPaneConstructor.md), [UID:0001MP][0x005b61f0-0x005b625c.SpellSpellInputPaneHandleKeyOrTextEvent](by-memory/0x005b61f0-0x005b625c.SpellSpellInputPaneHandleKeyOrTextEvent.md), and [UID:0001MQ][0x005b6260-0x005b62c8.SpellSpellInputPaneAccept](by-memory/0x005b6260-0x005b62c8.SpellSpellInputPaneAccept.md) now carry first-draft C++.
  - Summary/evidence: B001 rechecked the constructor/key/accept methods, helper `0x005a4310`, key-input shortcut route, `0x005a4530` dispatch helper, local-player spell-state offsets under `dword_67A748`, generated `SpellManager`/`g_pSpellMan` rejection, and [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) source placement.
- 2026-06-19 B013 source-quality support sync:
  - Score and ownership unchanged at `87/90`, owner/emitter [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md).
  - Summary/evidence: added source declaration-shape guidance and the local PE no-route/index proof; class-level C++ remains blank so the exact child emitters are not duplicated.
