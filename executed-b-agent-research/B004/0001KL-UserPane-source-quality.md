** TARGET-REPORT-UID:0001KL **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0001KL] UserPane source-quality report

Report-only B004 pass for:

- Target: `source-3/project-documentation/by-memory/0x005a2530-0x005b8395.UserPane.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B004/research/0001KL-UserPane-source-quality.md`
- Status: report created only. No target/support by-* docs were edited. `by-memory/-coverage-report.md` was not edited.

## Final Recommendation

Keep [UID:0001KL] as a reconstructable `UserPane` executable aggregate routed through [UID:0000P1] `UserPane` / `NexusTK/ui/panels/UserPane.cpp`.

Recommended target metadata:

```text
COMPLETION:88
CONFIDENCE:88
CANONICAL_OWNER:0000P1
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000P1
```

Replace the stale "blank because below 95/95" rationale. The current gate is the combined 85/85+ source-readiness/emitter gate, and this target clears the route side: [UID:0001KL] is reconstructable, [UID:0000P1] is a valid file emitter, and the direct class/file support pages already route the main constructor/destructor/name-buffer/slot-label/virtual-handler/name-label/vtable state to `UserPane.cpp`.

Do not put one first-draft C++ body on this aggregate page yet. That is a target-specific no-code/defer decision, not a score-gate failure. The page is an address-range and source-placement aggregate over many independent functions, exact child pages, compiler switch-table children, and interleaved non-UserPane helper islands. A single formal C++ block on [UID:0001KL] would either duplicate child pages or imply that excluded LivingObjectPane, SayInputPanes, Chatting, FunctionObjects, and switch-table artifacts are all one source function. First-draft C++ should be applied on exact method children or after future exact splits, then [UID:0001KL] can remain a documented emitting source-placement aggregate or be demoted to a non-emitting split index after all executable anchors have child coverage.

## Evidence Checked

