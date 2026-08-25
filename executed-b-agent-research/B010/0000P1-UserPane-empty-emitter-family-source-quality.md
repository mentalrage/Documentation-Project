** TARGET-REPORT-UID:0000P1 **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0000P1 UserPane Empty-Emitter Family Source-Quality Research

Assignment: `B010-report-0000P1-UserPane-empty-emitter-family-20260701`  
Mode: report-only research. No by-* docs, generated files, generated reports, coverage reports, validator state, queue files, archives, supervisor ledgers, or IDA database state were edited.

Implementation callback update, 2026-07-01: accepted implementation details have been applied into the scoped by-* docs. The Claim And Incorporation Ledger now marks accepted rows `applied` with proof; the Implementation Tracking Checklist is checked off item by item; scoped validator results and generated `UserPane.cpp` freshness proof are recorded in `Validator Results`.

## Original Target State Before Implementation

Primary target [UID:0000P1] `by-file/UserPane.md` is currently `COMPLETION:89`, `CONFIDENCE:85`, `CANONICAL_OWNER:FILE`, proposed path `NexusTK/ui/panels/`. The generated file `auto-generated/NexusTK/ui/panels/UserPane.cpp` was refreshed by validator command `000000003740` at `2026-07-01T07:11:51-04:00` and contains 13 emitters: two filled and eleven empty.

Current filled emitters are [UID:00024A] `UserPane::GetMapPane()` and [UID:0001OR] source-facing `UserPane *g_pUserPane = 0`.

Current empty emitters in scope:

| UID | Current path | Current disposition |
| --- | --- | --- |
| `0000FQ` | `by-class/UserPane.md` | Class declaration page, `86/86`, blank formal C++. |
| `0003VB` | `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md` | Large source-authored server-message virtual, `87/89`, blank formal C++. |
| `0003VD` | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` | Source-authored animation/update virtual, `86/88`, blank formal C++. |
| `0002YU` | `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md` | Source-declared/generated-binary vtable data, `88/91`, blank formal C++. |
| `0003EE` | `by-global/g_pInputBlockerPane.md` | Process-wide singleton pointer, `85/89`, blank formal C++. |
| `0002W8` | `by-memory/0x0069b4cc-0x0069b4d0.InputBlockerPaneSingleton.md` | Exact singleton backing slot, `87/91`, blank formal C++. |
| `0001KL` | `by-memory/0x005a2530-0x005b8395.UserPane.md` | Broad executable aggregate/index, `88/88`, blank formal C++. |
| `0002AA` | `by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md` | Fixed wide local-player name buffer, `87/90`, blank formal C++. |
| `0002AC` | `by-memory/0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage.md` | Concrete static pool object, `90/88`, blank formal C++. |
| `00030A` | `by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md` | Two file-scope command-state dwords, `87/89`, blank formal C++. |
| `0001TZ` | `by-type/by-struct/CollectionPlayerDataLayout.md` | Nested collection-player layout view, `86/88`, blank formal C++. |

## Evidence Checked

### Required docs and generated output

- `tools/leaser/Agents/Agent-B010/goal.md`.
- Project skill `ntk-b-agent-workflow`, `b-agent-research-and-implementation-workflow.md`, `supervisor-rule26-review-and-incorporation-standard.md`, and `score-blocker-audit-standard.md`.
- `by-structure.md` `IDA MCP Output Discipline`: followed narrow exact-address MCP calls, capped xrefs, and no broad lists/searches.
- Primary target `by-file/UserPane.md`.
- All eleven current empty-marker docs listed above.
- Support docs `by-class/PoolAllocator.md`, `by-file/PoolAllocator.md`, and `by-global/PoolAllocatorStaticInstances.md` for the `UserPane` pool declaration.
- Generated output `auto-generated/NexusTK/ui/panels/UserPane.cpp`.

### Old/support report search terms and relevant matches

Search terms used with `rg` over `executed-b-agent-research` and active agent research:

`0000P1`, `UserPane-empty-emitter-family`, `0000FQ`, `0003VB`, `UserPaneHandleServerMessage`, `0x005a76c0`, `0003VD`, `UserPaneHandleAnimationStep`, `0x005a83b0`, `0002YU`, `UserPaneVtableData`, `0003EE`, `g_pInputBlockerPane`, `0002W8`, `InputBlockerPaneSingleton`, `0001KL`, `0002AA`, `LocalPlayerNameWideBuffer`, `0002AC`, `UserPanePoolStaticStorage`, `00030A`, `Opcode2dCommandExtraValueSlots`, `0001TZ`, and `CollectionPlayerDataLayout`.

Relevant opened or reviewed matches:

- B001 `0003VB-0003US-UserPaneUserListDispatchSourceShape-source-quality.md`: validates opcode `0x36` as inline in [UID:0003VB] and rejects a live call to standalone `0x005abb20`.
- B011 `0003UU-LivingObjectPaneHandleMessageShowPacket-source-quality.md`: validates opcode `0x58` as a dispatcher call from [UID:0003VB] to a non-member file-local helper at `0x005ac070`.
- B007 `0002R1-LivingObjectPaneAnimationTimer-source-quality.md`: resolves `FWdA` and `FAnD` as LivingObjectPane timer constants and leaves only `0x14` plus local movement field/helper names as [UID:0003VD] blockers.
- B010 `00002W-CollectionEntryControlPane-class-source-quality.md`: supports the current [UID:0001TZ] collection entry record names and caveats.
- B009 `0001N4-ConfirmInputPaneConstructor-source-quality.md`: confirms `g_pInputBlockerPane` clear-helper/use context as input-blocker/UserPane state, not confirm-pane ownership.
- B003 `0001AS-profile-sidecar-refresh-source-quality.md`: supports [UID:0002AA] as the local-player-name source for profile sidecar filenames.
- B014 `0001N5-UserPaneDoubleParamCallback-source-quality.md`: support-only evidence that adjacent `UserPane` callback helpers should stay with UserPane, not FunctionObjects.

No exact executed or active `TARGET-REPORT-UID:0000P1` / `UserPane-empty-emitter-family` report was found.

### Live IDA MCP evidence

IDA MCP was available and used. Session `supervisor_resume_20260629` was active; `server_health` returned `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.

