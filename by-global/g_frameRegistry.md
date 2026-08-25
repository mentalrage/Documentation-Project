*** UID:0000Q0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// The declaration is emitted in FrameMgr.h; UID0002AT owns the definition.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
extern FrameMgr *g_frameRegistry;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_frameRegistry

## Status

- Symbol kind: external declaration for a process-wide `FrameMgr *` singleton.
- Address: exact loader-zero-filled storage at `0x0069ae10-0x0069ae14`; current IDA disassembly uses `unk_69AE10` and no target entity/name row survives.
- Source-facing name/type: `FrameMgr *g_frameRegistry`.
- Historical/raw aliases: `dword_69AE10`, `unk_69AE10`, and caller-context `g_pIdleDispatchQueue`.
- Owner/emitter: [UID:0000JM][FrameMgr](by-file/FrameMgr.md), `NexusTK/ui/core/FrameMgr.cpp`.
- Definition carrier: [UID:0002AT][0x0069ae10-0x0069ae14.g_frameRegistry](by-memory/0x0069ae10-0x0069ae14.g_frameRegistry.md), which emits the sole omitted-initializer definition.
- Confidence: very strong for storage, type, lifecycle, owner, linkage, and one-definition route; exact original symbol spelling remains inferred.

## Role

`g_frameRegistry` points to the process-wide [UID:00005H][FrameMgr](by-class/FrameMgr.md) instance. Frame handlers use it to insert or remove scheduled frame callbacks, and the message-loop idle worker uses it to dispatch callbacks for the current 20-tick slice. EventDispatcher creates and destroys the object but remains a lifetime driver/consumer rather than the storage owner.

Direct `Singleton<FrameMgr>` base construction publishes the complete object, while ordinary destruction, scalar-wrapper lowering, and constructor-unwind cleanup clear the pointer. These writes are compiler consequences of the base lifecycle, not explicit global assignments to repeat in human FrameMgr methods.

`g_pIdleDispatchQueue` is retained only as a historical caller-context alias. It is too narrow for insertion, removal, handler teardown, and due-frame dispatch. Raw `dword_69AE10`/`unk_69AE10` spellings and any all-ones sentinel interpretation are binary provenance, not recommended source.

## Declaration, Definition, And Initialization

- This page emits only the sole `extern` declaration in `FrameMgr.h`; UID00005G's earlier H fragment already forward-declares `FrameMgr`. UID0002AT emits exactly one `FrameMgr *g_frameRegistry;` definition in `FrameMgr.cpp`.
- The target is in the virtual-only tail of `.data`: target RVA `0x0029ae10` is `0x20610` bytes after the section's raw end and `0x2014` bytes before its virtual end. The loader supplies zero storage; there is no file-backed initializer dword.
- An omitted initializer is the least-assumption source reconstruction and matches the current bytes. Explicit `NULL` or `0` would be behaviorally equivalent but is not token-level proven. `nullptr` is era-inconsistent, and `0xffffffff` is false current state.
- External linkage is required by the established source model because FrameMgr owns the definition while EventDispatcher/application code in another source route consumes it. No second global, byte array, raw-address binding, section pragma, or file-local `static` alias is emitted.

## Evidence

