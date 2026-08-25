** TARGET-REPORT-UID:0001OR **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001OR g_pCollectionData / g_pUserPane Source-Quality Research

Assignment: `B001-goal2-g_pCollectionData-source-quality-0001OR-20260619`  
Agent: `Agent-B001`  
Target: `[UID:0001OR] source-3/project-documentation/by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`  
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0001OR-g_pCollectionData-source-quality.md`  
Current target score: `85/86` in the target metadata; supervisor-owned coverage row currently says `84% : strong`.

## Report-Only Compliance

This is a report-only B-agent pass. I did not edit any `by-*` documentation file and did not edit `by-memory/-coverage-report.md`.

The only requested implementation-side write for this pass is this report, plus the separate `Agent-B001/notes.md` handoff entry requested by the assignment. The proposed by-* and coverage edits below are supervisor callback instructions only.

## Final Recommendation

Rename the source-facing global from collection-specific `g_pCollectionData` to `g_pUserPane`, keep direct owner/emitter `[UID:0000P1] UserPane`, keep `RECONSTRUCTABLE:TRUE`, and raise the target to `89/90`.

Recommended source-facing declaration:

```cpp
class UserPane;

UserPane *g_pUserPane = 0;
```

Use the definition form on the exact storage page if the supervisor wants this by-memory item to emit the global storage. If the supervisor instead chooses the by-global page as the single emitting page, keep the target C++ block blank and put the same definition there. Do not emit both definitions.

The storage should be treated as a source-level global, not merely binary storage attached to UserPane. The reason is direct and stronger than the current name: the only writes to `0x0067a748` store or clear the active `UserPane *`, and the constructor write is from the UserPane construction path. Collection, player-data, spell, item, chat, fitting-room, heartbeat, screen-dimmer, quit, and party/user-list paths are consumers or typed views of the same object.

Keep these as aliases only:

- `dword_67A748`: IDA/raw storage name.
- `g_pCollectionData`: collection feature view over the same `UserPane` object.
- `g_pPlayerData`: generated/player-state view used by some docs and generated output.
- `g_collectionProgressTable`: collection progress-bar generated view; not a separate global.
- `g_pSpellMan` / generated spell-manager interpretations: reject for this storage; spell paths read a local-player/UserPane spell-command view.

Recommended metadata for the target after callback:

```text
COMPLETION:89
CONFIDENCE:90
CANONICAL_OWNER:0000P1
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000P1
```

Recommended target rename if the supervisor accepts source-facing canonical naming:

```text
from: by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md
to:   by-memory/0x0067a748-0x0067a74c.g_pUserPane.md
```

If the supervisor keeps the physical filename stable for link churn control, update the title and body to `g_pUserPane` while preserving `g_pCollectionData` as a historical alias.

## Evidence Checked

Primary target and exact coverage row:

- `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`
- `by-memory/-coverage-report.md` current `[UID:0001OR]` row

Direct owner/support docs:

- `by-global/g_pCollectionData.md`
- `by-file/UserPane.md`
- `by-class/UserPane.md`
- `by-memory/0x005a2530-0x005b8395.UserPane.md`
- `by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md`
- `by-type/by-struct/CollectionPlayerDataLayout.md`

Representative consumer/support docs:

- `by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md`
- `by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md` through current coverage/support references
- `by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md`
- `by-memory/0x0056e940-0x0056fe75.CollectionPane.md`
- `by-memory/0x005add20-0x005add8a.QuitInputPaneConfirmInput.md` through current target references
- Spell input and dispatch support references on the target and global pages
- Item/gold input support references on the target and global pages
- User-list/party-search state support reference in `by-memory/0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag.md`
- Current B001 reports that mention the alias set, including `000250-CollectionReadOnlyData-source-quality.md`

Raw binary checks:

- `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- PE image base: `0x00400000`.
- Relevant sections:
  - `.text` RVA `0x1000`, virtual size `0x20b4ac`, raw `0x400`, raw size `0x20b600`.
  - `.rdata` RVA `0x20d000`, virtual size `0x5f0be`, raw `0x20ba00`, raw size `0x5f200`.
  - `.data` RVA `0x26d000`, virtual size `0x2fe24`, raw `0x26ac00`, raw size `0xd800`.