Narrow MCP calls used in this pass:

- `idb_list` and `server_health` for availability.
- `lookup_funcs` for `0x005a76c0`, `0x005a83b0`, `0x005a2530`, `0x005b83a0`, `0x005a4f70`, and `0x005a2d80`.
- `get_bytes` for `0x0062ef0c` size `192`, `0x0069b4cc` size `4`, `0x0069bee0` size `64`, `0x0069bf34` size `40`, and `0x0069bf6c` size `8`.
- `xrefs_to` capped at `40` for `0x005a76c0`, `0x005a83b0`, `0x0062ef0c`, `0x0069b4cc`, `0x0069bee0`, `0x0069bf34`, `0x0069bf6c`, and `0x0069bf70`.
- `analyze_function` for `0x005a76c0` and `0x005a83b0`.
- `decompile` for `0x005a83b0`, `0x005a2d80`, `0x005a4f70`, and `0x005b83a0`.

Key live MCP facts:

- `lookup_funcs` returned `sub_5A76C0` size `0xbfd`, `sub_5A83B0` size `0x3fd`, `sub_5A2530` size `0x72b`, `sub_5B83A0` size `0x7`, `sub_5A4F70` size `0x9f`, and `sub_5A2D80` size `0x17`.
- `xrefs_to 0x005a76c0` returned only data ref `0x0062efa0`; `xrefs_to 0x005a83b0` returned only data ref `0x0062efc4`.
- `xrefs_to 0x0062ef0c` returned constructor/destructor/scalar destructor refs at `0x005a25b7`, `0x005a2c8b`, and `0x005b8262`.
- `xrefs_to 0x0069b4cc` returned 16 refs, including [UID:0003VB] refs at `0x005a7cf9`, `0x005a7d42`, `0x005a7d49`, and `0x005a7dba`, MapPane timer refs, `0x005abc70`, clear helper `0x005b7610`, and scalar destructor clear `0x005b79d6`.
- `xrefs_to 0x0069bee0` returned four refs at `0x005a2d88`, `0x005a2da3`, `0x005a2dc6`, and `0x005b6df4`.
- `xrefs_to 0x0069bf34` returned six refs at `0x0041a4b7`, `0x004f84c5`, `0x004f8a2c`, `0x00502445`, `0x005b834e`, and `0x0060c450`.
- `xrefs_to 0x0069bf6c` returned refs at `0x005a4fba` and `0x005a686f`; `xrefs_to 0x0069bf70` returned refs at `0x005a4fff` and `0x005a68a4`.
- Active bytes for `0x0069b4cc`, `0x0069bee0`, `0x0069bf34`, and `0x0069bf6c-0x0069bf73` are zero-filled in the active IDB.
- `decompile 0x005a2d80` is exactly `_wcscpy_s(&unk_69BEE0, 0x20u, Source)`.
- `decompile 0x005a4f70` sends opcode `45`, subtype `0`, through `dword_67A7EC`, then stores the argument to `unk_69BF6C` when `byte_66DA97 == 1` and to `unk_69BF70` otherwise.
- `analyze_function 0x005a76c0` reports a 3069-byte, 99-basic-block, cyclomatic-complexity 54 switch handler with 52 callees and case comments for many packet opcodes.
- `decompile 0x005a83b0` shows only four top-level source branches: local event `20`, timer `1097094982` (`FWdA`), timer `1148076358` (`FAnD`), and default delegation to `sub_53B830`; it also shows the method's `this` is an adjusted facet whose LivingObjectPane base is `this - 164`.

## Positive Evidence

- The file owner [UID:0000P1] is still correct. The constructor/destructor, vtable slots, `g_pUserPane`, local-player name buffer, UserPane pool, command dwords, and collection layout all route through the local-player/user pane source family.
- [UID:0000FQ] is now declaration-ready at class-shell level. Exact child pages should still own method bodies, but a declaration with `[[CHILDREN]]`, virtual method prototypes, and known public helper prototypes is useful source output and does not duplicate method bodies.
- [UID:0003EE], [UID:0002AA], [UID:0002AC], [UID:00030A], and [UID:0001TZ] are source-declaration/data/type items with enough current evidence for exact formal insertion text.
- [UID:0002W8] is a duplicate backing memory slot for [UID:0003EE] and should not emit a second global definition.
- [UID:0002YU] is generated vtable bytes. The vtable cells are rebuild-relevant, but they should be regenerated from `UserPane` declarations and virtual method definitions rather than hand-authored as pointer arrays.
- [UID:0001KL] is a real source-owner aggregate but is not a source function. Its formal block should be a no-code container proof, not a code body.
- [UID:0003VB] and [UID:0003VD] have stronger evidence now, but that evidence argues against decompiler-shaped whole-method formal C++ in this pass. The report below supplies exact no-current-improvement proof/comments rather than leaving them as generic "future C++".

