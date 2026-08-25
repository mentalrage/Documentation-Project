** TARGET-REPORT-UID:0002QX **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0002QX MotionAnimationAlternateConstructor Source-Quality Research


## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0002QX] as a source-authored alternate `Motion` constructor owned and emitted by [UID:00008R], with no split-table child and no owner/emitter change.
- Final disposition: implementation-ready source-quality update. The prior blank-C++ blocker is resolved with a defensible first-draft formal constructor body using inferred source-facing names.
- Required action: update the target score from `85/88` to `88/90`, insert the recommended formal `RECONSTRUCTION_CPP CODE` block, and incorporate the supporting field/source-route evidence listed below.
- Confidence: strong for exact behavior, range, ownership, emitter route, vtable/timer relationship, switch-table handling, and field offsets; still below final audit because exact original member/type spelling and caller-side declaration are inferred.

## Target
- Target UID: `0002QX`
- Target path: `by-memory/0x00539de0-0x00539f52.MotionAnimationAlternateConstructor.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` command `000000004795`, refreshed `2026-07-02T18:19:15-04:00`, row `85/88`, average `86.5`, reconstructable `true`, B reports `0`.
- Current supervisor classification: report-only source-quality research for `MotionAnimationAlternateConstructor`, Medium spec, MCP evidence required.
- Current scores and parent state: target `85/88`; direct class owner [UID:00008R] `Motion` is `86/87`; direct file route [UID:0000LL] `Motion` is `87/86`; target already clears the current C++ eligibility gate because it is reconstructable, routed, and average score is above `85`.