- Raw bytes for `0x0067a738-0x0067a768`: all zero, matching the target's zero-initialized pointer-window note.
- Exact little-endian VA needle `48 a7 67 00` occurs `505` times in `.text`, matching the target/global xref count. No RVA/raw-offset needle variant was needed for this storage.
- Per-needle Capstone backtracking decoded `505` unique instructions containing memory operands to `[0x67a748]`.

Scoped validator baseline:

_Executable command block removed from the research report; preserved in [0001OR-g_pCollectionData-source-quality-removed.md](0001OR-g_pCollectionData-source-quality-removed.md)._

The validator baseline did not edit the target because `--apply` was not used.

## Raw Xref And Lifetime Findings

The strongest source-quality fact is the write set. I found only five writes to `0x0067a748`; all five are UserPane construction, destruction, or clear paths:

| Address | Instruction | Source-quality role |
| --- | --- | --- |
| `0x005a2587` | `mov dword ptr [0x67a748], eax` | UserPane constructor stores `this` after deriving the object pointer from the constructed subobject. |
| `0x005a258e` | `mov dword ptr [0x67a748], 0` | UserPane constructor null/fallback path clears the singleton. |
| `0x005a2d55` | `mov dword ptr [0x67a748], 0` | Non-deleting UserPane destructor clears the singleton after child/state cleanup. |
| `0x005b7640` | `mov dword ptr [0x67a748], 0` | Tiny singleton clear helper; best source-facing role is `ClearUserPaneSingleton` / `ResetUserPaneGlobal` if modeled separately. |
| `0x005b832c` | `mov dword ptr [0x67a748], 0` | Scalar deleting UserPane destructor clears the singleton before optional pool return/delete. |

Representative decoded constructor context:

```asm
005a2570  lea     esi, [ebx + 0x20c]
005a257d  test    esi, esi
005a257f  je      0x5a258e
005a2581  lea     eax, [esi - 0x20c]
005a2587  mov     dword ptr [0x67a748], eax
005a258c  jmp     0x5a2598
005a258e  mov     dword ptr [0x67a748], 0
```

That is not a collection-data allocation. It is the active `UserPane` object pointer stored at module/global scope.

Representative decoded heartbeat context:

```asm
00466f15  cmp     dword ptr [0x67a748], 0
00466f1c  je      0x467037
...
00466fef  mov     eax, dword ptr [0x67a748]
00466ff4  test    eax, eax
00466ff6  je      0x467037
00466ff8  mov     bl, byte ptr [eax + 0x1a0]
```

`CheckTimerSkewAndSendHeartbeat` is therefore an Application/message-loop consumer that gates a heartbeat/status packet on the active UserPane pointer and reads byte `+0x1a0`; it is not an owner of the storage.

Representative xref bands from the `505` decoded references:

| Band | Count | Writes | Representative addresses | Meaning |
| --- | ---: | ---: | --- | --- |
| FittingRoomDialog band | `4` | `0` | `0x0041be9c`, `0x0041bee0`, `0x0041c329`, `0x0041c422` | Fitting-room consumer views; no ownership. |
| Early/Application/misc band | `39` | `0` | includes heartbeat `0x00466f15`, `0x00466fef` | Application and early UI consumers, not owner. |
| Chatting/UI band | `15` | `0` | `0x00480cfd` through `0x00481ee6` | Chatting variety/current mode and input-lock consumers. |
| CollectionDialogControls | `23` | `0` | `0x0048c77b` through `0x0048dcb9` | Collection detail dialog/control typed view. |
| DialogSession/ScreenDimmer | `2` | `0` | `0x004a12e1`, `0x004a1300` | ScreenDimmer parent-selection consumer through a UserPane subobject/view. |
| Other middle `.text` consumers | `290` | `0` | `0x004a2482` through `0x005c48c0` | Broad local-player/client-state use; not collection-specific. |
| CollectionPane | `14` | `0` | `0x0056ea5d` through `0x0056fcb4` | Collection summary pane metadata/list/detail request view. |
| UserPane constructor/destructor | `3` | `3` | `0x005a2587`, `0x005a258e`, `0x005a2d55` | Direct lifetime owner. |
| LivingObjectPane local-player extensions | `52` | `0` | `0x005a2ef9` through `0x005ac61d` | Movement/spell/action/target local-player views; not owner. |
| Quit/map transition input | `2` | `0` | `0x005add5a`, `0x005adda3` | Quit confirmation timer-owner view at `+0xa4`. |
| Spell/Input/UserPane tail | `61` | `2` | includes `0x005b7640`, `0x005b832c` | Spell/input consumers plus the clear helper and scalar destructor clear. |

The xref breadth explains why generated names disagree. The write set explains ownership and type.

## Heuristic / Inference Reanalysis And Validation

### Source-facing global name

Best-supported canonical source-facing name: `g_pUserPane`.

Evidence:

- The storage receives the constructed `UserPane *` in the UserPane constructor at `0x005a2587`.
- The storage is cleared by UserPane cleanup/destructor paths at `0x005a258e`, `0x005a2d55`, `0x005b7640`, and `0x005b832c`.
- `by-file/UserPane.md`, `by-class/UserPane.md`, and `by-memory/0x005a2530-0x005b8395.UserPane.md` already document the same construction/destruction path as UserPane lifetime, with the large local-user object, vtables, child/state arrays, and cached `MapPane *m_mapPane`.
- The direct source owner is a UI pane module, and this codebase already uses `g_p...Pane` names for active pane singletons. `g_pUserPane` fits that source pattern better than a generic `g_pPlayerData` name.

Rejected canonical names:

- Reject `g_pCollectionData` as canonical: it is a real and useful collection-view alias, but collection paths contribute only a minority of the 505 xrefs and never write the slot.
- Reject `g_pPlayerData` as canonical storage name: it describes many field uses, but the value stored is a vtable-bearing `UserPane *`, not an independently allocated player-data struct.
- Reject `g_collectionProgressTable` as canonical: it is a generated view for the CollectionBar/progress reader, not a process-wide storage declaration.
- Reject `g_pLocalPlayer` as canonical for now: it captures the local-player semantics, but the documented class and construction evidence identify the object as UserPane. A future source-symbol dump could prove a different original spelling, but the best reconstruction name from binary/docs is `g_pUserPane`.

Confidence on exact spelling is high but not absolute. The binary proves the type and owner; it does not store original source symbol names. `g_pUserPane` is the best source-quality name because it matches type, owner, and project naming style.

### Source-facing type

Best-supported type: `UserPane *`.

Evidence:

- The constructor write stores the same object that immediately receives UserPane vtables and UserPane field initialization.
- Destructor and scalar deleting destructor clear the same global after running UserPane cleanup.
- The active `MapPane *m_mapPane` accessor at `0x005b83a0` and UserPane docs show this is a large pane object with UI graph state, not a standalone POD record.

Typed-view guidance:

- Treat collection offsets as `UserPane` nested local-player/collection state.
- Treat spell, item, chat, fitting, heartbeat, and party-search offsets as feature-specific views into the same object.
- Do not invent separate `CollectionData *`, `PlayerData *`, or `CollectionProgressTable *` globals for this address.

### Owner and source placement

Best-supported direct owner/emitter: `[UID:0000P1] UserPane`, source path `NexusTK/ui/panels/UserPane.cpp`.

Evidence:

- Only UserPane code writes the slot.
- The UserPane file and class pages already satisfy the strict direct-parent gate and identify this as the local user/player pane module.
- CollectionPane, CollectionDialogPane, Chatting, FittingRoom, Application heartbeat, ScreenDimmer, QuitInputPane, and user-list/party-search docs are consumer contexts.

Source placement should be file/module-level, not a class data member. The global declaration belongs near UserPane module statics in `UserPane.cpp`; methods read and write it through global storage. The class page can reference it, but the direct source declaration belongs to the by-file emitter route.

### Source-level global versus binary-only storage

This should emit as a source-level global declaration if callback policy allows the target/by-global page to emit exact data storage.

No-code proof is not appropriate for the target because:

- The bytes are zero-initialized writable `.data`, not vtable/RTTI/compiler-only output.
- The storage has explicit source-level lifetime stores and clears.
- It is a singleton/global pointer used from many modules.
- A minimal definition `UserPane *g_pUserPane = 0;` captures the storage and type without freezing uncertain nested field layouts.

The only emission caution is duplicate-definition avoidance: choose exactly one page, target or by-global, to carry the definition.

### Field and typed-view inference

The global storage type can be resolved even though many member fields remain feature-view names. Best-supported field/type directions:

| Offset/view | Best source-facing role | Evidence and closure |
| --- | --- | --- |
| `+0xa4` | `TimerHandler`/timer-owner subobject view inside UserPane | `QuitInputPaneConfirmInput` passes `dword_67A748 + 0xa4` to `TimerMgr::RemovePendingTimersForOwner` before `MapPane::ExitToMenu(true)`. Treat as a subobject/view, not a separate global. |
| `+0x1a0` | heartbeat/session byte, best provisional role `m_heartbeatSeedByte` | Heartbeat helper reads one byte and combines it into the `0x60` heartbeat/status packet. I found no stronger semantic source name in current docs; this does not block global C++ because it is not needed for the global declaration. |
| `+0x3cb1` | party-search/hunters-list local-player flag | `UserListDialogHuntersListOnlyFlag` documents `g_pPlayerData+0x3cb1` and the `"Put me on the hunters list"` path. This is a local-player/UserPane state view. |
| `+0x3eb4` | current chat variety/mode | ChattingVarietyPane coverage identifies this as the current chat mode used for Talk/Shout/Whisper/Group/Clan display. |
| `+0x3ec0` | item/gold command busy gate | Drop/give/throw paths check the byte before packet sends; best name is `m_itemCommandBusy` or `m_inventoryCommandBusy`, not collection data. |
| `+0x3ec8 + group * 0x2604` | collection group record base | Collection loader, list, detail dialog, and progress controls agree on the group stride/header. Keep as `CollectionGroupRecord` typed view inside UserPane/local-player state. |
| `+0x1340c8` | collection group count | Collection metadata loader writes it and collection list/detail paths consume it. |
| `+0x1340c9` | collection metadata loaded/groups loaded flag | Existing docs call this metadata loaded. Current evidence does not prove a broader name; keep `m_collectionMetadataLoaded` as the best feature-specific field name. |
| `+0x1340f8` | `MapPane *m_mapPane` | Already resolved by B001 on `UserPaneGetMapPane`; constructor copies `g_activeMapPane` and writes inverse `MapPane+0x418 = this`. |
| `+0x13a6ec + slot * 0x148` | spell/command slot record base | ChangeSpellSlotInputPane, spell constructors, accept path, and command-slot dispatch all use this slot record. |
| `+0x13a794 + slot * 0x148` | spell prompt/name text | Spell input constructors read prompt/name text from this offset. |
| `+0x13a834 + slot * 0x148` | spell learned/active flag | Available-slot helper and dispatch paths read this byte. |
| `+0x13ead4` | spell slot active/guard/dirty flag | Spell-change and dispatch paths check/clear it. |
| `+0x13eb1d` | local UI/input lock, collection/chat feature-view alias | Collection docs call it collection input lock; ChattingVarietyPane also uses it as a local-player/UserPane input-lock gate. Best broad field name is `m_localInputLocked` or `m_inputLocked`; keep `collectionInputLock` as a feature-view alias until a full class-layout pass chooses exact member spelling. |