## Negative Evidence

- No hidden direct caller route to [UID:0003VB] or [UID:0003VD] exists beyond UserPane vtable data refs in the current IDB.
- [UID:0003VB] is too broad for safe first-draft whole-method C++: current MCP reports 99 basic blocks, a 128-case switch comment, 52 callees, and many packet/UI helper dependencies. Current docs resolve some routes (`0x04`, `0x0a`, `0x36`, `0x3e`, `0x58`) but not every payload struct and local state name.
- [UID:0003VD] is smaller, but the live decompile shows an adjusted-facet receiver (`this - 164` recovers the LivingObjectPane base) and many unnamed adjusted offsets (`+288`, `+289`, `+290`, `+360`, `+1261652`, `+1305140`, `+1305144`, `+1305165..+1305210`). A formal C++ body with those raw offsets would be worse than no C++ and would freeze decompiler-shaped member names.
- `InputBlockerPane` has no current class page. That does not block the pointer declaration: a forward declaration plus the singleton definition is source-ready. It does block pretending a full `InputBlockerPane` class declaration exists in this pass.
- The old [UID:00030A] item summary still says initialized `0xffffffff` and assignment withheld. Fresh docs and live MCP show zero-filled bytes and current owner/emitter [UID:0000P1].
- The missing exact `0x005a4f70` by-memory page does not block [UID:00030A] storage C++. The current marker is the data declaration, and the helper decompile is sufficient evidence for naming the two slots. Creating a helper page is outside the current empty-marker list and should not be used as a deferral reason for the data.

## Heuristic / Inference Reanalysis And Validation

The strongest improvement route is not to force every empty marker into executable source. It is to classify each marker by actual source role:

- Declaration emitters: [UID:0000FQ], [UID:0003EE], [UID:0002AA], [UID:0002AC], [UID:00030A], and [UID:0001TZ].
- No-duplicate/no-code artifacts: [UID:0002YU], [UID:0002W8], and [UID:0001KL].
- Rare no-current-improvement executable handlers: [UID:0003VB] and [UID:0003VD].

This closes the named blockers without claiming original names that are not supported. The current docs' "future C++" wording should be replaced with target-specific dispositions. Where formal source is ready, exact insertion text is below. Where it is not safe, exact formal no-code/no-current-improvement comments are below so the generated output no longer carries unexplained empty markers.

## Ranked Ownership And Source Placement

1. [UID:0000P1] `UserPane.cpp` remains the by-file owner for the family. It owns the local-player pane, singleton, file-scope local-player name buffer, concrete `UserPane` pool declaration, local-player command state, and server/key/animation UI event surface.
2. [UID:0000FQ] `UserPane` remains the class owner for class declarations, vtable-generated data, and exact virtual method children.
3. [UID:0003EE] `g_pInputBlockerPane` is the direct source declaration owner for the exact [UID:0002W8] memory slot. [UID:0000P1] remains the current file-level placement because [UID:0003VB] has the strongest create/destroy lifecycle evidence.
4. [UID:0000MM]/[UID:0000AM] `PoolAllocator` own allocator mechanics only. [UID:0002AC] remains a concrete `UserPane.cpp` pool declaration, not a `PoolAllocator.cpp` global.
5. `LivingObjectPane`, `MapPane`, `IconsPane`, `TabPane`, `SayInputPanes`, `Chatting`, `FunctionObjects`, `UserLookPane`, `SelfLookPane`, and `UserStatusPane` remain dependencies, callers, or neighboring owners. None should take ownership of this empty-emitter family.

## Split / Range / Container Analysis

- [UID:0001KL] should remain a broad aggregate/index and should not emit executable C++. Its range spans multiple exact children plus excluded helper islands and compiler switch-table children. This is a no-code container disposition, not a failure to reconstruct the actual children.
- [UID:0002YU] is a vtable-data child ending where `InputBlockerPane` vtable data begins. It should remain as documentation of the generated vtable cells, but source emission belongs to [UID:0000FQ] and exact virtual children.
- [UID:0002W8] is the exact backing dword for [UID:0003EE]. It should not duplicate the global definition.
- [UID:0002AA] is exactly `0x40` bytes, matching 32 wide characters. No split is indicated.
- [UID:0002AC] is exactly one `0x28`-byte `PoolAllocator` object. No split is indicated; adjacent `0x0069bf5c` is a separate `g_pQuitInputPane` slot.
- [UID:00030A] is exactly two dwords with two refs per slot and no tail-byte refs. No split is indicated.
- [UID:0001TZ] should emit type declarations only. It is a nested `UserPane` local-player layout view, not a separate allocation owner.

## Score And Metadata Recommendations