Instruction/contract files:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B004/goal.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`

Target and direct support docs:

- `by-memory/0x005a2530-0x005b8395.UserPane.md`
- `by-class/UserPane.md`
- `by-file/UserPane.md`
- `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`
- `by-memory/0x005a5b80-0x005a5bc7.UserPaneOnBoundsChanged.md`
- `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md`
- `by-memory/0x005a7422-0x005a76c0.UserPaneHandleKeyEventSwitchTables.md`
- `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`
- `by-memory/0x005a82bd-0x005a83b0.UserPaneHandleServerMessageSwitchTables.md`
- `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md`
- `by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md`
- `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md`
- `by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md`
- `by-memory/0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage.md`
- `by-global/g_pCollectionData.md`
- `by-memory/-coverage-report.md` row context only

Local exported binary data checked:

- `resources/exported_data/functions/0x005a2530.json`
- `resources/exported_data/functions/0x005a2c60.json`
- `resources/exported_data/functions/0x005a2d80.json`
- `resources/exported_data/functions/0x005a40d0.json`
- `resources/exported_data/functions/0x005a4310.json`
- `resources/exported_data/functions/0x005a5bd0.json`
- `resources/exported_data/functions/0x005a76c0.json`
- `resources/exported_data/functions/0x005a83b0.json`
- `resources/exported_data/functions/0x005a8840.json`
- `resources/exported_data/functions/0x005a8e70.json`
- `resources/exported_data/functions/0x005a8f60.json`
- `resources/exported_data/functions/0x005b8230.json`

Searches run:

- `rg` over target/support docs for `0001KL`, `UserPane`, direct anchor addresses, child UIDs, `0x005a4530`, `0x005a4930`, `0x005a4f70`, `00030A`, `0x005abb20`, `0x005a9310`, `0x005a94b0`, `0x005b7450`, and `0x005b77b0`.
- `Get-ChildItem` checks confirmed the required report path was missing before this pass.

I did not edit IDA, by-* docs, generated files, or `by-memory/-coverage-report.md`.

## Range and Split Decision

The [UID:0001KL] exclusive range remains `0x005a2530-0x005b8395`.

Known boundary/padding facts that should stay in the target:

- Predecessor alignment `0x005a2523-0x005a2530` is thirteen `0xcc` bytes.
- Constructor body starts at `0x005a2530` and the next anchor starts after `0x005a2c5b-0x005a2c60` padding.
- Non-deleting cleanup `0x005a2c60-0x005a2d74` is padding-separated from the local-name setter.
- `0x005b8395-0x005b83a0` is eleven `0xcc` bytes before adjacent accessor [UID:00024A] `0x005b83a0-0x005b83a7`.
- `0x005b83a7-0x005b83b0` is nine `0xcc` bytes before the separate `UserStatusPane` neighborhood.

The target is not a contiguous C++ function. It is a broad aggregate of source-owned UserPane anchors in a larger local-player neighborhood. Current exact and future child policy:

| Anchor | Decision |
| --- | --- |
| `0x005a2530-0x005a2c5b` | Keep in [UID:0001KL] for now, but recommend a future exact `UserPaneConstructor` child if implementation wants formal C++. |
| `0x005a2c60-0x005a2d74` | Keep as UserPane non-deleting cleanup, not standalone no-owner. Future exact destructor-helper child is appropriate. |
| `0x005a2d80-0x005a2d97` | UserPane file-scope name setter; future exact child can emit simple C++ once final source name is accepted. |
| `0x005a40d0-0x005a430c` | `BuildInventorySlotLabelString`; future exact child should carry source C++, not the aggregate. |
| `0x005a4310-0x005a4523` | `BuildSpellSlotLabelString`; future exact child should carry source C++, not the aggregate. |
| [UID:0003V8] `0x005a5b80-0x005a5bc7` | Exact child exists; small method and a good first-draft candidate after helper/field names are accepted. |
| [UID:0003V9] `0x005a5bd0-0x005a7422` | Exact child exists; leave C++ blank until full key-handler source shape and event/control field names are resolved. |
| [UID:0003VA] `0x005a7422-0x005a76c0` | Compiler switch-table child, non-source body, no formal C++. |
| [UID:0003VB] `0x005a76c0-0x005a82bd` | Exact child exists; leave whole-dispatcher C++ blank, but keep resolved opcode `0x36` inline decision. |
| [UID:0003VC] `0x005a82bd-0x005a83b0` | Compiler switch-table child, non-source body, no formal C++. |
| [UID:0003VD] `0x005a83b0-0x005a87ad` | Exact child exists; source-shaped animation virtual, but not whole-method C++ ready because event tags and animation fields remain provisional. |
| `0x005a8840-0x005a88cf` | UserPane `OnClipBounds`; future exact child should be created before formal C++. |
| `0x005a8e70-0x005a8f5a` | UserPane `ShowNameLabel`; future exact child is first-draft-ready enough after BowGauge/global naming is accepted. |
| `0x005a8f60-0x005a8f8c` | UserPane `HideNameLabel`; future exact child is first-draft-ready enough after timer/global naming is accepted. |
| `0x005b8230-0x005b8395` | Scalar deleting destructor glue plus destructor body; keep C++ blank unless split from non-deleting cleanup and pool-return policy is documented on an exact child. |
| [UID:00024A] `0x005b83a0-0x005b83a7` | Adjacent exact child already emits `MapPane *UserPane::GetMapPane()`. It is outside [UID:0001KL] and should stay outside. |

## Source Placement and Ownership

Direct owner remains [UID:0000P1] `UserPane` / `NexusTK/ui/panels/UserPane.cpp`.

Evidence:

- The constructor at `0x005a2530` is called from UI initialization at `0x004f84e2` and `0x004f8a49`, stores `this` into `dword_67A748` / [UID:0000QK] `g_pCollectionData`, installs three UserPane vtables, vector-constructs 128 large records at stride `0x2604`, initializes map/BowGauge/local state, and returns `this`.
- The name setter at `0x005a2d80` is called from the same initialization function at `0x004f84ad` and `0x004f8a14`, directly tying the local wide-name buffer setup to UserPane startup.
- The non-deleting destructor `0x005a2c60` and scalar deleting destructor `0x005b8230` restore the UserPane vtables, delete the same child/list/buffer fields, remove BowGauge pending timers/show state, vector-destroy the same 128 records, clear `dword_67A748`, and call the base cleanup.
- [UID:0002YU] `UserPaneVtableData` records the same vtable family and direct constructor/destructor stores. The main UserPane virtual slots point back to exact children and unsplit anchors in this page.
- [UID:0002AA] `LocalPlayerNameWideBuffer` and [UID:0002AC] `UserPanePoolStaticStorage` both route to [UID:0000P1] through direct xrefs and lifecycle evidence.
- [UID:00024A] `GetMapPane` confirmed `m_mapPane` at `this+0x1340f8`; the constructor copies [UID:0000PR] `g_activeMapPane` and writes the inverse `MapPane+0x418 = this`, which is class member setup rather than MapPane ownership.

Rejected ownership alternatives:

- `LivingObjectPane`: base class and major local-player movement/server helpers are real, but the constructor/destructor/vtable/name-buffer/pool evidence belongs to `UserPane`. Keep the excluded helper starts documented with [UID:0001KM], including `0x005a2de0`, `0x005a2e00`, `0x005a4530`, `0x005a5a90`, `0x005a87e0`, `0x005a88d0`, and `0x005a8cf0`.
- `SayInputPanes` or `Chatting`: the `0x005a4930-0x005a5791` neighborhood contains chat history and say-input helpers, and the key handler constructs/chat-opens some of those panes. That is consumer/inlined allocation evidence, not ownership of [UID:0001KL]. The narrow opcode `0x2d` state exception [UID:00030A] belongs to `UserPane.cpp` as file-level local-player command state.
- `MapPane`: `m_mapPane` is a cached pointer and active-object back-pointer relationship. MapPane is a dependency and consumer of UserPane state, not the owner of this aggregate.
- `BowGaugeObjectPane`: BowGauge is a child/global dependency for the name-label UI. `ShowNameLabel`, `HideNameLabel`, and destructor paths consume [UID:0000QA] `g_pBowGaugeObjectPane`; BowGauge methods remain in BowGauge docs.
- `FunctionObjects`: [UID:0002VM] and [UID:0001N5] are template callback support bound to a `UserPane` target, not methods of UserPane and not proof that the broad callback templates should be merged into this target.
- `UserStatusPane`: the adjacent `0x005b83a0-0x005b83a7` accessor is UserPane-owned by vtable slot, but `0x005b83b0` starts a separate UserStatusPane neighborhood. Do not extend [UID:0001KL] past `0x005b8395`.
- No-owner/non-emitting for the whole target: not appropriate now because several unsplit executable anchors are real UserPane source methods and would lose their only current owner/emitter route.

## Source-Facing Names and Layout Recommendations

Use source-facing names in prose, with raw names kept only as aliases during transition.

Recommended names:

| Raw/current label | Recommended source-facing role | Confidence | Notes |
| --- | --- | ---: | --- |
| `sub_5A2530` | `UserPane::UserPane()` | High | No constructor parameters in exports; calls `LivingObjectPane(0,0,0,2)` and initializes UserPane globals/vtables/children. |
| `sub_5A2C60` | `UserPane::~UserPane()` non-deleting cleanup body | High | Same cleanup core as scalar deleting destructor without pool-return flag path. |
| `sub_5A2D80` | `SetLocalPlayerName` or `SetUserPaneNameBuffer` | Medium-high | `__cdecl`, one `const wchar_t *`, calls `wcscpy_s(word_69BEE0, 0x20, source)`. Final original spelling unknown; do not keep only `sub_5A2D80`. |
| `word_69BEE0` | `g_localPlayerName` or `s_localPlayerName` | Medium-high | Exact fixed `wchar_t[32]`; docs currently call it LocalPlayerNameWideBuffer. |
| `sub_5A40D0` | `UserPane::BuildInventorySlotLabelString(wchar_t *out)` | High for role, medium for signature | Builds compact ranges of active inventory command slots and writes a terminator. |
| `sub_5A4310` | `UserPane::BuildSpellSlotLabelString(wchar_t *out)` | High for role, medium for signature | Builds compact ranges over 52 spell slots; callers include OnKeyEvent and SpellSpellInputPane constructor path. |
| `sub_5A5B80` | `UserPane::OnBoundsChanged(...)` | High for role, medium for exact signature | Small vtable method, exact child [UID:0003V8]. Existing docs describe bounds-cache comparison and child/base forwarding. |
| `sub_5A5BD0` | `bool UserPane::OnKeyEvent(const PaneKeyEvent *event)` | Medium-high | Binary returns `AL` as handled/unhandled. Keep child filename `HandleKeyEvent` if project convention prefers that spelling, but prose should use one source-facing virtual name consistently. |
| `sub_5A76C0` | `bool UserPane::OnServerMessage(const ServerMessageEvent *event)` | Medium-high | Reads payload pointer/size at event `+0x0c/+0x10`; opcode switch is direct source shape. |
| `sub_5A83B0` | `bool UserPane::OnAnimationStep(int message, int frameOrDirection, int aux)` | Medium | Vtable slot is clear; final event enum/tag names are not. |
| `sub_5A8840` | `UserPane::OnClipBounds(RectBounds *clip, RectBounds *out)` | Medium-high | Calls base `LivingObjectPane` clipping and optionally intersects a centered avatar/name clip rectangle. Final return type should be checked against base virtual family before C++. |
| `sub_5A8E70` | `void UserPane::ShowNameLabel()` | High | Shows/repositions BowGauge/name-label child, sets visible flag, records tick, optional backdating by 5000. |
| `sub_5A8F60` | `void UserPane::HideNameLabel()` | High | Clears visible flag, calls BowGauge `RemovePendingTimers`, records `g_pTimerMgr+0x18` to `this+0x13eaf8`. |
| `sub_5B8230` | `UserPane::ScalarDeletingDestructor` | High | Compiler glue plus destructor core and pool return through `byte_69BF34`; source should be represented by destructor plus generated scalar wrapper. |
| `dword_67A748` | `g_pCollectionData` / local-player UserPane singleton | Medium-high | Current canonical doc name can stay; prose should call out that it is a broad local-player/client-state pointer, not collection-private. |
| `byte_69BF34` | `s_userPanePool` / `UserPanePoolStaticStorage` | High | Static pool object exact range and lifecycle are documented. |
| `this+0x1340f8` | `m_mapPane` | Very high | Confirmed by [UID:00024A] and constructor/back-pointer evidence. |
| `this+0x13eb20..+0x13eb30` | deferred user-list packet buffer/state | High for role, medium for names | Opcode `0x36` inline case and retained duplicate helper agree on payload pointer/size/timestamps/skip flag. |
| `this+0x13eaf8` | name-label hidden/timer tick | Medium-high | `HideNameLabel` stores `g_pTimerMgr+0x18`; `ShowNameLabel` records a current tick into the nearby name-label timestamp field and backdates by 5000 under a flag. |
| `this+0x13eb04/+0x13eb08/+0x13eb0c` | UserPane-owned list children | Medium | Constructor creates `List(0x200, 10)`, `List(0x40, 10)`, `List(0x40, 10)`; destructor deletes them. Final semantic names need caller-by-caller field use before C++. |
| `this+0x13eb14/+0x13eb18` | 64-entry 16-byte scratch/visibility buffer | Medium | Constructor allocates `0x400`, initializes first byte of each 16-byte record, server opcode `0x04` clears it. Exact source field name unresolved. |

Do not introduce final names such as `SpellManager`, collection-private globals, or BowGauge-owned UserPane fields without stronger source evidence. Current docs already note that `dword_67A748` is a broad local-player/client-state pointer with collection, spell, item, command, and UI views.

## Method Group Findings

### Constructor `0x005a2530-0x005a2c5b`

Source shape is a real no-argument `UserPane::UserPane()`:

- Calls base `LivingObjectPane::LivingObjectPane(this, 0, 0, 0, 2)`.
- Stores `this` into `dword_67A748` / [UID:0000QK] unless the decompiler's null-adjusted edge fires.
- Installs the primary and secondary UserPane vtables at `0x0062ef0c`, `0x0062ef90`, and `0x0062efc0`.
- Runs vector constructor over 128 records at stride `0x2604`.
- Initializes EPF/non-EPF branches based on `byte_66DA97`.
- Allocates/deletes three list children later observed at `+0x13eb04/+0x13eb08/+0x13eb0c`.
- Copies [UID:0000PR] `g_activeMapPane` to `this+0x1340f8` and writes inverse `MapPane+0x418 = this`.
- Allocates the `0x400` 64-record scratch buffer, initializes render/clip rectangles, constructs a surface/image helper, and constructs `BowGaugeObjectPane` in the EPF branch.

Do not emit constructor C++ on the parent aggregate. Future exact child C++ is plausible but needs a focused field-name pass because the constructor is large and conditional on EPF layout.

### Destructor helper and scalar deleting destructor

`0x005a2c60` is the non-deleting cleanup body. `0x005b8230` is a scalar deleting destructor wrapper that repeats the cleanup core and conditionally returns storage to the UserPane pool. Both restore the UserPane vtables before tearing down children, which is expected C++ destructor codegen rather than evidence for a second class owner.

Source-level representation should be:

- `UserPane::~UserPane()` as the handwritten destructor.
- Compiler-generated scalar deleting destructor as no-code/generated glue.
- [UID:0002AC] pool return through `byte_69BF34` as source-declared/generated-binary storage, not arbitrary raw data.

Open field names in the destructor are not passive blockers for source routing, but they are blockers for putting a polished destructor body into the broad parent page. Exact destructor child pages should carry final C++ only after `+0x13eb04/+08/+0c`, `+0x13eb14/+18`, and BowGauge cleanup names are stabilized.

### Local name helper and name buffer

`0x005a2d80-0x005a2d97` is small enough for future exact child C++:

```cpp
void SetLocalPlayerName(const wchar_t *name)
{
    wcscpy_s(g_localPlayerName, 0x20, name);
}
```

This is a future child-page draft, not a [UID:0001KL] aggregate C++ block. Original helper name is not known. Best source-facing direction is `SetLocalPlayerName`, `SetUserPaneName`, or `SetUserPaneNameBuffer`; `SetLocalPlayerName` fits the fixed `word_69BEE0` docs and block-list validation use best.

### Inventory and spell label builders

`0x005a40d0` and `0x005a4310` are source-owned UserPane methods, not generic formatting helpers:

- Inventory helper is repeatedly called by item-command input-pane creation paths inside `OnKeyEvent`.
- Spell helper scans 52 spell slots using `0x148`-stride records and maps slot numbers to `a..z`, `A..Z`, or space, with compact range output and `-` for longer ranges.
- The spell helper has callers from `OnKeyEvent`, `0x005a9e10`, and `0x005b6120`, matching command prompt setup and spell input panes.

These are good future exact child pages. They can likely get first-draft source C++ after the slot-record active flag offsets are named. Do not keep raw `sub_5A40D0`/`sub_5A4310` in support docs except as aliases.

### Bounds, key, server, animation, clip, and name-label virtuals

Vtable evidence is strong:

- `0x0062ef18 -> 0x005a5b80` `OnBoundsChanged`
- `0x0062ef28 -> 0x005b83a0` `GetMapPane`
- `0x0062ef5c -> 0x005a8840` `OnClipBounds`
- `0x0062ef80 -> 0x005a8e70` `ShowNameLabel`
- `0x0062ef84 -> 0x005a8f60` `HideNameLabel`
- `0x0062ef98 -> 0x005a5bd0` `OnKeyEvent`/`HandleKeyEvent`
- `0x0062efa0 -> 0x005a76c0` `OnServerMessage`/`HandleServerMessage`
- `0x0062efc4 -> 0x005a83b0` `OnAnimationStep`

`OnKeyEvent` source-facing details:

- Returns handled/unhandled in `AL`; use `bool` unless base virtual docs prove a different source typedef.
- Starts by checking UserPane control flags, modal/chat gates, key event type byte at event `+0x4`, raw key byte at event `+0x8`, and modifier/extra byte at event `+0x10a`.
- Calls a ctype/narrow helper at `0x004a8b10`.
- Uses compiler switch tables [UID:0003VA] at `0x005a7422-0x005a76c0`.
- Constructs many input panes inline by allocation, base constructor calls, vtable installs, and singleton stores. Those child panes remain their own classes/files.
- Contains the `0x51` route to [UID:0001KP] `QuitPromptLauncher`.
- Contains the inline opcode `0x2d` EPF/non-EPF write to [UID:00030A] `0x0069bf6c/0x0069bf70`.
- Contains inline ChatInputPane construction for the `">"` prompt. That xref is a consumer/construction site, not proof that the prompt literal or ChatInputPane belongs to UserPane.

`OnServerMessage` source-facing details:

- Returns handled/unhandled in `AL`; use `bool`.
- Reads packet payload pointer at event `+0x0c` and payload size at event `+0x10`.
- Switches on the first payload byte with [UID:0003VC] switch data.
- Opcode `0x36` is resolved as an inline live user-list packet case. It stages/defer-copies payload data in `LivingObjectPane+0x13eb20..+0x13eb30`, tiers next refresh by entry count from `payload+3`, honors the skip flag, and lazy-creates `UserListDialogPane`.
- Do not rewrite opcode `0x36` as a call to [UID:0003US] `0x005abb20`: current docs record no xrefs, no switch-table route, and no raw PE VA/RVA/rel32 route to the retained duplicate helper.

`OnAnimationStep` source-facing details:

- Vtable slot and class owner are clear.
- Event ids include `0x14`, `0x41645746`, and `0x446e4146`; final enum/tag names are not safe yet.
- It drives LivingObjectPane animation state, `g_pTimerMgr`/timer scheduling, `MapPane` facing/frame helpers, and local movement/clip updates.
- Keep C++ blank on [UID:0003VD] until event-name and animation-field naming are resolved.

`OnClipBounds` source-facing details:

- Calls base `LivingObjectPane::OnClipBounds` first.
- If the options/client-state flag at `dword_67A7C8+0x28de76` is enabled and a UserPane/ObjectPane render flag at `this+0x1c6` is set, it builds a centered rectangle using `word_66DA9C`, `word_66DAA0`, and `this+0x3ec4`, then intersects/applies it through `0x004b7d70`.
- Best source-facing role is local avatar/name-label clip customization. It should get an exact child before C++.

`ShowNameLabel` and `HideNameLabel` source-facing details:

- `ShowNameLabel` checks a visible flag at `this+0x1d1` in the export, calls BowGauge/global virtual methods at slots `+0x38`, `+0x40`, `+0x30`, and `+0x3c`, reads current bounds through this virtual slot `+0x28`, computes a small rectangle either to the side or above depending on local facing/state byte `dword_67A748+0x1c5`, records `g_pTimerMgr+0x18`, optionally backdates by 5000 when a UserPane flag at `+0x13eafd` is set, and calls `0x00538c10`.
- `HideNameLabel` clears the same visible flag, calls [UID:0001DC] `BowGaugeObjectPane::RemovePendingTimers` when [UID:0000QA] `g_pBowGaugeObjectPane` is non-null, and stores the current tick into `this+0x13eaf8`.
- The BowGauge global/function names should remain BowGauge-owned. UserPane methods are consumers and lifecycle coordinators.

## First-Draft C++ Readiness

[UID:0001KL] parent aggregate:

- Do not populate formal C++.
- Reason: target-specific aggregate/no-code proof, not score-gate failure.
- It clears owner/emitter readiness but is not the correct granularity for C++.

Already emitted:

- [UID:00024A] `UserPane::GetMapPane()` is complete and correctly emits a tiny accessor.

Good future first-draft candidates after exact child creation or targeted child callback:

- `0x005a2d80-0x005a2d97` local name setter.
- `0x005a40d0-0x005a430c` inventory slot label builder.
- `0x005a4310-0x005a4523` spell slot label builder.
- [UID:0003V8] `UserPane::OnBoundsChanged`, after helper names for rectangle compare/update and child forwarding are accepted.
- `0x005a8840-0x005a88cf` `OnClipBounds`, after base virtual return/signature is confirmed.
- `0x005a8e70-0x005a8f5a` `ShowNameLabel`.
- `0x005a8f60-0x005a8f8c` `HideNameLabel`.

Keep blank for now:

- [UID:0003V9] `OnKeyEvent`: too large, many inline child-pane constructors, packet sends, and unresolved event/control field names.
- [UID:0003VB] `OnServerMessage`: opcode `0x36` is resolved, but whole dispatcher still has many packet-case names and payload structs unresolved.
- [UID:0003VD] `OnAnimationStep`: vtable/source owner clear, but event tags and animation/local-movement fields need another pass.
- [UID:0003VA] and [UID:0003VC]: compiler switch tables, no source C++.
- `0x005b8230-0x005b8395`: scalar deleting destructor/generated glue should not be hand-authored on the parent page.

## Open Questions and Evidence-Backed Direction

| Issue | Evidence checked | Recommendation |
| --- | --- | --- |
| Final original name for `dword_67A748` | `g_pCollectionData.md`, target/class/file docs, constructor/destructor exports, broad consumer notes. | Keep canonical doc alias `g_pCollectionData` but describe it as the local-player/UserPane singleton or broad player/client-state pointer. Do not treat it as collection-private. |
| Final helper name for `0x005a2d80` | Export confirms one `wchar_t *` parameter and `wcscpy_s(word_69BEE0, 0x20, source)`; callers are UI init. | Best source-facing name `SetLocalPlayerName`. If implementation wants lower-risk wording, use `SetUserPaneNameBuffer` in prose and keep `SetLocalPlayerName` as likely original-style alias. |
| Three list fields at `+0x13eb04/+08/+0c` | Constructor creates 512/64/64-list children; destructors delete the same fields. | Source docs can call them UserPane-owned list children. Do not invent final semantic names until caller use is fully mapped. |
| `OnKeyEvent` event type and fields | Export shows return `char`, event offset reads at `+0x4`, `+0x8`, `+0x10a`, and `+0x10c` for the opcode `0x2d` extra value. | Use `bool UserPane::OnKeyEvent(const PaneKeyEvent *event)` as high-probability source-facing signature, but leave child C++ blank. |
| `OnServerMessage` packet context type | Export and child doc show event `+0x0c/+0x10` payload pointer/size and opcode-byte switch. | Use `bool UserPane::OnServerMessage(const ServerMessageEvent *event)` or project-preferred `HandleServerMessage`; document packet context fields descriptively until a shared type is named. |
| `OnAnimationStep` message constants | Export shows `0x14`, `0x41645746`, `0x446e4146`, MapPane/LivingObjectPane animation calls, and bool-like return. | Source owner and role are solved; final enum names are not safe. Keep C++ blank and request a child-specific animation/event naming pass. |
| BowGauge/name-label ownership | Target, class docs, exports for show/hide, [UID:0001DC], [UID:0000QA]. | UserPane owns `ShowNameLabel`/`HideNameLabel`; BowGauge owns timer/display helper methods. UserPane is a consumer/coordinator, not BowGauge owner. |
| Parent aggregate C++ | Target docs, exact child pages, mixed neighbor docs, switch-table children, support vtable/global docs. | No parent formal C++. This is a child-first split/emission problem, not a reconstructability blocker. |

## Recommended Target Changes

Implementation should update `by-memory/0x005a2530-0x005b8395.UserPane.md` as follows:

1. Change metadata to:

```text
COMPLETION:88
CONFIDENCE:88
CANONICAL_OWNER:0000P1
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000P1
```

2. Replace stale below-95/no-code wording with:

```text
This page clears the current combined 85/85+ owner/emitter gate through [UID:0000P1] `UserPane.cpp`; the blank formal C++ block is a target-specific aggregate/split decision, not a gate failure. [UID:0001KL] spans many UserPane methods, exact child pages, compiler switch-table children, and excluded neighboring helper islands, so first-draft C++ belongs on exact method children or future splits rather than on this broad parent aggregate.
```

3. Add the current source-quality decision that the range remains reconstructable and UserPane-owned, but parent-level C++ should stay blank until exact children cover the remaining unsplit source methods.

4. Add or expand source-facing names:

- `UserPane::UserPane()`
- `UserPane::~UserPane()` non-deleting cleanup body
- `SetLocalPlayerName` / `SetUserPaneNameBuffer` for `0x005a2d80`
- `UserPane::BuildInventorySlotLabelString`
- `UserPane::BuildSpellSlotLabelString`
- `bool UserPane::OnKeyEvent(...)` / project-preferred `HandleKeyEvent`
- `bool UserPane::OnServerMessage(...)` / project-preferred `HandleServerMessage`
- `bool UserPane::OnAnimationStep(...)`
- `UserPane::OnClipBounds`
- `UserPane::ShowNameLabel`
- `UserPane::HideNameLabel`
- `UserPane` scalar deleting destructor as generated wrapper/glue

5. Preserve all exact boundaries, padding, and child exclusions:

- no expansion past `0x005b8395`
- adjacent [UID:00024A] remains outside
- LivingObjectPane helper starts remain under [UID:0001KM]
- SayInput/chat helpers remain under SayInputPanes/Chatting except for the already documented opcode `0x2d` local-player state exception
- switch-table children remain compiler data/no C++

6. Add a "Future child split/emission policy" section naming the recommended exact child pages for constructor, cleanup, local-name setter, slot-label builders, `OnClipBounds`, `ShowNameLabel`, `HideNameLabel`, and scalar deleting destructor.

## Recommended Support-Doc Changes

Update `by-class/UserPane.md`:

- Replace any lingering "class-level declaration C++ remains blank until large handler/member layout" wording with the stronger child-first policy: class/aggregate route clears the current gate, but formal C++ should be emitted on exact children, not the broad aggregate.
- Add source-facing signatures with confidence:
  - `UserPane::UserPane()`
  - `UserPane::~UserPane()`
  - `bool OnKeyEvent(const PaneKeyEvent *event)` or project-preferred handler spelling
  - `bool OnServerMessage(const ServerMessageEvent *event)` or project-preferred handler spelling
  - `bool OnAnimationStep(...)`
  - `OnClipBounds(...)`
  - `ShowNameLabel()`
  - `HideNameLabel()`
  - `MapPane *GetMapPane()`
- Add that `0x005a2d80` is best documented as a UserPane file-scope `SetLocalPlayerName`/name-buffer helper, not a class method unless future source evidence proves it was a static method.
- Add that `+0x13eb20..+0x13eb30` are deferred user-list packet fields used by the live opcode `0x36` inline path.
- Clarify `g_pCollectionData` as the current canonical alias for a broader local-player/UserPane/client-state pointer.

Update `by-file/UserPane.md`:

- Add the child-first emission policy for [UID:0001KL].
- Keep `NexusTK/ui/panels/UserPane.cpp` as the source route.
- Add future exact split recommendations for local name setter, slot-label builders, clip/name-label methods, and destructor helpers.
- Preserve the documented exclusions for LivingObjectPane, SayInputPanes, Chatting, FunctionObjects, MapPane, and BowGauge.
- Keep [UID:00030A] as file-level local-player opcode `0x2d` command state, not a `UserPane` class field.

Update child/support docs only if implementation callback scope allows:

- [UID:0003V8] `UserPaneOnBoundsChanged`: note first-draft readiness after helper names.
- [UID:0003V9] `UserPaneHandleKeyEvent`: use `bool` source-facing return and document key-event field offsets; keep C++ blank.
- [UID:0003VB] `UserPaneHandleServerMessage`: already has the opcode `0x36` inline decision; ensure wording says whole dispatcher C++ remains blank, not stale score gate.
- [UID:0003VD] `UserPaneHandleAnimationStep`: add source-facing signature caveat and event-tag unresolved status.
- [UID:0002YU] `UserPaneVtableData`: no code change; optionally add that vtable bytes regenerate from the class declaration and should not be hand-authored.
- [UID:0002AA] `LocalPlayerNameWideBuffer`: no required change; optional alias `g_localPlayerName` / `s_localPlayerName`.
- [UID:0002AC] `UserPanePoolStaticStorage`: no required change; already correctly assigns the pool to `UserPane.cpp`.

## Exact Pending Coverage Row

Supervisor-owned replacement row for `by-memory/-coverage-report.md`:

```text
    - [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md) 0x005a2530-0x005b8395 | class aggregate / UserPane executable anchor index | UserPane : reconstructable : 88% : strong : B004 source-quality pass confirms the broad local-player `UserPane` aggregate routes to [UID:0000P1] `UserPane.cpp` with constructor/destructor/name-buffer/slot-label/name-label/vtable evidence, clean padding before/after, and explicit exclusions for LivingObjectPane, say-input/chat, FunctionObjects, and switch-table children. Formal C++ should remain blank on this parent despite clearing the current 85/85 emitter gate because the page is an overbroad method aggregate with exact child pages and interleaved non-UserPane helpers; first-draft C++ belongs on exact method children such as [UID:00024A] and future splits for label/name-label/clip methods, while large key/server/animation dispatchers remain child-level defer targets.