## Current Target State
- Existing metadata: `CANONICAL_OWNER:00008R`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008R`, blank formal C++ block, item summary "Alternate Motion animation constructor with explicit phase/control byte and optional sound/effect override."
- Existing owner/emitter/reconstructable state: correct. The target is a method of the timer-driven `Motion` animation class, and [UID:00008R] emits through [UID:0000LL] `NexusTK/render/Motion.cpp`.
- Existing C++/emitter state: eligible but blank. The page says C++ is intentionally blank because the constructor signature and field names were not final-source quality.
- Existing open questions/blockers: no direct entry xrefs to `0x00539de0`; exact caller-side source overload name unknown; exact original member names unknown; `dword_67A7C8 + 0x28de71` was not recorded as a named config field on the config support page.
- Related target/support docs checked: target page; [UID:00008R] `by-class/Motion.md`; [UID:0000LL] `by-file/Motion.md`; [UID:0001DD] constructor/timer cluster; [UID:0002QW] primary constructor; [UID:0002QY] timer tick; [UID:0002QZ] scalar deleting destructor; [UID:000356] vtable data; [UID:0002WR] pool storage; [UID:00028Q] `g_pConfig`.

## Executive Recommendation
- Best direct owner: keep [UID:00008R] `Motion`.
- Best source placement: keep route through [UID:0000LL] `NexusTK/render/Motion.cpp`.
- Split/container disposition: do not split. `0x00539de0-0x00539f52` is the source body; `0x00539f52-0x00539fe0` is constructor-local switch/jump-table data and `0xcc` padding before the timer tick, not a source-authored child.
- C++ disposition: insert first-draft source C++ into the target's formal block. The code must use inferred source-facing member names, not `sub_539DE0`, `a2`, or raw `dword_67A7C8`.

## Supervisor Active Recheck
- Current assignment: `B007-report-0002QX-MotionAnimationAlternateConstructor-20260702`, report-only research first, expected path `tools/leaser/Agents/Agent-B007/research/0002QX-MotionAnimationAlternateConstructor-source-quality.md`.
- The assignment does not authorize by-* edits during this pass, so all target/support changes below are recommendations for supervisor Gate 1 review and later callback.
- MCP was unavailable in the stale session `1f24c222` earlier, but supervisor resumed MCP. I discarded the stale session and used fresh `idb_list`, selecting canonical session `b010_0002r7_20260702`.

## Inference Research Guidance Check
- IDA/MCP facts are treated as authoritative for ranges, xrefs, callees, disassembly, bytes, vtable refs, stack arguments, and decompiled behavior.
- Current by-* docs are treated as documentation evidence for Motion ownership, Config/global naming, and source route.
- Generated reports are treated as state inputs only, not proof of source quality.
- The older `95/95` code-entry language in some historical docs is superseded by current `by-structure.md`: this routed reconstructable item is eligible for formal C++ at current scores if the code is source-quality enough.
- No Wave2/Wave3 material was used as authority. Generated/simroot names were not used to justify final source names.

## Heuristic / Inference Reanalysis And Validation
- Constructor role: direct IDA facts show `sub_539DE0` constructs the primary object view, then the timer subobject at `this + 4`, writes Motion vtables at `this + 0` and `this + 4`, and returns `this` with `retn 14h`. The five stack arguments make this a real alternate constructor, not a helper body.
- Signature: the source-like signature is best represented as `Motion::Motion(ObjectPane *owner, int motionType, char terminalFrame, int timerDelay, char soundOverride)`. `owner` is inferred from the primary constructor/timer tick owner flow; `motionType` is direct from switch selectors and storage at `+0x0c`; `terminalFrame` is inferred from timer tick use of `base + 0x14`; `timerDelay` is inferred from timer rescheduling use of `base + 0x18`; `soundOverride` is direct from the optional byte override semantics.
- Field names: `m_owner`, `m_motionType`, `m_soundEffectId`, `m_soundTriggerFrame`, `m_currentFrame`, `m_terminalFrame`, and `m_timerDelay` are inferred/descriptive. They match the timer tick's later field reads and avoid decompiler offsets. They are not original-name proof.
- Config global: `dword_67A7C8` must be source-facing `g_pConfig`; [UID:00028Q] already documents this as the canonical config pointer. The target-specific field at `+0x28de71` should be added as a descriptive `m_motionType16SoundEnabled` byte because both primary and alternate constructor sound maps gate motion type `16` on that byte.
- Sound override semantics: the binary treats `soundOverride == 0` as no override and stores `-1`; a negative nonzero override also stores `-1`; positive overrides either allow a fixed motion-type sound ID or fall through to the override value for default cases. The draft code preserves that with a local signed `requestedSound`.
- Cases `27` and `28`: the first switch deliberately performs no write to `m_soundTriggerFrame` for these cases. The C++ draft must preserve the no-assignment behavior rather than inventing a value.
- Switch tables: the table bytes after `0x00539f52` are compiler output for the two source-level switches. They should stay documented as table/padding bytes under this target/container, not receive a child page or C++.
- No direct start xrefs: still true. This limits confidence and exact declaration proof, but does not block source C++ because vtable, shared constructors, pool route, object layout, and exact body behavior all identify the target as retained Motion source.
- Rejected raw names: `sub_539DE0`, `a2`, `a3`, `a4`, `a5`, `a6`, `dword_67A7C8`, `byte_539F64`, and `jpt_539E67` are IDA/decompiler artifacts and should not appear in formal source C++.

## Evidence Standards Used
- IDA MCP exact-address checks: `server_health`, `idb_list`, `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `disasm`, `get_bytes`, and `int_convert`.
- Existing documentation checks: target and Motion support pages, constructor/timer/destructor/vtable/pool pages, generated tracker/memory coverage, and `g_pConfig`.
- Evidence is strong enough for a first-draft because function boundaries, stack signature, field writes, switch maps, dependencies, vtable refs, and timer-consumer field meanings agree. Confidence remains below final because there is no direct caller and no recovered original header declaration.