| UID | Recommended metadata | Rationale |
| --- | --- | --- |
| `0000P1` | Raise to `COMPLETION:90`, `CONFIDENCE:87`; keep `CANONICAL_OWNER:FILE`. | Empty-emitter family dispositions become implementation-ready; remaining caps are large handler/body and exact original field names. |
| `0000FQ` | Raise to `88/88`; keep owner/emitter `0000P1`; populate class declaration C++. | Class shell is ready while method bodies stay child-owned. |
| `0003VB` | Keep `87/89`; keep owner/emitter `0000FQ`; populate exact no-current-improvement comment. | Evidence improved but still rejects whole-method first draft. |
| `0003VD` | Raise to `87/89`; keep owner/emitter `0000FQ`; populate exact no-current-improvement comment. | Fresh decompile resolves top-level branch shape but proves adjusted-offset naming is not source-ready. |
| `0002YU` | Keep `88/91`; keep owner/emitter `0000FQ`; populate exact no-code vtable comment. | Vtable bytes are generated from declarations. |
| `0003EE` | Raise to `87/90`; keep owner/emitter `0000P1`; populate singleton definition. | Pointer type and zero initializer are source-ready. |
| `0002W8` | Keep `87/91`; keep owner/emitter `0003EE`; populate no-duplicate backing-slot comment. | Global definition belongs to [UID:0003EE]. |
| `0001KL` | Keep `88/88`; keep owner/emitter `0000P1`; populate aggregate no-code comment. | Broad aggregate should not emit a fake function. |
| `0002AA` | Raise to `88/91`; keep owner/emitter `0000P1`; populate `wchar_t[32]` definition. | Exact size and xrefs are current. |
| `0002AC` | Raise to `91/90`; keep owner/emitter `0000P1`; populate concrete pool declaration. | Pool type/API docs now support declaration shape. |
| `00030A` | Raise to `88/90`; keep owner/emitter `0000P1`; populate two dword definitions and fix stale summary. | Fresh MCP confirms zero-fill and exact writer refs. |
| `0001TZ` | Raise to `88/89`; keep owner/emitter `0000P1`; populate layout structs. | Existing declaration hypothesis is ready enough for formal type output with caveats. |

## First-Draft C++ Or No-Code Proof

### [UID:0000FQ] `by-class/UserPane.md`

Exact formal insertion:

```cpp
class UserPane : public LivingObjectPane
{
public:
    UserPane();
    virtual ~UserPane();

    virtual void OnBoundsChanged(const RectBounds *bounds);
    virtual void OnClipBounds(RectBounds *clip, RectBounds *out);
    virtual void ShowNameLabel();
    virtual void HideNameLabel();
    virtual bool OnKeyEvent(const PaneKeyEvent *event);
    virtual bool OnServerMessage(const ServerMessageEvent *event);
    virtual bool OnAnimationStep(int message, int frameOrDirection, int aux);
    virtual MapPane *GetMapPane();

    void SendGiveItemPacket(signed char slot, bool allItems);
    void SendDropItemPacket(signed char slot, bool allItems);

private:
    [[CHILDREN]]
};
```

Rationale: declaration-level output is now safe. The known method bodies still belong on exact by-memory children.

### [UID:0003VB] `UserPaneHandleServerMessage`

Exact formal no-current-improvement insertion:

```cpp
// No whole-method reconstruction is currently entered for
// UserPane::OnServerMessage. Current IDA MCP evidence proves this is the
// live UserPane vtable dispatcher at 0x005a76c0 with a 128-case packet
// switch, event payload pointer/size at event +0x0c/+0x10, inline opcode
// 0x04 and 0x36 bodies, and delegated packet helpers for resolved cases.
// The remaining packet cases and payload-local field names are not
// source-quality enough for a behavior-complete formal C++ body without
// freezing decompiler-shaped offsets or inventing helper calls.
```

This is a rare no-current-improvement proof, not a future-deferral placeholder. Current evidence routes were checked: target/support docs, prior opcode route reports, fresh `analyze_function`, vtable xrefs, and current generated output. A partial case-only method body would misrepresent the source. A whole-method body with 99 basic blocks and unresolved packet structs would reduce source quality.

### [UID:0003VD] `UserPaneHandleAnimationStep`

Exact formal no-current-improvement insertion:

```cpp
// No whole-method reconstruction is currently entered for
// UserPane::OnAnimationStep. Current IDA MCP decompilation proves the
// top-level dispatch on local event 0x14, kLivingTimerForwardStep/FWdA,
// kLivingTimerFrameAnimation/FAnD, and default LivingObjectPane timer
// delegation. The function body is entered through an adjusted facet:
// the LivingObjectPane base is recovered as this - 0xa4, and the
// remaining local movement fields are still offset-named. Emitting a
// formal body now would freeze adjusted-base offsets and decompiler-shaped
// field names rather than source-quality UserPane members.
```

This closes the current blocker without deferring the evidence work. Fresh MCP verified the full branch shape; the remaining unsafe part is not the event constants but the adjusted object model and local movement fields.

### [UID:0002YU] `UserPaneVtableData`

Exact formal no-code insertion:

```cpp
// UserPane vtable bytes are compiler-generated from the UserPane class
// declaration and exact virtual method definitions. Do not hand-author
// the 0x0062ef0c-0x0062efcc pointer cells as source data.
```

### [UID:0003EE] `g_pInputBlockerPane`

Exact formal insertion:

```cpp
class InputBlockerPane;

InputBlockerPane *g_pInputBlockerPane = 0;
```

This is safe even before a full `InputBlockerPane` class page exists; the source can forward-declare the class and define the singleton pointer.

### [UID:0002W8] `InputBlockerPaneSingleton`

Exact formal no-duplicate insertion:

```cpp
// Backing storage for g_pInputBlockerPane is emitted by [UID:0003EE].
// This exact memory page documents the 0x0069b4cc slot and xrefs only.
```

### [UID:0001KL] broad `UserPane` aggregate