```

## Validation Commands for Future Implementation

Run validators from `source-3/project-documentation` for every doc touched during implementation. Minimum expected commands if only the target, class, and file pages are updated:

> Executable block R001 was removed from this report and preserved verbatim in [0001KL-UserPane-source-quality-removed.md](0001KL-UserPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If child pages are touched in the same callback, add:

> Executable block R002 was removed from this report and preserved verbatim in [0001KL-UserPane-source-quality-removed.md](0001KL-UserPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Formal C++ should remain blank on [UID:0001KL], so no generated `auto-generated/NexusTK/ui/panels/UserPane.cpp` change is expected from this target alone. If implementation creates exact child C++ blocks in a later callback, report any generated file/stat changes from the validator/autogen workflow.

## IDA Rename, Type, and Comment Recommendations

No IDA edits were made. Recommended future annotations:

| Address/global | Rename/type/comment | Confidence |
| --- | --- | ---: |
| `sub_5A2530` | `UserPane::UserPane()` | High |
| `sub_5A2C60` | `UserPane::~UserPane_non_deleting` or `UserPane::Destroy` cleanup helper comment | High |
| `sub_5A2D80` | `SetLocalPlayerName(const wchar_t *name)` | Medium-high |
| `word_69BEE0` | `g_localPlayerName` / `s_localPlayerName[32]` | Medium-high |
| `sub_5A40D0` | `UserPane::BuildInventorySlotLabelString(wchar_t *out)` | High |
| `sub_5A4310` | `UserPane::BuildSpellSlotLabelString(wchar_t *out)` | High |
| `sub_5A5B80` | `UserPane::OnBoundsChanged(...)` | High |
| `sub_5A5BD0` | `UserPane::OnKeyEvent(const PaneKeyEvent *event)` with bool return comment | Medium-high |
| `sub_5A76C0` | `UserPane::OnServerMessage(const ServerMessageEvent *event)` with bool return comment | Medium-high |
| `sub_5A83B0` | `UserPane::OnAnimationStep(...)`; comment unresolved event tags `0x14`, `0x41645746`, `0x446e4146` | Medium |
| `sub_5A8840` | `UserPane::OnClipBounds(...)` | Medium-high |
| `sub_5A8E70` | `UserPane::ShowNameLabel()` | High |
| `sub_5A8F60` | `UserPane::HideNameLabel()` | High |
| `sub_5B8230` | `UserPane::ScalarDeletingDestructor` / generated scalar deleting destructor wrapper | High |
| `dword_67A748` | Keep canonical `g_pCollectionData`; add comment "local-player/UserPane singleton, broad client-state pointer" | Medium-high |
| `byte_69BF34` | `s_userPanePool` / `UserPanePoolStaticStorage` | High |
| `this+0x1340f8` | `m_mapPane` | Very high |
| `this+0x13eb20..+0x13eb30` | deferred user-list packet state comment | High for role |
| `this+0x13eaf8` | name-label/timer tick comment | Medium-high |

## Implementation Readiness

Implementation is ready for documentation-only changes:

- update [UID:0001KL] metadata and current gate/no-code rationale;
- update `by-class/UserPane.md` and `by-file/UserPane.md` support wording;
- leave formal C++ blank on [UID:0001KL];
- do not edit `by-memory/-coverage-report.md`;
- use the exact pending coverage row above for supervisor-owned coverage application.

Implementation is not ready for a parent aggregate C++ block. If the supervisor wants source code generation, first split or target exact child pages and apply C++ there.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0001KL-UserPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"0001KL"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001KL-UserPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0001KL-UserPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001KL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