- B003's 2026-07-14 healthy read-only MCP pass used evidence-time database `4836cd9f`; `server_health` was `ok` with auto-analysis, Hex-Rays, and strings ready. Bounded bytes over the target/adjacent window were all zero. These are captured evidence-time facts, not an indefinite current-session assertion.
- Input-image section mapping independently proves the target is unbacked virtual `.data` storage. The exact four zero bytes hash to SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
- Exactly 13 direct refs remain: EventDispatcher/application sites `0x004a6bfa`, `0x004a6cc9`, and `0x004a7e0c`; FrameHandler sites `0x004b6cd9`, `0x004b6d02`, `0x004b6d21`, `0x004b6d35`, and `0x004b6d7b`; FrameMgr lifecycle sites `0x004b6e03`, `0x004b6e0a`, `0x004b6e83`, `0x004b70b0`, and `0x004b70d6`.
- Target VA operand bytes `10 AE 69 00` occur exactly 13 times; target RVA bytes `10 AE 29 00` occur zero times. There is no hidden pointer table, relocation, dynamic initializer, or alternate storage route.
- FrameMgr RTTI names direct bases `LObject` and `Singleton<FrameMgr>`; the Singleton base descriptor has PMD `+4`. Constructor instructions derive `this+4`, publish the complete object by subtracting 4, and contain only a theoretical adjusted-null fallback.
- The constructor EH funclet at `0x005ff128` adds 4 to the complete object and jumps at `0x005ff12e` to `0x004b70b0`, whose body only clears the singleton. This proves a Singleton base-destructor cleanup target, not a public clear API.
- The raw ordinary cleanup island at `0x004b6e70` and scalar deleting wrapper at `0x004b70c0` repeat the clear as ordinary source-destructor/base lowering and compiler wrapper behavior. Human source must not add vptr stores, explicit base teardown, scalar flags, delete logic, EH/cookie code, or direct global writes.
- `FrameMgr *` is stronger than `FrameHandler *`, `LObject *`, `void *`, or an integer: EventDispatcher allocates 24 bytes and calls the FrameMgr constructor, vtable/RTTI identify FrameMgr, and every scheduler read invokes FrameMgr state or methods.
- The live xref set ties storage ownership to FrameMgr rather than FrameChrome, TimerMgr, EventDispatcher/Application, ScreenPane, WorldMapPane, Boost, or LinkedList. Those are consumers, separate subsystems, caller-biased embeddings, polluted names, or generic container support.
- [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md) is currently `94/94` and retains its split-first mixed aggregate/no-monolithic-C++ disposition.
- [UID:0001QU][client_timing](by-meta/client_timing.md) records the timing-model split: `FrameMgr` schedules frame-count callbacks, while `TimerMgr` dispatches time-based callbacks. This keeps the global out of visible frame-chrome or audio timing ownership.
- Historical 2026-06-11 wording correctly disclosed that pass's lack of fresh IDA access. It is superseded for current documentation by the healthy 2026-07-14 MCP/PE evidence above.

## User And Lifecycle Summary

| Evidence point | Current conclusion |
| --- | --- |
| Exact storage | `0x0069ae10-0x0069ae14`, four-byte loader-zero-filled `.data` pointer; current operand alias `unk_69AE10`, no surviving data-symbol row. |
| Constructor publish | `0x004b6e03` publishes the complete FrameMgr from direct `Singleton<FrameMgr>` base construction; `0x004b6e0a` is the compiler's adjusted-null fallback. |
| Destruction/cleanup | `0x004b6e83`, `0x004b70b0`, and `0x004b70d6` clear through ordinary, constructor-unwind, and scalar-wrapper Singleton/base lowering. |
| FrameHandler users | `0x004b6cd9`, `0x004b6d02`, `0x004b6d21`, `0x004b6d35`, and `0x004b6d7b` unregister or schedule handlers through the registry. |
| Application/EventDispatcher users | `0x004a6bfa`, `0x004a6cc9`, and `0x004a7e0c` read the registry during idle/cleanup work; the idle scheduler dispatches elapsed `0x14` / decimal `20` tick frame slices (Verified with `int_convert.py`). |
| Rejected owners | FrameChrome/art panes, WorldMap-only animation, and TimerMgr are consumers or neighboring timing systems, not owners of this singleton. |

## Assignment Decision

Keep owner/emitter UID0000JM on [UID:0000JM][FrameMgr](by-file/FrameMgr.md). This global declaration page is currently `93/94`, the UID00015M scheduler is currently `94/94`, and the UID0000JM file root is currently `94/94`; all clear the strict `85/85` gate without changing the ownership conclusion.