Exact formal no-code insertion:

```cpp
// Broad UserPane executable aggregate. Formal source is emitted by exact
// children such as UserPane methods, file-scope globals, and layout pages.
// Do not emit one synthetic C++ body for 0x005a2530-0x005b8395.
```

### [UID:0002AA] `LocalPlayerNameWideBuffer`

Exact formal insertion:

```cpp
wchar_t g_localPlayerName[32] = { 0 };
```

### [UID:0002AC] `UserPanePoolStaticStorage`

Exact formal insertion:

```cpp
static PoolAllocator g_userPanePool(sizeof(UserPane), 2);
```

This relies on [UID:0000AM] `PoolAllocator` constructor `PoolAllocator(int blockSize, int blocksPerChunk)` and the static wrapper evidence `sub_4B13D0(byte_69BF34, 1305476, 2)`.

### [UID:00030A] `Opcode2dCommandExtraValueSlots`

Exact formal insertion:

```cpp
static int g_opcode2dEpfCommandExtraValue = 0;
static int g_opcode2dLegacyCommandExtraValue = 0;
```

Name rationale: live `0x005a4f70` writes the first slot when `g_useEpfAssets`/`byte_66DA97 == 1` and the second otherwise. The stale `0xffffffff` initialization wording should be removed; current bytes are zero.

### [UID:0001TZ] `CollectionPlayerDataLayout`

Exact formal insertion:

```cpp
struct CollectionEntryRecord
{
    SimpleUString shortName;
    SimpleUString entryName;
    SimpleUString description;
    unsigned char collectedFlag;
    unsigned char reserved[3];
};

struct CollectionGroupRecord
{
    unsigned char loadedFlag;
    unsigned char groupType;
    unsigned char totalEntries;
    unsigned char collectedEntries;
    CollectionEntryRecord entries[128];
};
```

Rationale: the type page already proves a `0x2604` group stride, 4-byte group header, `0x4c` entry stride, three 24-byte `SimpleUString` fields, and a state byte at entry `+0x48`. The names remain feature-view names; the support prose should preserve that caveat.

## Recommended Target / Support Doc Changes

### `by-file/UserPane.md`

- Add this report's family-level empty-emitter audit under Changes/Evidence.
- Raise to `90/87`.
- Replace stale "future C++" wording for current empty markers with explicit dispositions:
  - class declaration ready on [UID:0000FQ];
  - [UID:0003VB]/[UID:0003VD] exact no-current-improvement comments;
  - [UID:0002YU], [UID:0002W8], [UID:0001KL] no-code/no-duplicate comments;
  - concrete source declarations for [UID:0003EE], [UID:0002AA], [UID:0002AC], [UID:00030A], [UID:0001TZ].
- Preserve exclusions for LivingObjectPane, SayInputPanes, Chatting, FunctionObjects, MapPane, BowGaugeObjectPane, UserLook/SelfLook/UserStatusPane, and switch-table children.

### `by-class/UserPane.md`

- Insert the formal class declaration above.
- Raise to `88/88`.
- Preserve the child-first method-body policy: the declaration may emit, but large method bodies still belong to exact children.
- Add a note that [UID:0003VD]'s unresolved blocker is adjusted receiver/local movement field naming, not `FWdA`/`FAnD`.

### `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`

- Replace generic blank-C++ rationale with the exact no-current-improvement formal comment.
- Preserve opcode `0x04`, `0x0a`, `0x36`, `0x3e`, and `0x58` route evidence.
- Keep `87/89`.

### `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md`

- Insert the exact no-current-improvement formal comment.
- Raise to `87/89`.
- Add fresh MCP evidence: full decompile top-level branch shape and adjusted facet `this - 0xa4`.

### `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md`

- Insert the exact no-code vtable comment.
- Fill the empty `Item Summary` with: `UserPane vtable pointer cells generated from the class declaration; exact slots and constructor/destructor refs documented, no hand-authored vtable C++.`

### `by-global/g_pInputBlockerPane.md`

- Insert the exact singleton definition.
- Raise to `87/90`.
- Update stale `ff ff ff ff` wording to current zero initialization.
- Make clear that the lack of a full `InputBlockerPane` class page does not block a forward-declared pointer definition.

### `by-memory/0x0069b4cc-0x0069b4d0.InputBlockerPaneSingleton.md`

- Insert the exact no-duplicate backing-slot comment.
- Keep [UID:0003EE] as owner/emitter and current scores.
- Preserve the 16-xref evidence and UserPane server-message lifecycle route.

### `by-memory/0x005a2530-0x005b8395.UserPane.md`

- Insert the broad aggregate no-code comment.
- Keep `88/88`.
- Preserve the exact child/source-placement inventory and no-owner rejection.

### `by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md`

- Insert the exact `wchar_t[32]` formal definition.
- Raise to `88/91`.
- Preserve the helper evidence for `0x005a2d80`, `0x005a2da0`, `0x005a2dc0`, and block-list validation.

### `by-memory/0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage.md`

- Insert the exact `PoolAllocator` declaration.
- Raise to `91/90`.
- Cross-reference [UID:0000AM] and [UID:0000TI] for constructor/API shape.

### `by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md`

- Insert the two formal dword definitions.
- Raise to `88/90`.
- Fix stale Item Summary to remove `0xffffffff` and "assignment withheld"; current bytes are zero and owner/emitter are [UID:0000P1].
- Remove "final C++ remains blank because helper split unresolved"; the data declaration is source-ready even without an exact helper child.