Unresolved field names above are not generic future work. The exact original source spellings cannot be recovered from these operands alone because all field references are numeric offsets into a large object. The report resolves their roles to high-probability names/views and isolates the only truly unsafe part: exact original member spelling. That uncertainty does not block emitting the global pointer declaration.

### Compiler/generated names and replacements

| Current/generated name | Source-quality replacement |
| --- | --- |
| `dword_67A748` | raw storage for `UserPane *g_pUserPane` |
| `g_pCollectionData` | collection typed-view alias of `g_pUserPane` |
| `g_pPlayerData` | local-player/player-state typed-view alias of `g_pUserPane` |
| `g_collectionProgressTable` | collection-progress typed-view alias of `g_pUserPane`; do not create a second global |
| `sub_5A2530` | `UserPane::UserPane` constructor |
| `sub_5A2C60` | ordinary/non-deleting UserPane destructor cleanup body |
| `sub_5B8230` | UserPane scalar deleting destructor |
| `0x005b7640` raw clear helper | best role `ClearUserPaneSingleton` / `ResetUserPaneGlobal`; tiny helper body only clears `g_pUserPane` |
| generated `SpellManager` / `g_pSpellMan` readings of the same address | reject; spell-command state is a UserPane/local-player typed view |

### Caller/reachability

This is data, not a callable function, so reachability is through data reads/writes.

Lifetime reachability is proven by direct writes from UserPane constructor and destructor/clear paths. Consumer reachability is broad and multi-module: the raw `.text` scan found 505 direct references, matching current docs. The direct-write proof is the decisive owner evidence; consumer xrefs explain why generated names vary.

### Split/range decision

Keep the exact range `0x0067a748-0x0067a74c`.

Evidence:

- Raw `.data` bytes show a zero-initialized four-byte slot.
- Neighboring slots are separate four-byte globals: predecessor `0x0067a744-0x0067a748.g_pEPFLib`, successor `0x0067a74c-0x0067a750.g_pApplicationCleanupQueue`, and following slot `0x0067a750`.
- The target covers exactly the pointer storage; no merge with neighboring pointer globals is warranted.

If renamed, rename the file/title but keep the UID and exact range. Do not split aliases into multiple pages.

### False ownership alternatives

Reject `CollectionPane` / `CollectionDialogPane` ownership. Collection has strong read/use evidence and a well-modeled nested layout, but no writes to the global. Collection docs should describe typed views over `g_pUserPane`.

Reject `Application` ownership. The heartbeat helper reads the global and a byte at `+0x1a0`, but its owned state lives in Application heartbeat/timer globals around `0x0067ab5c-0x0067ab70`. It only gates packet construction on the active local user.

Reject `Chatting` ownership. ChattingVarietyPane reads mode/input-lock state; it does not own the singleton storage.

Reject `FittingRoom` ownership. Fitting-room paths are read-only consumers of local player/item/catalog state.

Reject `LivingObjectPane` ownership for the storage. LivingObjectPane local-player extension paths read many offsets, but the global value is still written by UserPane construction/destruction. LivingObjectPane remains the owner of movement/object helper code where docs prove that source placement.

Reject standalone `PlayerData` ownership. `PlayerData` is a useful typed-view name, but the stored pointer is the active pane object. If a future full layout pass creates a nested `UserPanePlayerState` type, that should be a member/view type, not a second process-wide global for `0x0067a748`.

## Consumer Semantics To Preserve

Collection:

- Group count `+0x1340c8`, metadata-loaded flag `+0x1340c9`, group base `+group * 0x2604 + 0x3ec8`, and entry record stride `0x4c` remain correct typed views.
- `CollectionPlayerDataLayout` should be reframed as a nested UserPane/local-player collection view.
- `g_collectionProgressTable` should be removed as a separate-global implication and kept only as a generated progress-view alias.

Spell/local command:

- Spell slot record base `+0x13a6ec + slot * 0x148`, prompt/name `+0x13a794`, learned/active `+0x13a834`, and guard/dirty byte `+0x13ead4` are views of the same UserPane object.
- Do not model these as a separate `SpellManager` singleton.

Item/gold/player-name:

- Drop/give/throw item/gold paths use byte `+0x3ec0` as a busy/guard gate before sending packets.
- Wield/wear/throw/use/eat constructors call the local player-name helper with this pointer. That reinforces UserPane/local-player state.

Chatting:

- ChattingVarietyPane reads current chat variety/mode at `+0x3eb4`.
- The same feature also uses the local input-lock view at `+0x13eb1d`; this argues for a broader `m_inputLocked` role rather than a collection-only field name.

FittingRoom:

- Four raw refs in the fitting-room band are read-only consumer evidence. They are important because they broaden the state beyond collection, but they do not affect ownership.

Heartbeat/Application:

- `CheckTimerSkewAndSendHeartbeat` checks `g_pUserPane` non-null and reads byte `+0x1a0` when building the heartbeat/status packet. Keep Application as owner of the heartbeat helper and timer globals; keep UserPane as owner/type of this pointer.

ScreenDimmer/Dialog:

- `CreateScreenDimmerFactory` uses a subobject/view around `+0x214` for parent-selection semantics. This is another consumer of active UI/local-player state.

Quit/map transition:

- `QuitInputPaneConfirmInput` uses `+0xa4` as a nullable timer-owner subobject passed to `TimerMgr::RemovePendingTimersForOwner` before exiting to menu.

Party/user list:

- `UserListDialogHuntersListOnlyFlag` documents `g_pPlayerData+0x3cb1` for hunters-list/party-search state. That should be updated to `g_pUserPane` with `g_pPlayerData` noted as a typed-view alias.

## First-Draft C++ Recommendation

First-draft C++ is safe for the global pointer only:

```cpp
class UserPane;

UserPane *g_pUserPane = 0;
```

Do not emit a large `UserPane` struct or the nested collection/player-data layout from this target. The global declaration is source-ready because the storage type and owner are proven. The member layout remains a support-doc/type-layout task and should not block the global declaration.

Use `0` rather than `nullptr` to stay compatible with the older source style implied by the binary/toolchain unless the project has already standardized on C++11 constructs elsewhere.

If the implementation callback needs a header-side declaration, use:

```cpp
extern UserPane *g_pUserPane;
```

That header declaration is not the exact `.data` storage definition and should not be placed in this by-memory C++ block unless the project convention for global pages requires both declaration and definition.

## Score And Metadata Recommendation

Recommended target score: `89/90`.

Rationale:

- Completion rises because this pass resolves the prior blocker called out by the target: final source-facing global name and concrete pointer type.
- Completion stays below final audit level because many nested UserPane fields still have source-role names rather than exact original member spellings.
- Confidence rises because raw PE/xref evidence and current docs agree: zero storage, 505 direct references, exactly five writes, all writes from UserPane lifetime/clear paths, and broad read-only consumers.

Recommended related support scoring if supervisor updates support pages:

- `by-global/g_pCollectionData.md`: rename/title as `g_pUserPane` if accepted; raise to `89/90` or keep `88/86` only if the supervisor decides not to rename the canonical symbol yet.
- `by-type/by-struct/CollectionPlayerDataLayout.md`: keep `86/88` unless a larger field-layout pass is performed; update ownership wording to `g_pUserPane` / nested collection view.
- `by-file/UserPane.md`: score can remain `89/85`; add resolved global naming/type evidence without broad rescore.
- `by-class/UserPane.md` and `by-memory/0x005a2530-0x005b8395.UserPane.md`: score can remain as-is unless the supervisor also updates class/member naming.