Do not attach the global directly to the [UID:00005H][FrameMgr](by-class/FrameMgr.md) class page. The storage is module-scope scheduler state; the ordered UID00005G and UID0000Q0 H fragments supply the forward declaration and extern without duplicating a partial class shell.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 93 | Exact zero storage/PE state, all 13 refs, direct Singleton source cause, type/name/linkage/initializer decisions, declaration/definition split, source placement, rejected alternatives, support route, exact H declaration channel, and contributor order are documented. |
| Confidence | 94 | Current MCP/PE/RTTI/instruction evidence strongly proves type, behavior, owner, and declaration route. The exact original symbol and explicit-versus-omitted zero token remain unavailable lexical caps. |

## Cross-References

- [UID:0000JM][FrameMgr](by-file/FrameMgr.md)
- [UID:00005H][FrameMgr](by-class/FrameMgr.md)
- [UID:00005G][FrameHandler](by-class/FrameHandler.md)
- [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md)
- [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md)
- [UID:0002AT][0x0069ae10-0x0069ae14.g_frameRegistry](by-memory/0x0069ae10-0x0069ae14.g_frameRegistry.md)
- [UID:0001QU][client_timing](by-meta/client_timing.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents address, aliases, singleton role, constructor/destructor writes, application idle use, FrameMgr ownership, and cross refs; final source-level spelling remains provisional.
- 2026-06-05: Marked reconstructable under [UID:0000JM][FrameMgr](by-file/FrameMgr.md). Evidence: live IDA MCP xrefs to `0x0069ae10` include `FrameMgr` construction/destruction, `FrameHandler` wrappers, and `0x004a6c40` idle scheduling; decompilation confirms `0x004b6dc0` writes `dword_69AE10 = this` and `0x004b70c0` clears it.
- 2026-06-11 A001 gate and evidence refresh:
  - Changed scores from `86/80` to `88/86`.
  - Summary/evidence: added exact storage-child and scheduler aggregate links, lifecycle/user summary, timing-model separation, verified `0x14` / decimal `20` idle-slice conversion, explicit rejected-owner rationale, strict `85/85` gate decision through [UID:0000JM][FrameMgr](by-file/FrameMgr.md), and score rationale. No fresh live IDA call was attempted for this page during this pass after prior MCP requests timed out on the previous target.
- 2026-07-14 B003 UID0002AT source-quality callback:
  - Raised `88/86` to `91/92`, retained owner/emitter UID0000JM, reconstructable true, and blank optional position, and installed exact R1 forward/extern declaration.
  - Current MCP and independent PE mapping supersede the historical `0xffffffff` claim with loader-zero-filled virtual `.data`; exact type is `FrameMgr *`, the source-facing name remains inferred `g_frameRegistry`, and UID0002AT owns the sole omitted-initializer definition.
  - Added exact 13-ref inventory, direct `Singleton<FrameMgr>` PMD `+4`, constructor/EH/ordinary/scalar lifecycle decomposition, external-linkage/one-definition policy, rejected aliases/types/owners/initializers, and historicalized no-fresh-IDA wording.

## 2026-08-24 B001 UID0000JM Accepted Callback

- Raised `91/92 -> 93/94`, preserved owner/emitter UID0000JM and reconstructable state, and assigned contributor position `10` between UID00005G's opening declarations and UID0002AT's storage definition.
- Moved the sole formal declaration from CPP to H as exactly `extern FrameMgr *g_frameRegistry;`. UID00005G's position-0 H fragment already supplies `class FrameMgr;`, so this page emits no duplicate forward declaration. The CPP channel contains only a declaration-route comment to keep the validator from rendering a false empty-emitter marker; it emits no declaration, definition, or executable source.
- UID0002AT at position `20` remains the only definition carrier. Loader-zero-filled `[0x0069ae10,0x0069ae14)`, all thirteen refs, external linkage, direct `Singleton<FrameMgr>` publication/clear cause, omitted initializer, and rejected `g_pIdleDispatchQueue`/raw/all-ones aliases remain unchanged.
- The score increase closes the exact declaration channel and contributor order. Exact original symbol spelling remains the lexical confidence cap; no owner, range, type, lifecycle, or one-definition claim changed.