### `by-type/by-struct/CollectionPlayerDataLayout.md`

- Insert the exact `CollectionEntryRecord` and `CollectionGroupRecord` declarations.
- Raise to `88/89`.
- Keep caveats that names are feature-view names inside the large `UserPane` object, not proof of a standalone allocation.

## Claim And Incorporation Ledger

| Claim | Destination | Action | Verification state |
| --- | --- | --- | --- |
| [UID:0000P1] remains the by-file owner for this family and should rise to `90/87`. | `by-file/UserPane.md` | incorporate | applied - header is `COMPLETION:90` / `CONFIDENCE:87`; section `2026-07-01 Empty-Emitter Family Dispositions` lists all audited UIDs. |
| [UID:0000FQ] should emit declaration-level class C++ with `[[CHILDREN]]`. | `by-class/UserPane.md` | incorporate | applied - `RECONSTRUCTION_CPP CODE` contains `class UserPane : public LivingObjectPane` with accepted virtual prototypes and `[[CHILDREN]]`; validator `000000003857` refreshed generated output. |
| [UID:0003VB] should not receive whole-method first-draft C++; use exact no-current-improvement formal comment. | `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md` | incorporate | applied - `RECONSTRUCTION_CPP CODE` contains the accepted no-current-improvement comment and the prose preserves the 128-case packet switch, payload pointer/size, opcode `0x04`/`0x36`, and delegated packet-helper evidence. |
| [UID:0003VD] should not receive whole-method first-draft C++; use exact adjusted-this no-current-improvement formal comment. | `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` | incorporate | applied - header is `87/89`; code block contains the accepted no-current-improvement comment and evidence names the adjusted receiver as `this - 164` / hex `0xa4`. |
| [UID:0002YU] vtable data should emit only a no-hand-authored-vtable comment. | `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md` | incorporate | applied - `RECONSTRUCTION_CPP CODE` contains the accepted vtable no-code comment and `Item Summary` is filled with compiler-generated vtable wording. |
| [UID:0003EE] should emit `InputBlockerPane *g_pInputBlockerPane = 0` with a forward declaration. | `by-global/g_pInputBlockerPane.md` | incorporate | applied - header is `87/90`; code block contains `class InputBlockerPane;` and `InputBlockerPane *g_pInputBlockerPane = 0;`; stale `ff ff ff ff` wording was replaced with zero-initialized evidence. |
| [UID:0002W8] should be documented as backing storage emitted by [UID:0003EE]. | `by-memory/0x0069b4cc-0x0069b4d0.InputBlockerPaneSingleton.md` | incorporate | applied - code block contains the no-duplicate backing-storage comment and prose keeps [UID:0003EE] as owner/emitter with the 16-xref route. |
| [UID:0001KL] should emit only a broad-aggregate no-code comment. | `by-memory/0x005a2530-0x005b8395.UserPane.md` | incorporate | applied - code block contains the broad UserPane executable aggregate no-code comment and source-placement inventory remains child-first. |
| [UID:0002AA] should emit `wchar_t g_localPlayerName[32] = { 0 };`. | `by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md` | incorporate | applied - header is `88/91`; code block contains `wchar_t g_localPlayerName[32] = { 0 };` and helper evidence remains for `0x005a2d80`, `0x005a2da0`, `0x005a2dc0`, and block-list validation. |
| [UID:0002AC] should emit `static PoolAllocator g_userPanePool(sizeof(UserPane), 2);`. | `by-memory/0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage.md` | incorporate | applied - header is `91/90`; code block contains `static PoolAllocator g_userPanePool(sizeof(UserPane), 2);` and PoolAllocator support is cross-referenced. |
| [UID:00030A] should emit two zero-initialized command dwords and remove stale `0xffffffff`/withheld wording. | `by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md` | incorporate | applied - header is `88/90`; code block contains the two zero-initialized dwords and `Item Summary` now describes current zero-initialized EPF/legacy opcode `0x2d` slots. |
| [UID:0001TZ] should emit collection entry/group layout structs with feature-view caveats. | `by-type/by-struct/CollectionPlayerDataLayout.md` | incorporate | applied - header is `88/89`; code block contains `CollectionEntryRecord` and `CollectionGroupRecord`; caveats remain that names are feature-view names inside the large UserPane object. |
| `0x005a4f70` helper split is not required to clear [UID:00030A] storage C++; helper evidence was checked but no exact current empty marker exists. | `by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md` | incorporate | applied - reconstruction notes now state the exact helper split is not required for the data declaration and no helper-split-as-C++-blocker wording remains. |
| `InputBlockerPane` full class page is not required for [UID:0003EE] pointer C++; forward declaration is sufficient. | `by-global/g_pInputBlockerPane.md` | incorporate | applied - ownership decision states that the forward-declared pointer definition is source-ready even without a full `InputBlockerPane` class shell. |
| LivingObjectPane, SayInputPanes, Chatting, MapPane, FunctionObjects, BowGaugeObjectPane, UserLookPane, SelfLookPane, and UserStatusPane are rejected as direct owners for this by-file empty-emitter family. | `by-file/UserPane.md` and affected child docs | incorporate | applied - `by-file/UserPane.md` `Boundaries` and `Changes` preserve those rejected-owner boundaries; [UID:0003VD] still excludes the raw LivingObjectPane helper and [UID:0003VB] keeps the opcode `0x58` helper with LivingObjectPane. |