## Evidence Checked
- MCP session: `idb_list` on 2026-07-02 returned canonical `b010_0002r7_20260702` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` returned `status ok`, `auto_analysis_ready true`, `hexrays_ready true`, `module NexusTK.exe`, imagebase `0x400000`.
- MCP function boundaries: `lookup_funcs` returned `0x00539de0 sub_539DE0 size 0x172`, so exact half-open range is `0x00539de0-0x00539f52`; `0x00539f52` is not a function; neighbors are primary constructor `0x00539bc0 size 0x183`, timer tick `0x00539fe0 size 0x12c`, destructor `0x0053d590 size 0x84`.
- MCP xrefs: `xrefs_to 0x00539de0` returned zero; primary constructor has code xref `0x0053b5f9`; timer has vtable data xref `0x00620968`; destructor has code ref `0x0053cf57` and vtable data ref `0x00620954`; vtable slots `0x00620954` and `0x00620964` are stored by both constructors; pool root `0x0069b984` has five refs from init, creator, unwind, destructor, and cleanup.
- MCP callees: target calls only `0x004f4a80` and `0x00597570`, matching base object and timer handler construction.
- MCP decompile: `int __thiscall sub_539DE0(int this, int a2, int a3, char a4, int a5, char a6)` stores owner at `+0x08`, motion type at `+0x0c`, sound/effect word at `+0x10`, sound trigger byte at `+0x12`, current frame at `+0x13`, explicit terminal/control byte at `+0x14`, and timer delay/control dword at `+0x18`.
- MCP disasm: 116 instructions, stack args `arg_0 dword`, `arg_4 dword`, `arg_8 byte`, `arg_C dword`, `arg_10 byte`, final `retn 14h`; first lowered switch uses `byte_539F64` and `jpt_539E67`; second uses `jpt_539E88`; SEH/security-cookie handler code is outside source-body behavior.
- MCP bytes: `get_bytes regions` at `0x00539f52` shows table bytes beginning `66 90 6e 9e 53 00 74 9e 53 00 78 9e 53 00 ...` and ending with `cc cc cc cc` before the next function; `0x00620950` bytes decode to the Motion vtable/RTTI data including slots for `0x0053d590`, `0x0053cf54`, and `0x00539fe0`.
- Numeric conversions: MCP `int_convert` verified `0x1c` = decimal `28`, `0x28` = decimal `40`, `0x14` = decimal `20`, `0x2c5` = decimal `709`, `0x196` = decimal `406`, `0x193` = decimal `403`, `0x12c` = decimal `300`, `0x13b` = decimal `315`, and `0x28de71` = decimal `2678385`. These conversions were verified with MCP `int_convert`.
- Generated state: `auto-generated/-ag-memory-coverage.md` command `000000004785`, refreshed `2026-07-02T18:11:43-04:00`, row says UID0002QX emits through `00008R` to `auto-generated/NexusTK/render/Motion.cpp` with `Code no`.
- Existing report search terms used: `0002QX`, `0x00539de0`, `00539de0`, `MotionAnimationAlternateConstructor`, `sub_539DE0`, `Motion animation`, `Motion::Motion`, `MotionPool`, `0x00539f52`, `g_pConfig`, and `dword_67A7C8`.
- Existing report/search result: no prior executed B-agent report for UID0002QX was found. Relevant leads in A/C notes and current docs were rechecked against current MCP; generated report rows remain lead/state only.
- Failed/skipped checks: one `get_bytes` attempt used `start` instead of the current schema's `addr` inside `regions`, returned parse errors, and was retried successfully with `regions=@(@{addr=...; size=...})`. No by-* edits or validators were run in report-only mode.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID0002QX remains Motion-owned and emitted by [UID:00008R]; no owner/emitter change. | Strong | vtable stores, Motion class/file docs, generated memory coverage route | target metadata/status, Motion class/file support | incorporate | applied |
| C2 | Exact source body range remains `0x00539de0-0x00539f52`; `0x00539f52-0x00539fe0` is switch-table/padding, not a child. | Strong | `lookup_funcs`, `disasm`, `get_bytes`, neighbor timer function | target evidence; container support if needed | incorporate | applied |
| C3 | Score should move from `85/88` to `88/90`. | Strong | current MCP proof plus resolved C++ blocker; remaining caller/name caveats | target metadata and score rationale | incorporate | applied |
| C4 | Formal first-draft C++ should be inserted for `Motion::Motion(ObjectPane *, int, char, int, char)`. | Strong | decompile/disasm field stores, timer tick field meanings, current C++ gate | target formal `RECONSTRUCTION_CPP CODE` block | incorporate | applied |
| C5 | `g_pConfig + 0x28de71` should be documented as a Motion type 16 sound gate, descriptive name `m_motionType16SoundEnabled`. | Medium-high | target and primary constructor both check offset before sound id `305`; [UID:00028Q] owns config pointer | `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md` | incorporate | applied |
| C6 | No direct entry xrefs remain and should be preserved as a confidence limiter, not a no-code blocker. | Strong | `xrefs_to 0x00539de0` zero refs; vtable/constructor-family evidence positive | target negative evidence and score rationale | incorporate | applied |
| C7 | Support docs for primary constructor, timer tick, vtable, pool, and constructor/timer cluster already contain same-or-greater structural evidence; only narrow cross-reference updates are optional. | Medium-high | current support docs and MCP recheck | support docs | already-present | already-present |

## Positive Evidence Summary
- Direct facts supporting recommendation: exact function boundary, five-argument constructor convention, base/timer construction calls, Motion vtable stores, Motion pool family, timer field consumers, and switch maps all point to a source-authored alternate `Motion` constructor.
- Corroborating docs: [UID:00008R] and [UID:0000LL] already split timer-driven Motion animation from Region dirty-rectangle helpers, MessageDialogs, and NewHumanImageLib `Motion.tbl` helpers.
- Strongest inference chain: `sub_539DE0` shares the primary constructor's base/timer/vtable setup, stores the same owner/motion/sound/frame fields consumed by the timer tick, uses the same Motion vtable slots and pool family, and differs by accepting an explicit terminal/control frame. This is sufficient for source-facing constructor C++ even with no direct entry xref.

## IDA MCP Facts
- Function/range facts: `0x00539de0` is `sub_539DE0`, size `0x172`, end `0x00539f52`; `0x00539f52` is not a function; `0x00539fe0` starts the timer tick.
- Data/table/padding facts: bytes at `0x00539f52` contain jump table/selectors for the lowered switches plus `0xcc` alignment; these bytes are compiler output for this source body.
- Xref facts: no direct start refs to target; vtable slot refs and adjacent Motion pool/constructor refs support Motion ownership.
- Vtable/global/type facts: vtable writes use `0x00620954` and `0x00620964`; target reads `g_pConfig` storage at `0x0067a7c8` and offset `0x28de71`.
- Negative IDA facts: no direct caller, no embedded source filename, no local UDT recovered for exact declaration.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00539bc0-0x00539d43` | [UID:0002QW] `MotionAnimationConstructor` | Primary Motion constructor | TRUE | [UID:00008R] | `86/89` | related support, already present |
| `0x00539de0-0x00539f52` | [UID:0002QX] target | Alternate Motion constructor | TRUE | [UID:00008R] | recommend `88/90` | update target |
| `0x00539f52-0x00539fe0` | no separate UID recommended | compiler switch tables and padding | FALSE as child | target/container evidence only | not applicable | no split |
| `0x00539fe0-0x0053a10c` | [UID:0002QY] `MotionAnimationTimerTick` | Timer callback consuming fields | TRUE | [UID:00008R] | `86/90` | support evidence |
| `0x0053d590-0x0053d614` | [UID:0002QZ] destructor | Scalar deleting destructor | TRUE | [UID:00008R] | `88/92` | support evidence |
| `0x00620950-0x0062096c` | [UID:000356] vtable data | Motion vtable/RTTI slots | TRUE | [UID:00008R] | already strong | support evidence |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00539de0` | zero xrefs to target start | confidence limiter; not an ownership rejection |
| `0x00539bc0` | code xref from `0x0053b5f9` in `sub_53B3D0` | primary constructor live caller and source-family context |
| `0x00539de0 -> 0x004f4a80` | callee | base object construction |
| `0x00539de0 -> 0x00597570` | callee | timer handler/subobject construction |
| `0x00620954`, `0x00620964` | stored by both constructors | Motion vtable ownership |
| `0x0069b984` | five refs from pool lifecycle | Motion animation object pool context |

## Documentation Evidence And IDA Status
- Existing docs that support conclusion: target page already identifies constructor role and field offsets; [UID:00008R] and [UID:0000LL] already assign the timer-driven animation object to Motion and exclude Region/MessageDialogs/NewHumanImageLib pollution; [UID:00028Q] already resolves `dword_67A7C8` to `g_pConfig`.
- Existing docs that are incomplete: target C++ is blank and still phrases final signature/member names as blockers; [UID:00028Q] does not yet list the `+0x28de71` Motion sound gate; Motion class/file pages still treat alternate constructor source shape as a class/file-level blocker.
- Generated state: generated Motion.cpp has the UID0002QX marker but no code; memory coverage row shows emitted route with `Code no`.

## Ranked Ownership Analysis

### 1. [UID:00008R] Motion class
- Evidence for: direct vtable writes to Motion slots; identical base/timer setup to primary constructor; fields consumed by Motion timer tick; static Motion pool context; current class/file docs already isolate this timer-driven object from false Motion-labeled helpers.
- Evidence against: no direct start caller to alternate constructor; exact original constructor declaration not recovered.
- Decision: keep as owner and emitter. Negative evidence is a confidence limiter, not a stronger ownership alternative.

### 2. [UID:0000LL] Motion file
- Evidence for: file route already owns the timer-driven Motion class and generated destination `NexusTK/render/Motion.cpp`.
- Evidence against: file is a source bucket, not the narrow semantic owner; class is the better direct owner.
- Decision: keep as downstream file route through [UID:00008R], not direct target owner.

### 3. Constructor/timer cluster [UID:0001DD]
- Evidence for: contains exact neighboring Motion constructor/timer children and table/padding facts.
- Evidence against: documented non-emitting index/container, not a source owner.
- Decision: do not assign target to the cluster; keep only support/cross-reference role.

### Rejected non-Motion candidates
- Region dirty-rectangle helpers, MessageDialogs packet dispatch, NewHumanImageLib `Motion.tbl` helpers, and LivingObjectPane/ObjectPane adjacent islands are rejected by current Motion class/file split docs and by the target's vtable/timer/pool evidence.

## Source Placement
- Recommended placement: target emits as a `Motion` constructor through [UID:00008R] into [UID:0000LL] `NexusTK/render/Motion.cpp`.
- Why it fits: the constructor initializes the timer-driven animation object, not a Region rectangle helper or external asset-table helper.
- Rejected placements: Region.cpp, MessageDialogs.cpp, NewHumanImageLib.cpp, and no-owner/non-emitting are all weaker than current Motion vtable/timer evidence.
- Remaining uncertainty: exact original filename and exact class declaration spelling are not proven; this affects score ceiling but not source route.

## Range / Split / Padding / Reclassification Analysis
- Exact range: function `0x00539de0-0x00539f52`, source body ending after `retn 14h` at `0x00539f4f`.
- Table/padding: `0x00539f52-0x00539fe0` contains lowered switch/jump-table data and `0xcc` alignment before timer tick `0x00539fe0`.
- Split decision: no switch-table split and no child page. The table is compiler/linker-generated support for the constructor's source switches.
- Parent/container impact: [UID:0001DD] remains a non-emitting constructor/timer index over exact child pages; no range or parent change required.

## Negative Evidence Summary
- No direct start xrefs to `0x00539de0`; checked with MCP `xrefs_to`, result zero. This prevents final-audit confidence but does not outweigh constructor/vtable/timer evidence.
- No embedded source filename or UDT proof for exact original constructor declaration; class/file support docs already keep exact filename/member spelling below final certainty.
- `0x00539f52` is not code and not a function; bytes are switch tables/padding, so creating a data child would over-split compiler output.
- Raw names in IDA are not source names; current docs prove `dword_67A7C8` is `g_pConfig`, and the constructor-specific config byte should be descriptive rather than raw.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing method: `Motion::Motion(ObjectPane *owner, int motionType, char terminalFrame, int timerDelay, char soundOverride)`.
- Proposed field names for target/support docs and C++: `m_owner`, `m_motionType`, `m_soundEffectId`, `m_soundTriggerFrame`, `m_currentFrame`, `m_terminalFrame`, `m_timerDelay`.
- Proposed config field: `g_pConfig->m_motionType16SoundEnabled` for `g_pConfig + 0x28de71`.
- IDA DB edits: not requested in this report-only pass. These are documentation/source-facing recommendations only.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. The target is reconstructable, routed, above current C++ gate, has an exact source body, and the previous blocker has a defensible inferred naming/type solution.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` header/block insertion text:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
Motion::Motion(ObjectPane *owner, int motionType, char terminalFrame, int timerDelay, char soundOverride)
    : LObject(),
      TimerHandler()
{
    m_owner = owner;
    m_timerDelay = timerDelay;
    m_terminalFrame = terminalFrame;

    char requestedSound = -1;
    if (soundOverride != 0)
        requestedSound = soundOverride;

    m_motionType = motionType;
    m_currentFrame = -1;

    switch (motionType)
    {
    case 1:
    case 2:
        m_soundTriggerFrame = 1;
        break;
    case 27:
    case 28:
        break;
    default:
        m_soundTriggerFrame = 0;
        break;
    }

    if (requestedSound < 0)
    {
        m_soundEffectId = -1;
        return;
    }

    switch (motionType)
    {
    case 2:
        m_soundEffectId = 709;
        break;
    case 4:
        m_soundEffectId = 406;
        break;
    case 8:
        m_soundEffectId = 403;
        break;
    case 9:
        m_soundEffectId = 312;
        break;
    case 10:
        m_soundEffectId = 313;
        break;
    case 11:
        m_soundEffectId = 300;
        break;
    case 12:
        m_soundEffectId = 301;
        break;
    case 13:
        m_soundEffectId = 302;
        break;
    case 14:
        m_soundEffectId = 303;
        break;
    case 15:
        m_soundEffectId = 304;
        break;
    case 16:
        m_soundEffectId = (g_pConfig->m_motionType16SoundEnabled == 1) ? 305 : -1;
        break;
    case 17:
        m_soundEffectId = 306;
        break;
    case 18:
        m_soundEffectId = 307;
        break;
    case 19:
        m_soundEffectId = 308;
        break;
    case 20:
        m_soundEffectId = 309;
        break;
    case 21:
        m_soundEffectId = 310;
        break;
    case 22:
        m_soundEffectId = 311;
        break;
    case 23:
        m_soundEffectId = 314;
        break;
    case 24:
        m_soundEffectId = 315;
        break;
    default:
        m_soundEffectId = requestedSound;
        break;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves exact original behavior: field writes, no-write cases `27/28`, `soundOverride == 0` behavior, negative override suppression, all sound IDs, the `g_pConfig + 0x28de71` gate, and constructor return semantics match MCP decompile/disasm.
- Reason it matches plausible original source shape: source-level constructor overload with ordinary member assignments and two `switch` statements is the natural C++ source for the compiler-emitted jump tables. It avoids IDA labels and decompiler temporaries.
- Inferred names/types: `ObjectPane`, `TimerHandler`, and member names are source-facing inferred names. Exact original spellings are not proven, but they are stronger than leaving blank C++.
- Naming/coding style: conservative VC6/VC7-era member names consistent with existing B-agent accepted source style (`m_` members, `g_pConfig` global).
- Reason code should remain blank: not applicable. A blank block would no longer satisfy current score-blocker rules because source-like names and behavior are defensibly recoverable.
- Third-party import directive: not applicable.

## Final Recommendation
- Apply target score `88/90`; leave owner `00008R`, emitter `00008R`, reconstructable `TRUE`, and range unchanged.
- Insert the formal first-draft constructor C++ above into the target formal block.
- Do not split switch-table bytes or create child pages.
- Update support docs only where they remove stale C++ blockers or add required field context.

## Recommended Target Doc Changes
- Target path: `by-memory/0x00539de0-0x00539f52.MotionAnimationAlternateConstructor.md`
- Incorporate: current MCP session evidence; exact range/body/table bytes; no direct xrefs; vtable/callee facts; field names; sound map; `g_pConfig + 0x28de71`; no split-table decision; score rationale.
- Metadata/C++ changes: `COMPLETION:88`, `CONFIDENCE:90`, formal C++ block populated with the exact code above; owner/emitter/reconstructable unchanged.
- Preserve negative evidence: zero direct start refs and inferred exact member/source declaration names remain confidence limiters.

## Recommended Support Doc Changes
- `by-class/Motion.md`: update the alternate constructor blocker. Record that UID0002QX now has a source-ready first-draft constructor body with inferred member names, while the broader class declaration can remain blank until full class layout/header is finalized.
- `by-file/Motion.md`: record that UID0002QX is now ready to emit through `NexusTK/render/Motion.cpp`; preserve split-owner guard excluding Region dirty rectangles, MessageDialogs, and NewHumanImageLib.
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`: add `+0x28de71` as the Motion type 16 sound/effect enable byte, with descriptive member name `m_motionType16SoundEnabled`, consumed by both Motion constructors' sound maps.
- `by-memory/0x00539bc0-0x0053a10c.MotionAnimationConstructorTimerCluster.md`: no required metadata change. If touched, add only a short note that B007 reconfirmed no split-table child for the alternate constructor tail.
- `by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md`, `by-memory/0x00539fe0-0x0053a10c.MotionAnimationTimerTick.md`, `by-memory/0x00620950-0x0062096c.MotionVtableData.md`, and `by-memory/0x0069b984-0x0069b9ac.MotionPoolStaticStorage.md`: already-present support evidence; no required edits unless the supervisor wants cross-reference polish.

## Score And Metadata Recommendation
- Current score/metadata: `85/88`, owner `00008R`, reconstructable `TRUE`, emitter `00008R`, blank C++.
- Recommended score/metadata: `88/90`, owner/emitter/reconstructable unchanged, formal C++ populated.
- Score rationale: completion rises because the report resolves the prior C++/signature/member-name blocker into an implementation-ready first draft, verifies current MCP facts, and records exact support changes. Confidence rises because current MCP reconfirmed range, body, stack args, vtable refs, table bytes, and global identity.
- Reason not higher: no direct caller to the alternate constructor; exact original header declaration and member spellings are not proven; class-level full declaration remains broader work.
- Reason not lower: the target has exact IDA behavior, exact field stores, exact switch maps, strong Motion owner route, and source-like code no longer requires unsafe speculation.
- Metadata fields to leave unchanged: UID, owner, reconstructable, emitter, range, item summary meaning, and no child split.

## Open Questions With Attempted Resolution
- Exact caller and overload usage: MCP `xrefs_to` found zero direct target refs; primary constructor caller and Motion family evidence were checked. Remains unresolved, score impact only.
- Exact original member names: timer field use and current docs support descriptive names; no UDT/source header exists. Use inferred names in formal C++ and document them as inferred.
- Exact `g_pConfig + 0x28de71` field name: no config doc row exists today; binary role is clear enough for descriptive `m_motionType16SoundEnabled`. Final Config naming can refine later without blocking this constructor body.
- Exact original file name: `NexusTK/render/Motion.cpp` remains proposed, not original-proof; route is still correct because generated output already uses this file bucket and support docs reject non-Motion pollution.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable. The relevant tracker and memory coverage reports are validator-owned generated files. Do not manually edit `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, or any manual `-coverage-report.md`.

## Follow-Up Actions
- Supervisor Gate 1: audit this report's headings/content and either approve callback or return exact rework.
- If callback approved: update the target/support docs listed above under leases, run scoped file validators, and then stop at `READY_FOR_SUPERVISOR_EXECUTE`.
- Supervisor-only after Gate 2: run the executed-report lifecycle command. B007 must not run it.

## Confidence
- Recommendation confidence: strong.
- Score confidence: strong for `88/90`; not final-audit confidence because no direct caller/header proof.
- Remaining uncertainty: exact original declaration and names, not behavior/range/owner.

## Validator Results
- Commands run during implementation callback:
  - `python .\tools\validator.py --mode file --file by-memory/0x00539de0-0x00539f52.MotionAnimationAlternateConstructor.md --apply --queue-timeout 240 --wait-generated`
    - `command_id: 000000004810`
    - `command_timestamp: 2026-07-02T18:53:15-04:00`
    - Exit code: `0`
    - Result: `ok: 1`; `completion_update 0002QX ... 88`; `confidence_update 0002QX ... 90`; `autogen_cpp_update 0000LL auto-generated/NexusTK/render/Motion.cpp`; `generated_refresh: completed`.
  - `python .\tools\validator.py --mode file --file by-class/Motion.md --apply --queue-timeout 240`
    - `command_id: 000000004811`
    - `command_timestamp: 2026-07-02T18:53:30-04:00`
    - Exit code: `0`
    - Result: `ok: 1`; `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-file/Motion.md --apply --queue-timeout 240`
    - `command_id: 000000004812`
    - `command_timestamp: 2026-07-02T18:53:35-04:00`
    - Exit code: `0`
    - Result: `ok: 1`; validator inserted the generated UID link for UID0002QX; `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md --apply --queue-timeout 240`
    - `command_id: 000000004813`
    - `command_timestamp: 2026-07-02T18:53:52-04:00`
    - Exit code: `0`
    - Result: `ok: 1`; added reference-index entries for UID0002QW and UID0002QX; `generated_refresh: deferred`.
- Generated freshness: `auto-generated/NexusTK/render/Motion.cpp` now has `validator-command-id: 000000004812` and `validator-refreshed-at: 2026-07-02T18:53:35-04:00`, and contains the UID0002QX `Motion::Motion(ObjectPane *owner, int motionType, char terminalFrame, int timerDelay, char soundOverride)` body with `Completion:88 | Confidence:90`.
- Any unresolved validator warnings/errors: the `g_pConfig` scoped validator reported five existing `missing_ref_uid` diagnostics for UIDs `0003UJ` and `0003UA`; these references pre-existed in that support page and were not introduced by this callback. The scoped file still returned `ok: 1`. Target-specific validator issues: none.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B007/research/0002QX-MotionAnimationAlternateConstructor-source-quality.md`
- Modified during implementation callback:
  - `by-memory/0x00539de0-0x00539f52.MotionAnimationAlternateConstructor.md`
  - `by-class/Motion.md`
  - `by-file/Motion.md`
  - `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
  - this report checklist/ledger
- Renamed: none.
- Report execution: not run. B agents must never run `tools/validator.py execute_report`, dry-run/probing variants, registry lifecycle commands, manual report moves, or archive commands.

## Implementation Tracking Checklist
- [x] Supervisor validation required before implementation. Gate 1 accepted by supervisor for implementation callback at `2026-07-02T18:46:39-04:00`, SHA256 `9B24953E25E698F0201E1BD6FF31FB79291742EFD84893442301D71E5EAEF447`.
- [x] Target/support docs to update: target `by-memory/0x00539de0-0x00539f52.MotionAnimationAlternateConstructor.md`; support `by-class/Motion.md`, `by-file/Motion.md`, and `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md` all updated. Constructor/timer cluster and sibling Motion docs left untouched because accepted report marked their facts already-present/optional and no stale text directly conflicted.
- [x] Current target state and actual evidence checked recorded: target page now includes MCP session `b010_0002r7_20260702`, health, function boundary, zero xrefs, callees, decompile/disasm, table bytes, int conversions, vtable/pool refs, and generated-state implications.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: C1-C6 marked `applied`; C7 marked `already-present`.
- [x] Metadata/score changes to apply: target metadata now `COMPLETION:88`, `CONFIDENCE:90`; owner `00008R`, emitter `00008R`, reconstructable `TRUE`, and range unchanged.
- [x] Score-limiting blockers researched to resolution: target now has formal first-draft C++; no-direct-caller and exact-name questions preserved as confidence limiters, not blockers.
- [x] Owner/emitter/reconstructable changes to apply: none; target page explicitly preserves owner/emitter/reconstructable.
- [x] Split/rename/new-child changes to apply: none; target page explicitly preserves no switch-table split and no child creation for `0x00539f52-0x00539fe0`.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: target and Motion file document `0x00539f52-0x00539fe0` as compiler switch-table/padding; no IDA DB edits requested or made.
- [x] First-draft C++ to apply: exact formal `Motion::Motion(ObjectPane *owner, int motionType, char terminalFrame, int timerDelay, char soundOverride)` block inserted into the target formal `RECONSTRUCTION_CPP CODE` block and generated into `auto-generated/NexusTK/render/Motion.cpp`.
- [x] Third-party import directive to apply or confirm not applicable: not applicable; no `third_party_embeds/...` import.
- [x] Exact target/support doc facts to incorporate at report-level detail: field map, sound map, zero direct xrefs, table bytes, vtable/callee evidence, `g_pConfig +0x28de71`, inferred naming caveats, and score rationale incorporated.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: old blank-C++ blocker explicitly superseded; raw `dword_67A7C8` replaced by `g_pConfig`; non-Motion Region/Dialog/NewHumanImageLib placements rejected; zero direct xref caveat preserved.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: generated state remains route/status input only; no Wave2/Wave3 authority added.
- [x] Open questions to close or document as evidence-backed unresolved: exact caller, header declaration, and final member spelling remain documented as unresolved score/confidence limiters.
- [x] Validators to run after implementation callback only: ran scoped validators for all four changed by-* docs; command IDs `000000004810`, `000000004811`, `000000004812`, and `000000004813`, all exit code `0`, all `ok: 1`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: no manual coverage/tracker edits made. Target validator completed generated refresh; generated Motion.cpp header is `validator-command-id: 000000004812`, `validator-refreshed-at: 2026-07-02T18:53:35-04:00`, and includes UID0002QX code.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004841","destination_path":"executed-b-agent-research/B007/0002QX-MotionAnimationAlternateConstructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0002QX-MotionAnimationAlternateConstructor-source-quality.md","timestamp":"2026-07-02T19:01:17-04:00","uid":"0002QX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