## Exact Implementation Checklist

Target by-memory page `[UID:0001OR]`:

- Rename title/source-facing symbol from `g_pCollectionData` to `g_pUserPane` if the supervisor accepts the canonical rename.
- Update metadata to `COMPLETION:89`, `CONFIDENCE:90`, owner/emitter unchanged as `0000P1`, reconstructable unchanged as `TRUE`.
- Populate C++ with exactly one definition if this page is selected as the emitting storage page:

```cpp
class UserPane;

UserPane *g_pUserPane = 0;
```

- Replace "final source-facing name/type unresolved" wording with `g_pUserPane` / `UserPane *` as the recommended source declaration.
- Preserve alias notes for `dword_67A748`, `g_pCollectionData`, `g_pPlayerData`, and `g_collectionProgressTable`.
- Add raw PE/xref summary: zero `.data` window, `505` exact direct operand references, and the five-write UserPane-only write set.
- Add heartbeat consumer detail: Application heartbeat checks non-null pointer and reads byte `+0x1a0`; Application is a consumer, not owner.
- Add field-view closure table or equivalent text for `+0xa4`, `+0x1a0`, `+0x3cb1`, `+0x3eb4`, `+0x3ec0`, collection group offsets, spell offsets, `+0x1340f8`, and `+0x13eb1d`.
- Add a 2026-06-19 B001 change note referencing this report.

Global support page:

- Rename or retitle `[UID:0000QK] by-global/g_pCollectionData.md` to `g_pUserPane` if supervisor accepts the canonical rename.
- Keep aliases in the Purpose section; explicitly say `g_pCollectionData`, `g_pPlayerData`, and `g_collectionProgressTable` are typed views over `g_pUserPane`.
- Avoid duplicate C++ emission. If target emits the definition, leave the by-global C++ block blank or make it a non-emitting semantic/index page according to local convention.
- Update the memory-doc link if the target file is renamed.

UserPane support:

- `by-file/UserPane.md`: update proposed contents and evidence notes to name `g_pUserPane` as the active UserPane singleton; keep historical alias in parentheses for searchability.
- `by-class/UserPane.md`: update constructor/destructor/global lifetime bullets from canonical `g_pCollectionData` to `g_pUserPane` with aliases.
- `by-memory/0x005a2530-0x005b8395.UserPane.md`: update touched-state/global rows and score rationale to use `g_pUserPane` source-facing name.
- `by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md`: no required semantic change unless it references the old global in support text; keep `m_mapPane` resolution.

Typed-layout support:

- `by-type/by-struct/CollectionPlayerDataLayout.md`: change owning global/view wording to `g_pUserPane` with `CollectionPlayerDataLayout` as a nested collection view. Close the open question "broader canonical name for the player-data block" as `UserPane` object storage / `g_pUserPane`; keep exact nested field spelling open only where original member names are not binary-unique.
- Collection docs (`CollectionPane`, `CollectionDialogPane`, `CollectionDialogControls`, `CollectionReadOnlyData`, and related collection pages): replace separate-global implications with local typed views over `g_pUserPane`.

Consumer support:

- Spell input/dispatch pages: replace generated `g_pSpellMan` / independent spell manager implications for this address with `g_pUserPane` spell-command slot view.
- Item/gold input pages: document `+0x3ec0` as a UserPane/local-player item-command busy gate.
- ChattingVarietyPane pages: document `+0x3eb4` and `+0x13eb1d` as UserPane/local-player state views, not Chatting-owned globals.
- FittingRoom docs: keep read-only consumer evidence if references are present; do not assign ownership.
- `CheckTimerSkewAndSendHeartbeat`: update `dword_67A748` wording to `g_pUserPane`; preserve Application ownership for heartbeat/timer state.
- `CreateScreenDimmerFactory`: update `g_pCollectionData + 0x214` wording to `g_pUserPane` subobject/view.
- `QuitInputPaneConfirmInput`: update the `+0xa4` timer-owner wording to `g_pUserPane + 0xa4`.
- `UserListDialogHuntersListOnlyFlag` / party-search support: update `g_pPlayerData+0x3cb1` to `g_pUserPane` player-state view.