## Implementation Tracking Checklist

- [x] Edit `by-file/UserPane.md`: raised to `COMPLETION:90`, `CONFIDENCE:87`; added `2026-07-01 Empty-Emitter Family Dispositions`; replaced generic future/blank-C++ wording for the audited markers; preserved rejected-owner boundaries in `Boundaries` and `Changes`.
- [x] Edit `by-class/UserPane.md`: raised to `88/88`; inserted the formal class declaration in `RECONSTRUCTION_CPP CODE`; preserved exact-child method-body policy and the adjusted-this caveat for [UID:0003VD] in reconstruction/emission notes.
- [x] Edit `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md`: inserted the exact no-current-improvement formal comment; preserved opcode route evidence; score remains `87/89`.
- [x] Edit `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md`: raised to `87/89`; inserted the exact no-current-improvement formal comment; added fresh adjusted-facet evidence naming `this - 164` / hex `0xa4`.
- [x] Edit `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md`: inserted the exact no-code vtable comment and filled `Item Summary`.
- [x] Edit `by-global/g_pInputBlockerPane.md`: raised to `87/90`; inserted the formal pointer definition; replaced stale `ff ff ff ff` wording with current zero-initialized evidence; documented forward declaration sufficiency.
- [x] Edit `by-memory/0x0069b4cc-0x0069b4d0.InputBlockerPaneSingleton.md`: inserted the exact no-duplicate backing-storage comment; retained [UID:0003EE] owner/emitter.
- [x] Edit `by-memory/0x005a2530-0x005b8395.UserPane.md`: inserted the exact broad-aggregate no-code comment; preserved child/source-placement inventory.
- [x] Edit `by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md`: raised to `88/91`; inserted `wchar_t g_localPlayerName[32] = { 0 };`.
- [x] Edit `by-memory/0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage.md`: raised to `91/90`; inserted `static PoolAllocator g_userPanePool(sizeof(UserPane), 2);`; cross-referenced PoolAllocator support.
- [x] Edit `by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md`: raised to `88/90`; inserted two dword definitions; fixed stale `Item Summary`; removed helper-split-as-C++-blocker wording for the data.
- [x] Edit `by-type/by-struct/CollectionPlayerDataLayout.md`: raised to `88/89`; inserted formal `CollectionEntryRecord` and `CollectionGroupRecord`; preserved feature-view naming caveats.
- [x] Update this report's Claim And Incorporation Ledger during callback with each row marked `applied`, `already-present`, `excluded-with-reason`, or `blocked` and exact proof. Proof: this section now marks every row `applied`; no accepted item is blocked.
- [x] Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` after implementation. Proof: see `Validator Results` below; all twelve listed commands exited `0` with `ok: 1` and `generated_refresh: completed`.
- [x] Verify `auto-generated/NexusTK/ui/panels/UserPane.cpp` regenerated with no remaining unexplained empty markers for the eleven audited UIDs. Proof: generated header is `validator-command-id: 000000003904`, `validator-refreshed-at: 2026-07-01T15:34:43-04:00`; generated file contains [UID:0000FQ], [UID:0003VB], [UID:0003VD], [UID:0002YU], [UID:0003EE], [UID:0001KL], [UID:0002AA], [UID:0002AC], [UID:00030A], and [UID:0001TZ] with accepted code/comments; [UID:0002W8] is intentionally duplicate backing storage emitted by [UID:0003EE] and has no standalone old empty marker in `UserPane.cpp`. Search for `EMPTY`/`TODO` in the generated file returned no matches.
- [x] No supervisor-owned manual coverage/tracker edits are requested by this report. Generated tracker/coverage refresh was validator-owned only.

## Validator Results

All commands were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with `--apply --queue-timeout 240 --wait-generated`.

| File | Command | command_id | command_timestamp | Exit | ok | Warnings/advisories | Generated refresh |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `by-file/UserPane.md` | `python .\tools\validator.py --mode file --file by-file/UserPane.md --apply --queue-timeout 240 --wait-generated` | `000000003855` | `2026-07-01T15:26:54-04:00` | `0` | `1` | Existing validator advisory noise only: missing-ref UID/autogen child-marker/emitter notices; no fatal diagnostics. | `completed`, `generated_refresh_command_id: 000000003855`, timestamp `2026-07-01T15:26:54-04:00` |
| `by-class/UserPane.md` | `python .\tools\validator.py --mode file --file by-class/UserPane.md --apply --queue-timeout 240 --wait-generated` | `000000003857` | `2026-07-01T15:27:06-04:00` | `0` | `1` | Existing validator advisory noise only; no fatal diagnostics. | `completed`, `generated_refresh_command_id: 000000003857`, timestamp `2026-07-01T15:27:06-04:00` |
| `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md` | `python .\tools\validator.py --mode file --file by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md --apply --queue-timeout 240 --wait-generated` | `000000003859` | `2026-07-01T15:27:24-04:00` | `0` | `1` | Existing validator advisory noise only; no fatal diagnostics. | `completed`, `generated_refresh_command_id: 000000003859`, timestamp `2026-07-01T15:27:24-04:00` |
| `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` | `python .\tools\validator.py --mode file --file by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md --apply --queue-timeout 240 --wait-generated` | `000000003862` | `2026-07-01T15:27:43-04:00` | `0` | `1` | Existing validator advisory noise only; no fatal diagnostics. | `completed`, `generated_refresh_command_id: 000000003862`, timestamp `2026-07-01T15:27:43-04:00` |
| `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md` | `python .\tools\validator.py --mode file --file by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md --apply --queue-timeout 240 --wait-generated` | `000000003865` | `2026-07-01T15:28:12-04:00` | `0` | `1` | Existing validator advisory noise only; no fatal diagnostics. | `completed`, `generated_refresh_command_id: 000000003865`, timestamp `2026-07-01T15:28:12-04:00` |
| `by-global/g_pInputBlockerPane.md` | `python .\tools\validator.py --mode file --file by-global/g_pInputBlockerPane.md --apply --queue-timeout 240 --wait-generated` | `000000003868` | `2026-07-01T15:28:41-04:00` | `0` | `1` | Existing validator advisory noise only; no fatal diagnostics. | `completed`, `generated_refresh_command_id: 000000003868`, timestamp `2026-07-01T15:28:41-04:00` |
| `by-memory/0x0069b4cc-0x0069b4d0.InputBlockerPaneSingleton.md` | `python .\tools\validator.py --mode file --file by-memory/0x0069b4cc-0x0069b4d0.InputBlockerPaneSingleton.md --apply --queue-timeout 240 --wait-generated` | `000000003872` | `2026-07-01T15:29:10-04:00` | `0` | `1` | Existing validator advisory noise only; no fatal diagnostics. | `completed`, `generated_refresh_command_id: 000000003872`, timestamp `2026-07-01T15:29:10-04:00` |
| `by-memory/0x005a2530-0x005b8395.UserPane.md` | `python .\tools\validator.py --mode file --file by-memory/0x005a2530-0x005b8395.UserPane.md --apply --queue-timeout 240 --wait-generated` | `000000003875` | `2026-07-01T15:29:39-04:00` | `0` | `1` | Existing validator advisory noise only; no fatal diagnostics. | `completed`, `generated_refresh_command_id: 000000003875`, timestamp `2026-07-01T15:29:39-04:00` |
| `by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md` | `python .\tools\validator.py --mode file --file by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md --apply --queue-timeout 240 --wait-generated` | `000000003878` | `2026-07-01T15:30:08-04:00` | `0` | `1` | Existing validator advisory noise only; no fatal diagnostics. | `completed`, `generated_refresh_command_id: 000000003878`, timestamp `2026-07-01T15:30:08-04:00` |
| `by-memory/0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage.md` | `python .\tools\validator.py --mode file --file by-memory/0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage.md --apply --queue-timeout 240 --wait-generated` | `000000003881` | `2026-07-01T15:30:37-04:00` | `0` | `1` | Existing validator advisory noise only; no fatal diagnostics. | `completed`, `generated_refresh_command_id: 000000003881`, timestamp `2026-07-01T15:30:37-04:00` |
| `by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md` | `python .\tools\validator.py --mode file --file by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md --apply --queue-timeout 240 --wait-generated` | `000000003885` | `2026-07-01T15:31:08-04:00` | `0` | `1` | Existing validator advisory noise only; no fatal diagnostics. | `completed`, `generated_refresh_command_id: 000000003885`, timestamp `2026-07-01T15:31:08-04:00` |
| `by-type/by-struct/CollectionPlayerDataLayout.md` | `python .\tools\validator.py --mode file --file by-type/by-struct/CollectionPlayerDataLayout.md --apply --queue-timeout 240 --wait-generated` | `000000003887` | `2026-07-01T15:31:37-04:00` | `0` | `1` | Existing validator advisory noise only; no fatal diagnostics. | `completed`, `generated_refresh_command_id: 000000003887`, timestamp `2026-07-01T15:31:37-04:00` |

Generated freshness proof:

- `auto-generated/NexusTK/ui/panels/UserPane.cpp` current header after the validator-owned refresh:
  - `validator-command-id: 000000003904`
  - `validator-refreshed-at: 2026-07-01T15:34:43-04:00`
  - `validator-refresh-source: foreground-generated-refresh`
- Generated output contains the accepted [UID:0000FQ] class declaration; [UID:0003VB] and [UID:0003VD] no-current-improvement comments; [UID:0002YU] vtable no-code comment; [UID:0003EE] forward declaration and pointer; [UID:0001KL] aggregate no-code comment; [UID:0002AA] local-player name buffer; [UID:0002AC] pool declaration; [UID:00030A] command dwords; and [UID:0001TZ] collection structs.
- `Select-String` for `EMPTY` and `TODO` in `auto-generated/NexusTK/ui/panels/UserPane.cpp` returned no matches.
- [UID:0002W8] is deliberately absent as a standalone generated C++ marker because it is duplicate backing storage documented in `by-memory/0x0069b4cc-0x0069b4d0.InputBlockerPaneSingleton.md` and emitted by [UID:0003EE] `g_pInputBlockerPane`.

Lease proof:

- Initial B010 lease batch succeeded for the twelve scoped by-* files before edits. A release attempt after validation reported `Rejected[No active lease]` for each file because the short leases had already expired.
- A second short B010 lease batch succeeded for the same twelve files before the final validator metadata rerun. The post-rerun unlease attempt again reported `Rejected[No active lease]` for each file, meaning no active B010 leases remained.
- `tools/leaser/Agents/Agent-B010/current_leases.md` contains no active B010 rows; only stale Supervisor rows from 2026-06-18 are listed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0000P1-UserPane-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0000P1-UserPane-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T15:37:05","uid":"0000P1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
