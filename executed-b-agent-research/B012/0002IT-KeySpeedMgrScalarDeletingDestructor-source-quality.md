** TARGET-REPORT-UID:0002IT **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002IT KeySpeedMgrScalarDeletingDestructor Source-Quality Research

## Final Recommendation

- Target: [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](../../../../by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md)
- Final disposition: source-declared/generated-binary `KeySpeedMgr` scalar deleting destructor glue. This page should stay reconstructable and routed, but it should not become a source-bearing handwritten C++ destructor body.
- Recommended metadata: keep `CANONICAL_OWNER:00006Z`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00006Z`; raise score from `84/90` to `86/91`.
- Recommended target C++: comment-only no-code marker, not a wrapper implementation:

```cpp
// Compiler-generated scalar deleting destructor for KeySpeedMgr; source is KeySpeedMgr::~KeySpeedMgr().
```

The ordinary source-bearing destructor is already on [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](../../../../by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md) at `87/92`:

```cpp
KeySpeedMgr::~KeySpeedMgr()
{
    g_pKeySpeedMgr = 0;
}
```

Do not hand-write the scalar deleting wrapper body, vptr restore, duplicate singleton clear, base cleanup call, scalar-delete flag tests, optional heap free, or guard-check path. Those are compiler/MSVC ABI output from the `KeySpeedMgr` class declaration, virtual destructor, base class, and ordinary destructor definition.

## Evidence Checked

- Required project rules: `by-structure.md`, `inference_research.md`, `.codex/AGENTS.md`, `Supervisor.md`, and B012 `goal.md`.
- Target/support docs:
  - `by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md`
  - `by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md`
  - `by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md`
  - `by-class/KeySpeedMgr.md`
  - `by-file/KeySpeedMgr.md`
  - `by-type/by-vtable/KeySpeedMgrVtable.md`
  - `by-type/by-struct/KeySpeedMgrLayout.md`
  - `by-global/g_pKeySpeedMgr.md`
  - `by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md`
  - `by-memory/0x0061c9c4-0x0061c9dc.KeySpeedMgrVtableData.md`
  - `by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md`
- Prior B003 ordinary-destructor report used as a lead and rechecked against current docs/exports: `tools/leaser/Agents/Agent-B003/research/executed/0002IQ-KeySpeedMgrDestructor-source-quality.md`.
- Local exported function evidence:
  - `resources/exported_data/functions/0x004effc0.json`
  - `resources/exported_data/functions/0x004efee0.json`
  - `hooks-generation/tests/function_data/ida/0x004effc0.json`
  - `hooks-generation/tests/function_data/ida/0x004efee0.json`
  - `hooks-generation/tests/function_data/ghidra/0x004effc0.json`
- Active generated output `source-3/project-documentation/auto-generated/NexusTK/input/KeySpeedMgr.cpp`.
- Current generated coverage row in `auto-generated/-ag-memory-coverage.md` and current project coverage row in `by-memory/-coverage-report.md`.
- Current IDA MCP check was attempted through `http://127.0.0.1:13337/mcp`; result: `MCP_ERROR: Unable to connect to the remote server`. This report therefore relies on existing live-MCP page notes plus local IDA/Ghidra/exported evidence.

## Direct Binary Facts

`0002IT` is one exact modeled function:

- IDA name: `sub_4EFFC0`.
- Ghidra names: `~KeySpeedMgr`; OOAnalyzer method name `virt_deldtor_0x4effc0`, method type `deldtor`.
- Range/size: `0x004effc0-0x004f0008`, size `0x48` / 72 bytes.
- Xrefs to target: sole target xref is a data reference from vtable slot `0x0061c9c8`.
- No direct code caller is recorded for the wrapper; runtime deletion reaches it through the vtable slot. The WinMain cleanup helper [UID:00032A] reads `g_pKeySpeedMgr`, pushes deleting-destructor flag `1`, and calls vtable slot zero.
- Callees: base cleanup at `0x004f4a90` (`sub_4F4A90`, documented as `LObject` cleanup), delete/free wrapper at `0x004f4ac0` (`sub_4F4AC0`), and `_guard_check_icall_nop@4` at `0x0041b6a0`.
- IDA decompile:

```c
_DWORD *__thiscall sub_4EFFC0(_DWORD *Block, char a2)
{
  *Block = &KeySpeedMgr::`vftable';
  dword_67AB48 = 0;
  sub_4F4A90(Block);
  if ( (a2 & 1) == 0 || (a2 & 4) != 0 )
    return Block;
  sub_4F4AC0(Block);
  return Block;
}
```

- Ghidra agrees on the wrapper shape: vptr restore, `DAT_0067ab48 = 0`, `LObject::~LObject`, optional `FUN_004f4ac0(this)` when `(param_1 & 1) != 0` and `(param_1 & 4) == 0`, and guard-check handling on the flag-4 branch.
- One Ghidra/GhidrAssist variant mislabels the base call at `0x004f4a90` as `Motion::~Motion`; the by-docs, ordinary destructor parity, and callee export support `LObject` cleanup instead. Treat the `Motion` label as a decompiler naming conflict, not source evidence.
- Existing live target notes place the vptr restore at `0x004effc6`, `g_pKeySpeedMgr` clear at `0x004effcc`, base cleanup call at `0x004effd6`, conditional delete at `0x004effe7`, guard check at `0x004efff9`, and `0xcc` alignment padding at `0x004f0008-0x004f0010`.

## Source-Quality Decision

The target should be documented as no-code compiler scalar deleting destructor glue while remaining reconstructable and class-owned:

- Keep `RECONSTRUCTABLE:TRUE`: rebuilding source must declare/define the `KeySpeedMgr` class and virtual destructor shape that regenerates this ABI wrapper.
- Keep `CANONICAL_OWNER:00006Z` and `EMITTER_UIDS:00006Z`: the vtable slot, vptr restore, singleton clear, ordinary destructor parity, and class/type pages identify one direct class owner.
- Keep the downstream source-file route through [UID:0000KJ][KeySpeedMgr](../../../../by-file/KeySpeedMgr.md), `NexusTK/input/KeySpeedMgr.cpp`.
- Do not reclassify to `RECONSTRUCTABLE:FALSE`: this is not ownerless runtime glue or a shared/mixed helper; it is class-specific generated binary support.
- Do not emit a wrapper implementation: that would encode MSVC scalar deleting destructor mechanics as handwritten source and duplicate the ordinary destructor semantics.

The current target text is stale where it justifies blank C++ by the old `95/95` source gate. The target already clears the active code-entry gate by routing and score: `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS:00006Z`, and current average `(84 + 90) / 2 = 87`, which is over 85. Blank/no-code is justified only by generated-binary policy. Under Rule 28-style tracking, the page should use a comment-only no-code marker so generated coverage does not treat routed compiler glue as missing.

## Heuristic / Inference Reanalysis

The old heuristic outcome was "blank C++ because below final source gate." That is no longer the correct reason. Current reconstruction heuristics say:

- It clears the route/source gate: reconstructable, nonblank emitter, and average score over 85.
- It fails the handwritten-source test: the only recovered behavior is scalar deleting destructor ABI mechanics around the ordinary destructor body.
- It passes the class-specific generated-binary test: the sole vtable slot target, vptr restore, singleton clear, base cleanup, and deleting flag behavior all bind to one class owner.
- It should use no-code proof, not source omission: a comment-only marker preserves routing/coverage while preventing a fake `ScalarDeletingDestructor` source method.

Inference result: the page is first-draft ready only as no-code compiler glue. The source-bearing inference terminates at [UID:0002IQ] `KeySpeedMgr::~KeySpeedMgr()`, whose semantic body is the singleton clear.

## Ordinary Destructor Placement

[UID:0002IQ] is the correct source-bearing page:

- It is the ordinary non-deleting destructor at `0x004efee0-0x004efef5`.
- Current metadata is already `87/92`, owner/emitter [UID:00006Z], and formal C++ is already first-draft ready.
- IDA export shows `sub_4EFEE0` size `0x15` / 21 bytes, no direct xrefs/callers, vptr restore, `dword_67AB48 = 0`, and a tail jump to `sub_4F4A90`.
- B003 raw PE/Capstone evidence confirms exact bytes and instruction shape: `mov [ecx], 0x61c9c8`; `mov [0x67ab48], 0`; `jmp 0x4f4a90`.

The source body should remain:

```cpp
KeySpeedMgr::~KeySpeedMgr()
{
    g_pKeySpeedMgr = 0;
}
```

Compiler-generated or implicit parts:

- vptr restore to `0x0061c9c8`;
- tail jump/call to `LObject` base cleanup at `0x004f4a90`;
- scalar deleting destructor flag checks;
- optional `sub_4F4AC0` delete wrapper call;
- `_guard_check_icall_nop@4` path.

## Routing And Rejected Alternatives

Accepted:

- Direct semantic owner: [UID:00006Z][KeySpeedMgr](../../../../by-class/KeySpeedMgr.md).
- Downstream file route: [UID:0000KJ][KeySpeedMgr](../../../../by-file/KeySpeedMgr.md), `NexusTK/input/KeySpeedMgr.cpp`.
- Rebuild classification: source-declared/generated-binary destructor ABI support with a comment-only no-code marker.

Rejected:

- Direct file owner [UID:0000KJ]: too broad. This is a class vtable/deleting-destructor artifact; the class is the narrow owner.
- `CANONICAL_OWNER:NONE`: stale for this target. The vtable slot and wrapper body prove a single class owner.
- `RECONSTRUCTABLE:FALSE`: appropriate for truly ownerless ABI or thunk glue, but not for this class-specific vtable slot target.
- Handwritten source wrapper: would duplicate the ordinary destructor and encode compiler-specific flag/delete behavior.
- WinMain/Application/InputMan ownership: those are consumers or neighboring startup/input modules. [UID:00032A] `DestroyKeySpeedMgr` is WinMain-owned cleanup policy that dispatches through the `KeySpeedMgr` vtable; it does not own the destructor wrapper.

## Globals And Singleton Behavior

`g_pKeySpeedMgr` is the class/file-owned singleton pointer:

- Exact storage: [UID:0001P7] `0x0067ab48-0x0067ab4c`.
- Global doc: [UID:0000RB] `g_pKeySpeedMgr`, owner [UID:0000KJ].
- Constructor `0x004efea0` writes `dword_67AB48 = this` and initializes the object fields.
- Ordinary destructor `0x004efee0` clears `dword_67AB48`.
- Scalar deleting destructor `0x004effc0` clears `dword_67AB48` again as part of compiler-generated deleting wrapper emission.
- WinMain cleanup helper `0x004673c0` reads the global, null-checks it, pushes flag `1`, and dispatches slot zero through the active vtable. Its source owner is [UID:0000PA][WinMain], not `KeySpeedMgr`.

The scalar deleting destructor's singleton clear is not evidence for a second source function. It repeats the same semantic effect already represented by `KeySpeedMgr::~KeySpeedMgr()`.

## Vtable And Class Shape

- Exact vtable-data page [UID:00031P] covers `0x0061c9c4-0x0061c9dc`.
- `0x0061c9c4` is the `KeySpeedMgr` RTTI complete-object locator pointer.
- Primary vtable base `0x0061c9c8` points to `0x004effc0`, the scalar deleting destructor slot.
- `0x0061c9cc` points to inherited `LObject` identity/class-name slot `0x004f4b10`.
- `0x0061c9d0` points to inherited/default no-op slot `0x0041b6c0`.
- Tail dwords `0x0061c9d4` and `0x0061c9d8` are `0x400` constants, not function pointers.
- Vtable stores are documented in constructor `0x004efecb`, ordinary destructor `0x004efee0`, and scalar deleting destructor `0x004effc6`.

The class layout remains a small `LObject`-derived singleton with object size `0x0c`: vptr at `+0x00`, saved keyboard delay at `+0x04`, and saved keyboard speed at `+0x08`.

## Compiler-Generated And Raw Names

Treat these as binary/decompiler labels, not source names:

- IDA: `sub_4EFFC0`.
- Ghidra: `~KeySpeedMgr` with deleting-destructor signature.
- OOAnalyzer: `virt_deldtor_0x4effc0`, method type `deldtor`.
- Documentation file slug: `KeySpeedMgrScalarDeletingDestructor`.

The source-level destructor name belongs to [UID:0002IQ]: `KeySpeedMgr::~KeySpeedMgr()`. No distinct source-authored `ScalarDeletingDestructor` method should be introduced.

## Open Questions

- Exact original header spelling for the class declaration and whether the final source should show `virtual ~KeySpeedMgr();` explicitly depends on final class/header reconstruction.
- The exact allocator/delete wrapper naming for `sub_4F4AC0` is still generic in local exports; this does not affect the no-code decision because the wrapper call is compiler-generated.
- The flag-4 guard-check path is documented and exported, but current live MCP was unavailable in this pass. Existing target notes and local exports agree on the branch/callee.
- Other `KeySpeedMgr` methods still have blank source blocks, so final `KeySpeedMgr.cpp` readiness is partial. This target is ready for a no-code marker; it is not a blocker on first-draft source for the ordinary destructor.

## Recommended Exact Target Doc Changes

Apply only if the supervisor sends an implementation callback.

Header metadata:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006Z | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006Z | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Target C++ block:

```cpp
// Compiler-generated scalar deleting destructor for KeySpeedMgr; source is KeySpeedMgr::~KeySpeedMgr().
```

Recommended status/reconstruction note edits:

- Replace old `80/80` or `95/95` gate wording with the current rule: `RECONSTRUCTABLE:TRUE`, nonblank emitter route, and `(COMPLETION + CONFIDENCE) / 2 > 85`.
- State that the page is routed and reconstructable because the class declaration and ordinary destructor regenerate the wrapper, not because a separate source method exists.
- State that `0002IQ` carries the only source-bearing destructor body.
- Record the local exported evidence: `sub_4EFFC0`, size `0x48`, vtable data ref from `0x0061c9c8`, no direct code callers, callees `sub_4F4A90`, `sub_4F4AC0`, and `_guard_check_icall_nop@4`.
- Mention the Ghidra `Motion::~Motion` base-label conflict as rejected in favor of `LObject` cleanup.

Recommended change-log note:

```markdown
### 2026-06-19 B012 source-quality recheck