Validation after callback:

- Run scoped validators for the target, renamed/updated global page, UserPane support pages, typed layout page, and each touched consumer page.
- Run memory coverage/report regeneration only from supervisor-owned callback flow.
- Regenerate autogen/rescore if C++ emission or file renames are accepted.

## Exact Supervisor-Owned Coverage Row

Current exact row in `by-memory/-coverage-report.md`:

```text
    - [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) 0x0067a748-0x0067a74c | global pointer | g_pCollectionData : reconstructable : 84% : strong : UserPane/local-player state pointer with zero storage, 505 xrefs, UserPane lifetime writes, typed collection/player-state views, and neighboring pointer boundaries documented.
```

Proposed replacement row if the target is renamed to `g_pUserPane`:

```text
    - [UID:0001OR][0x0067a748-0x0067a74c.g_pUserPane](by-memory/0x0067a748-0x0067a74c.g_pUserPane.md) 0x0067a748-0x0067a74c | global pointer | g_pUserPane : reconstructable : 89% : very strong : Source-level UserPane singleton pointer; raw PE/data-xref audit confirms zero-initialized `.data` storage, 505 direct `0x0067a748` operand refs, only five writes all from UserPane constructor/destructor/clear paths, collection/player/chat/item/spell/fitting/heartbeat typed-view consumers, alias rejection for separate `g_pCollectionData`/`g_pPlayerData` globals, and first-draft `UserPane *g_pUserPane = 0;` readiness documented.
```

Proposed replacement row if the supervisor keeps the existing filename/title for churn control:

```text
    - [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) 0x0067a748-0x0067a74c | global pointer | g_pUserPane : reconstructable : 89% : very strong : Source-level UserPane singleton pointer; raw PE/data-xref audit confirms zero-initialized `.data` storage, 505 direct `0x0067a748` operand refs, only five writes all from UserPane constructor/destructor/clear paths, collection/player/chat/item/spell/fitting/heartbeat typed-view consumers, `g_pCollectionData` preserved as a collection-view alias rather than canonical storage name, and first-draft `UserPane *g_pUserPane = 0;` readiness documented.
```

Again, B001 did not edit `by-memory/-coverage-report.md`.

## Open-Question Closure

Final source-facing owner: closed as `[UID:0000P1] UserPane` / `NexusTK/ui/panels/UserPane.cpp`.

Final source-facing type: closed as `UserPane *`.

Final source-facing global name: best high-probability reconstruction is `g_pUserPane`. Exact original spelling is not binary-stored, but leaving the page at `g_pCollectionData` now hides stronger type/owner evidence.

Whether this should emit source: closed as yes, one global pointer definition is safe. Duplicate emission between target and by-global page must be avoided.

Whether `g_pCollectionData`, `g_pPlayerData`, and `g_collectionProgressTable` are separate globals: closed as no.

Whether collection owns the storage: closed as no; collection owns feature consumers/layout docs, not lifetime storage.

Whether Application heartbeat changes ownership: closed as no; heartbeat is a consumer that gates packet emission and reads `+0x1a0`.

Whether the exact four-byte range should split or merge: closed as no; keep `0x0067a748-0x0067a74c`.

Remaining non-blocking uncertainty: exact original member names inside the large UserPane/local-player object are not all recoverable from this target. The report provides best-supported roles and support-doc update directions, and that uncertainty does not block global-pointer C++ readiness.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001OR-g_pCollectionData-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"0001OR"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001OR-g_pCollectionData-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001OR-g_pCollectionData-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001OR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