- Changed recommendation from `84/90` blank-C++ stale-gate wording to `86/91` with a comment-only no-code marker.
- Evidence: local IDA/Ghidra/exported function data confirms `sub_4EFFC0` is a 72-byte class-specific scalar deleting destructor reached from vtable slot `0x0061c9c8`, restoring the `KeySpeedMgr` vptr, clearing `g_pKeySpeedMgr`, calling `LObject` cleanup, and conditionally calling the delete wrapper for scalar-delete flags.
- Source decision: keep this page as source-declared/generated-binary ABI glue. The first-draft source destructor remains [UID:0002IQ] `KeySpeedMgr::~KeySpeedMgr() { g_pKeySpeedMgr = 0; }`; do not hand-author a separate scalar deleting destructor method.
```

## Validator Needs

No validator was run because this is a report-only B-agent pass.

After an implementation callback edits the target, run from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002IT-KeySpeedMgrScalarDeletingDestructor-source-quality-removed.md](0002IT-KeySpeedMgrScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor also applies the pending coverage row, run:

> Executable block R002 was removed from this report and preserved verbatim in [0002IT-KeySpeedMgrScalarDeletingDestructor-source-quality-removed.md](0002IT-KeySpeedMgrScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected generated coverage change after adding the comment-only marker:

```markdown
| [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md) | emits | `00006Z` | `00006Z` |  | yes | `auto-generated/NexusTK/input/KeySpeedMgr.cpp` | `by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md` |  |
```

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` from B012. Supervisor should replace the current `0002IT` row with:

```markdown
        - [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md) 0x004effc0-0x004f0008 | scalar-deleting-destructor | KeySpeedMgr scalar deleting destructor glue : reconstructable : 86% : strong : B012 source-quality review classifies this as source-declared/generated-binary KeySpeedMgr scalar deleting destructor glue, not a source-bearing handwritten method. Keep direct owner/emitter [UID:00006Z][KeySpeedMgr](by-class/KeySpeedMgr.md) routed through [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) to `NexusTK/input/KeySpeedMgr.cpp`; use a comment-only no-code marker while [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md) carries `KeySpeedMgr::~KeySpeedMgr() { g_pKeySpeedMgr = 0; }`. Local IDA/export evidence confirms `sub_4EFFC0` size `0x48`, sole target xref from vtable slot `0x0061c9c8`, vptr restore at `0x004effc6`, `g_pKeySpeedMgr` clear at `0x004effcc`, `sub_4F4A90` base cleanup, optional `sub_4F4AC0` delete wrapper only when `(flags & 1) != 0 && (flags & 4) == 0`, guard-check flag-4 path, no direct code callers, and `0xcc` padding before LanguageManLocalization.
```

## First-Draft Readiness

- `0002IT` is ready for comment-only no-code marking now.
- `0002IQ` already carries the first-draft source destructor body.
- Class/file routing is already sufficient: `0002IT` -> `00006Z` -> `0000KJ` -> `NexusTK/input/KeySpeedMgr.cpp`.
- Remaining final C++ work is outside this target: complete constructor/load/restore/helper source bodies and final class/header spelling for `KeySpeedMgr`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/0002IT-KeySpeedMgrScalarDeletingDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"0002IT"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002IT-KeySpeedMgrScalarDeletingDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/0002IT-KeySpeedMgrScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002IT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
