** TARGET-REPORT-UID:0001KQ **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001KQ SelfSaveInputPaneFactory Source-Quality Report

Assignment: B012 source-quality / heuristic reanalysis for [UID:0001KQ]

Status: FINISHED, report-only. I did not edit `by-*` documentation and did not edit `by-memory/-coverage-report.md`.

## Current Recommendation

- Keep [UID:0001KQ] reconstructable and source-bearing.
- Keep the immediate canonical owner/emitter as [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md) for this implementation pass.
- Do not move this one helper alone to [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md). The final source file probably folds the whole `SelfSaveInputPane` prompt family into `CommandInputPanes.cpp`, but that should be a coordinated source-file consolidation for the class, constructor, confirm handler, raw send helper, and vtable docs together.
- Raise target score from `85/86` to `87/88` after incorporating this evidence.
- Recommended source-facing helper name: `CreateSelfSaveInputPane`.
- Recommended signature: `SelfSaveInputPane *__cdecl CreateSelfSaveInputPane(void)`.
- The helper has no proven runtime route. Fresh PE scanning found no rel32 call/jump, absolute VA pointer, or RVA pointer to `0x005aa140`. This is a serious liveness caveat, but it is not a compiler/runtime glue body; the body is a source-authored, retained no-argument factory/open helper that constructs a `SelfSaveInputPane`.
- First-draft C++ is ready as a retained source helper, with the no-route caveat documented. Do not hand-write vtable stores or localized lookup inside this factory; source should call the constructor and let the compiler inline constructor details if it chooses.

Recommended first-draft C++ for [UID:0001KQ]:

```cpp
SelfSaveInputPane *CreateSelfSaveInputPane()
{
    return new SelfSaveInputPane;
}
```

The paired constructor page should carry the actual prompt construction source shape:

```cpp
SelfSaveInputPane::SelfSaveInputPane()
    : CharInputPane(g_pLanguageMan->GetLocalizedString(0x26))
{
}
```

The current `STR.RES` payload maps string id `0x26` / decimal `38` to:

```text
Save profile? (Y/N) 
```

Use the string text as evidence in prose/support docs, not as a hard-coded source literal in the factory.

## Target

- Target UID: `0001KQ`
- Target path: `source-3/project-documentation/by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/0001KQ-SelfSaveInputPaneFactory-source-quality.md`
- Current metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000NM`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NM`, blank formal C++.
- Current generated output route: `auto-generated/NexusTK/ui/dialogs/SelfSaveInputPane.cpp`.
- Current by-memory coverage row is stale at `78%`; exact replacement text is below.

## Evidence Checked

Required rules and workflow:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B012/goal.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`

Target and direct support docs:

- [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md)
- [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md)
- [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md)
- [UID:0001MU][0x005b67c0-0x005b68b0.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b0.SelfSaveInputPane.md)
- [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md)
- [UID:0003O6][0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md)
- [UID:0003O7][0x005b6870-0x005b68b0.SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b0.SelfSaveInputPaneSendSelfSavePacketRaw.md)
- [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md)
- [UID:0003HM][SelfSaveInputPaneVtables](by-type/by-vtable/SelfSaveInputPaneVtables.md)

Source-family and dependency docs:

- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:00001P][CharInputPane](by-class/CharInputPane.md)
- [UID:000363][0x004f28a0-0x004f2913.CharInputPaneConstructor](by-memory/0x004f28a0-0x004f2913.CharInputPaneConstructor.md)
- [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md)
- [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md)
- [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md)
- [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md)
- [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

Generated/report state:

- `source-3/project-documentation/by-memory/-coverage-report.md`
- `source-3/project-documentation/project-level/-auto-completion-stats.md`
- `source-3/project-documentation/auto-generated/-ag-memory-coverage.md`
- `source-3/project-documentation/project-level/-resolved.md`
- `source-3/project-documentation/project-level/-unresolved.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/executed/older/0001KM-livingobject-localplayer-source-split-audit.md`

Local binary/export evidence:

- Fresh read-only PE scan over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Current `STR.RES` payload extracted from documented `baram.dat` entry offset `11,268,984`, size `7,058`, solely to resolve id `0x26`.
- Local prewave exports:
  - `source-3/core/data/cache/prewave/functions/0x005aa140.json`
  - `source-3/core/data/cache/prewave/_bundles/decompiled/9311f4e54e50fc1df4dcc6c648a91680a44f0a34e7e6f064df7f79fa9872dac8.json`
  - `source-3/core/data/cache/prewave/functions/0x005b67c0.json`
  - `source-3/core/data/cache/prewave/_bundles/decompiled/3379d688f4c99afa873a5ec4f4450438cf6f69b941866427684998bea9b2bb46.json`
  - referenced target callee/xref bundles.

No live IDA MCP tool was exposed in this session. Existing target/support pages record prior live IDA MCP results; the fresh evidence added by this pass is the PE route/byte scan, string id extraction, and direct prewave-bundle comparison.

## Behavior And Boundaries

Fresh PE scan details:

- PE image base: `0x00400000`.
- `.text` section: `VA=0x00401000`, `RVA=0x1000`, virtual size `0x20b4ac`, raw size `0x20b600`.
- Filename range: `0x005aa140-0x005aa1bf`.
- Actual modeled function range: `0x005aa140-0x005aa1c0`, size `0x80`, with the final byte at `0x005aa1bf`.
- Predecessor bytes `0x005aa130-0x005aa140` end with a normal `ret` at `0x005aa13f`; there is no fallthrough into the target.
- Target start `0x005aa140-0x005aa170`:
  - `55 8B EC 6A FF 68 11 AE 60 00 64 A1 00 00 00 00 50 51 56 A1 24 2F 67 00 33 C5 50 8D 45 F4 64 A3 00 00 00 00 68 08 01 00 00 E8 32 A9 F4 FF 8B F0`
- Target epilogue `0x005aa1a0-0x005aa1c0`:
  - `00 00 10 06 63 00 C7 86 A4 00 00 00 40 06 63 00 8B 4D F4 64 89 0D 00 00 00 00 59 5E 8B E5 5D C3`
- Successor start `0x005aa1c0-0x005aa1e0` begins a separate prologue-shaped body:
  - `55 8B EC 83 EC 14 A1 24 2F 67 00 33 C5 89 45 FC 8D 45 EC 50 6A 09 E8 A5 B1 FC FF 8B 0D EC A7 67`

IDA/prewave decompilation for the target reduces to:

- allocate `0x108` / decimal `264` bytes through [UID:000196][OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md);
- if allocation succeeds, read [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md);
- call `LanguageMan::GetLocalizedString(0x26)`;
- call [UID:000363][CharInputPaneConstructor](by-memory/0x004f28a0-0x004f2913.CharInputPaneConstructor.md) on the allocated object;
- install the three `SelfSaveInputPane` vtable views:
  - primary `0x006305c0` at object offset `+0x00`;
  - secondary `0x00630610` at object offset `+0xa0`;
  - tertiary `0x00630640` at object offset `+0xa4`;
- return the constructed pointer, or null on allocation failure.

This matches the raw constructor body [UID:0003O5] except that [UID:0001KQ] includes allocation and null-check/SEH construction state. It is therefore best understood as a no-argument factory/create helper, not an ordinary instance method and not compiler glue.

## Fresh Route / Liveness Scan

Fresh PE scan results:

| Target | Result | Interpretation |
| --- | --- | --- |
| `0x005aa140` | `rel32=0`, `absVA=0`, `RVA=0` | No ordinary call/jump, vtable/table pointer, or RVA route to this factory. |
| `0x005b67c0` | `rel32=0`, `absVA=0`, `RVA=0` | Raw constructor start has no ordinary entry route. |
| `0x005b6800` | `rel32=0`, `absVA=1`, `RVA=0`; absolute VA at `0x00630608/.rdata` | Positive control: the virtual confirm handler is vtable-routed. |
| `0x005b6870` | `rel32=0`, `absVA=0`, `RVA=0` | Raw send helper has no ordinary route. |
| `0x004f28a0` | `rel32=50`, `absVA=0`, `RVA=0` | Positive control: base `CharInputPane` constructor has normal direct call fan-in. |
| `0x004f4aa0` | `rel32=1785`, `absVA=0`, `RVA=0` | Positive control: project operator-new wrapper has broad call fan-in. |

The route scan confirms and strengthens the prior IDA "no callers / xrefs_to zero" finding. It does not prove the helper was absent from original source; it proves no ordinary binary route exists in this executable. The best current liveness classification is "retained no-route source helper." A hidden computed call without any stored target cannot be completely disproven, but no evidence supports it.

## Resolved Names, Types, And Dependencies

Use these source-facing names in future target/support docs:

| Old/generated label | Recommended source-facing name | Evidence |
| --- | --- | --- |
| `sub_5AA140` / `SelfSaveInputPaneFactory` | `CreateSelfSaveInputPane` | No-arg allocation wrapper returning a new prompt object; no attach/activate side effect, so `Create` is more accurate than `Open`. |
| `sub_4F4AA0` | `operator new` / `OperatorNewWrapper` | [UID:000196] documents exact `GetMemoryMan -> AllocateBufferMemory` global allocation wrapper with 1,785 rel32 callers. |
| `dword_67A750` / `DAT_0067a750` | `g_pLanguageMan` | [UID:0000RC] documents singleton address `0x0067a750`, lifecycle, 192-xref localization fanout. |
| `sub_4F0350` / `meth_0x4f0350` | `LanguageMan::GetLocalizedString` | [UID:00018U] documents `this+0x4` string table, `this+0x8` count, fallback literal, and broad caller fanout. |
| `sub_4F28A0` | `CharInputPane::CharInputPane` | [UID:000363] documents base constructor boundary, vtable stores, and edit-disable behavior. |
| vtable stores at `0x006305c0/0x00630610/0x00630640` | `SelfSaveInputPane` primary/secondary/tertiary vtables | [UID:0002N8] and [UID:0003HM] document decorated table names, store refs from factory and raw constructor, and confirm-handler slot. |

String id resolution:

- `0x26` / decimal `38` is the prompt string id passed to `LanguageMan::GetLocalizedString`.
- Current `STR.RES` payload line `0x26` is `Save profile? (Y/N) `.
- Adjacent lines validate the table alignment: `0x23` is `Throw what? [%s ?] `, `0x24` is `Cast which spell? [%s ?] `, `0x25` is `      - Usable spells -`, `0x27` is `Ignore list - (A)dd,(D)elete,(?)List `.

## Paired Constructor / Handler / Send-Helper Relationship

The paired [UID:0003O5] raw constructor and this target share the same construction sequence:

- read `g_pLanguageMan`;
- lookup string id `0x26`;
- call `CharInputPane::CharInputPane`;
- install `SelfSaveInputPane` vtables at object offsets `+0`, `+0xa0`, and `+0xa4`.

The difference is source shape:

- [UID:0003O5] is an in-place constructor body: `SelfSaveInputPane::SelfSaveInputPane()`.
- [UID:0001KQ] is an allocation wrapper/factory with `operator new(0x108)` and null-check before the same constructor sequence. Human source should be `return new SelfSaveInputPane;`.

The active virtual handler [UID:0003O6] is vtable-routed through `0x00630608 -> 0x005b6800`. It reads one character, accepts only `y` or `Y`, then builds and queues a one-byte opcode `0x25` packet through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) and [UID:0001HU][QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md). Non-matching input returns without sending.

The raw helper [UID:0003O7] sends the same opcode `0x25` packet without reading input first, but it still has no direct raw-start xref/route. Best source-facing name if retained is `SelfSaveInputPane::SendSelfSavePacket()` or file-local `SendSelfSavePacket()`, but the no-route state should remain explicit.

The target [UID:0001KQ] does not call the raw send helper. It constructs the prompt only.

## Source Placement Analysis

Ranked placement outcomes:

1. Keep current direct owner/emitter [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md) for now.
   - This target is a file-level factory/helper, not a class method. It has no `this` input and no vtable slot.
   - It constructs only `SelfSaveInputPane`, uses the same `SelfSaveInputPane` vtable family as the raw constructor, and belongs with the prompt family rather than LivingObjectPane or generic input bases.
   - [UID:0000NM] currently provides the non-dead-ended generated route used by the target and the related SelfSave docs.

2. Treat [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) as the likely final source-file consolidation target, but do not move this helper alone.
   - [UID:0000NM] itself says evidence favors folding `SelfSaveInputPane` into [UID:0000ID] rather than keeping a final standalone `SelfSaveInputPane.cpp`.
   - [UID:0000ID] lists `SelfSaveInputPane` in proposed contents and places command input prompt classes under `ui/dialogs/CommandInputPanes.cpp`.
   - Moving only [UID:0001KQ] would split one prompt class across two output files while constructor, handler, raw helper, and vtables still route through [UID:0000NM]/[UID:0000CW]. The safer future change is a coordinated consolidation of the whole SelfSave source family.

3. Reject [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md) as canonical owner for this target.
   - The helper is a no-arg free/static factory body, not a method with a `this` pointer.
   - Class ownership is correct for the constructor, confirm handler, raw send helper, and vtable data, but not for a source-module factory unless later evidence proves it was a `static` class member.

4. Reject LivingObjectPane/UserPane physical-neighborhood ownership.
   - The target lies inside the larger local-player/UserPane address neighborhood, but [UID:0001KM] B001 audit explicitly excludes [UID:0001KQ] as `SelfSaveInputPane`, not LivingObjectPane.
   - The body touches no `LivingObjectPane` or `UserPane` fields and has no caller from the local-player dispatcher.

5. Reject generic InputPanes ownership.
   - The helper consumes [UID:00001P][CharInputPane](by-class/CharInputPane.md), but its vtable stores and prompt semantics are specific to `SelfSaveInputPane`.
   - [UID:0000K7][InputPanes](by-file/InputPanes.md) should own reusable base classes, not feature-specific command prompts.

6. Reject compiler/runtime/generated glue.
   - The body is not an adjustor thunk, scalar deleting destructor, EH-only cleanup, allocator wrapper, or padding.
   - It has a full source-level allocation/null-check/constructor shape and class-specific vtable stores.

## Heuristic / Inference Reanalysis And Validation

Issue: no caller route.

- Evidence checked: existing IDA caller/xref notes, target xrefs bundle, fresh PE rel32/absolute/RVA scan, predecessor/successor bytes, vtable positive controls.
- Result: no route to `0x005aa140` found. No fallthrough from the predecessor, because `0x005aa13f` is a `ret`. The successor at `0x005aa1c0` is a separate prologue-shaped function.
- Best inference: retained no-route source helper. It may be an unused factory compiled into a larger object file, or an old command/open helper whose active call path was removed/inlined elsewhere.
- Score/source impact: keep confidence below final levels and document liveness caveat; do not treat as no-code compiler glue.

Issue: final source-facing helper name.

- Candidates considered: `SelfSaveInputPaneFactory`, `OpenSelfSaveInputPane`, `CreateSelfSaveInputPane`, `NewSelfSaveInputPane`, class static `SelfSaveInputPane::Create`.
- Accepted: `CreateSelfSaveInputPane`.
- Reasoning: function has no parameters, allocates and returns a prompt pointer, and does not activate/show/attach it. `Open` overstates side effects. `Factory` is a documentation label, not likely mid-2000s source spelling. Class static ownership is unproven.

Issue: first-draft C++ readiness.

- Evidence checked: target decompilation, paired constructor decompilation, vtable stores, resolved dependencies, code-entry gate rule.
- Result: target meets the numeric gate (`85/86`, average `85.5`) and has a non-dead-ended emitter route. The source shape is clear enough for a first draft.
- Recommendation: add the first-draft helper if supervisor accepts emitting retained no-route helpers. The no-route caveat should remain in prose. Source should be `return new SelfSaveInputPane;`, not a decompiler-shaped vtable-store body.

Issue: localized prompt identity.

- Evidence checked: [UID:0001RP] `str.res` loader/payload docs and direct extraction of documented `STR.RES` payload from `baram.dat`.
- Result: id `0x26` maps to `Save profile? (Y/N) `.
- Recommendation: document the mapping on target/support pages and [UID:0001RP] as a high-value id mapping if desired. Do not hard-code the literal in the factory source.

Issue: source file route.

- Evidence checked: [UID:0000NM], [UID:0000ID], proposed source tree, B001 [UID:0001KM] audit, paired SelfSave docs.
- Result: current route through [UID:0000NM] is valid for this immediate target; [UID:0000ID] is the likely final consolidation file, but moving only this helper would create inconsistent output.
- Recommendation: leave metadata on [UID:0000NM] now; record a support-doc implementation note that future consolidation should move the entire SelfSave prompt family together.

Issue: raw constructor/send-helper relationship.

- Evidence checked: [UID:0003O5], [UID:0003O6], [UID:0003O7], vtable data, PE route scan.
- Result: factory and constructor share construction semantics; confirm handler is vtable-routed and active; raw send helper is source-shaped but no-route.
- Recommendation: support docs should separate these roles clearly: factory/create helper, constructor, virtual confirmation handler, retained raw send helper.

Issue: generated placeholder pollution.

- Evidence checked: project-level unresolved/resolved rows and dependency pages.
- Result: target still contains unresolved old labels `sub_4F4AA0`, `sub_4F0350`, `sub_4F28A0`, and `dword_67A750`.
- Recommendation: update prose to use `operator new` / [UID:000196], `g_pLanguageMan`, `LanguageMan::GetLocalizedString`, and `CharInputPane::CharInputPane` while keeping old labels in a historical/search note.

## Recommended Target Doc Changes

Apply these after supervisor review:

1. Update metadata:
   - `COMPLETION:87`
   - `CONFIDENCE:88`
   - `CANONICAL_OWNER:0000NM`
   - `RECONSTRUCTABLE:TRUE`
   - `EMITTER_UIDS:0000NM`
   - Keep position blank.
2. Add/update status text:
   - "Source-authored retained no-argument factory/create helper for `SelfSaveInputPane`."
   - "Fresh B012 PE scan found no rel32 call/jump, absolute VA, or RVA pointer route to `0x005aa140`; this is a retained/no-route liveness caveat, not compiler glue."
3. Replace generated dependency names in prose:
   - `sub_4F4AA0` -> `operator new` / [UID:000196].
   - `dword_67A750` -> [UID:0000RC] `g_pLanguageMan`.
   - `sub_4F0350` -> `LanguageMan::GetLocalizedString`.
   - `sub_4F28A0` -> `CharInputPane::CharInputPane`.
4. Add the string id finding:
   - `0x26` / `38` resolves to `Save profile? (Y/N) ` in current `STR.RES`.
5. Add the source-shape note:
   - "Do not reconstruct the target as manual vtable stores; human source should be a creation helper returning `new SelfSaveInputPane`, while [UID:0003O5] carries constructor semantics."
6. Add the route-scan table or equivalent compact evidence:
   - `0x005aa140`: no rel32/absVA/RVA hits.
   - Positive controls: `0x005b6800` has vtable absVA at `0x00630608`; `0x004f28a0` has 50 rel32 calls; `0x004f4aa0` has 1,785 rel32 calls.
7. Add first-draft C++ if the supervisor accepts code insertion for retained no-route helpers:

```cpp
SelfSaveInputPane *CreateSelfSaveInputPane()
{
    return new SelfSaveInputPane;
}
```

If the supervisor chooses to keep formal C++ blank despite the draft, the target doc must say explicitly that the reason is the no-route retained-helper caveat and coordinated SelfSave/CommandInputPanes source-file consolidation, not lack of a source-shaped body.

## Recommended Support Doc Changes

[UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md):

- Add B012 source-quality note for [UID:0001KQ].
- Record `CreateSelfSaveInputPane` as the best source-facing name/signature.
- Record string id `0x26` -> `Save profile? (Y/N) `.
- Record fresh no-route PE scan for `0x005aa140`.
- Clarify that this page remains the immediate emitter route only until a coordinated move to [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) is accepted.
- Preserve the existing statement that final source grouping likely folds the class into `CommandInputPanes.cpp`; add that the factory should move only with the whole SelfSave prompt family.

[UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md):

- Add the factory as a related file-level helper, not a class method.
- Update stale "90/90+" final-C++ wording to the current `85/85` combined gate language where it appears, while preserving target-specific C++ caveats for raw/no-route children.
- Add the constructor source shape:

```cpp
SelfSaveInputPane::SelfSaveInputPane()
    : CharInputPane(g_pLanguageMan->GetLocalizedString(0x26))
{
}
```

- Add the string mapping and no-route distinction:
  - factory [UID:0001KQ] no route;
  - constructor [UID:0003O5] raw no route;
  - confirm handler [UID:0003O6] vtable route;
  - send helper [UID:0003O7] raw no route.

[UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md):

- Add a note that SelfSave remains a likely final member of `CommandInputPanes.cpp`, but this B012 pass does not recommend moving only [UID:0001KQ].
- State that future consolidation should move [UID:0000NM], [UID:0000CW], [UID:0001KQ], [UID:0003O5], [UID:0003O6], [UID:0003O7], and [UID:0002N8]/[UID:0003HM] together or leave a documented compatibility route.

[UID:0003O5][SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md):

- Add string id `0x26` text and `g_pLanguageMan` / `LanguageMan::GetLocalizedString` names.
- Add constructor source-shape draft as above.
- Keep formal C++ blank or populate only in a coordinated SelfSave implementation callback; raw no-entry status remains a caveat.

[UID:0003O6][SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md):

- Replace stale "90/90+" blocker wording with current combined-gate wording.
- State that this method is the active vtable-routed submit path and already sends opcode `0x25` inline after `y/Y`.
- Do not rewrite it as a call to [UID:0003O7] unless a real route appears.

[UID:0003O7][SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b0.SelfSaveInputPaneSendSelfSavePacketRaw.md):

- Name best source-facing helper as `SelfSaveInputPane::SendSelfSavePacket()` if later routed.
- Preserve no-route status; fresh PE scan again found no rel32/absVA/RVA route to `0x005b6870`.
- Clarify that [UID:0001KQ] does not call it.

[UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md):

- Optional support update: add id `0x26` / decimal `38` to any high-value id map as `Save profile? (Y/N) `, consumed by SelfSave prompt construction.

[UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md):

- Optional support update: add `SelfSaveInputPane` to the prompt-constructor examples: string id `0x26` is read before `CharInputPane` construction.

## Metadata / Score Recommendation

Target score should become `87/88`.

Completion improves from `85` to `87` because this pass adds:

- fresh PE route scan with positive controls;
- exact prompt string mapping;
- generated-name cleanup;
- first-draft source shape;
- explicit paired constructor/handler/helper relationship;
- ranked source-placement and owner/emitter alternatives;
- exact coverage replacement text.

Confidence improves from `86` to `88` because construction behavior, dependencies, vtable identity, range, and source shape are now strongly corroborated. It remains below final levels because:

- no runtime route to the factory is known;
- final source-file consolidation between [UID:0000NM] and [UID:0000ID] remains unsettled;
- raw constructor/send helper pages still have no ordinary entry routes;
- final original helper spelling is inferred/descriptive.

Do not raise to `95+`; the no-route and final source-file questions are material.

## Exact Callback Implementation Instructions

If the supervisor accepts this report, send B012 an implementation callback with these concrete steps:

1. Edit only accepted target/support by-* docs; do not edit `by-memory/-coverage-report.md`.
2. Update [UID:0001KQ] metadata to `87/88`, keep owner/emitter `0000NM`, and add the full B012 evidence sections listed under "Recommended Target Doc Changes".
3. Insert the first-draft C++ block for [UID:0001KQ] if accepting retained no-route helper emission:

```cpp
SelfSaveInputPane *CreateSelfSaveInputPane()
{
    return new SelfSaveInputPane;
}
```

4. If the supervisor rejects immediate formal C++, leave the block blank but add the explicit defer proof: "source shape is known, but formal emission is deferred because no ordinary route to `0x005aa140` is proven and the SelfSave-vs-CommandInputPanes source-file consolidation should be coordinated."
5. Update [UID:0000NM], [UID:0000CW], and [UID:0000ID] with the report-level source-placement reasoning, not a short summary.
6. Update [UID:0003O5], [UID:0003O6], and [UID:0003O7] with the string id, current gate wording, and route distinctions where applicable.
7. Optionally update [UID:0001RP] and [UID:0000RC] with the id `0x26` mapping and SelfSave consumer example.
8. Carry the exact coverage row below for supervisor-owned application.
9. Run the validation commands listed below and report exact results.

## Exact Coverage Text

Replace the current [UID:0001KQ] row in `by-memory/-coverage-report.md` with:

```md
    - [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md) 0x005aa140-0x005aa1bf | function | SelfSaveInputPaneFactory : reconstructable : 87% : strong : Source-authored retained no-argument `SelfSaveInputPane` creation helper; B012 2026-06-19 recheck resolves the source shape as `CreateSelfSaveInputPane()` returning `new SelfSaveInputPane`, maps localized string id `0x26` to `Save profile? (Y/N) `, normalizes `dword_67A750` to [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), and links the allocation/base-constructor/vtable sequence to [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md), [UID:000363][0x004f28a0-0x004f2913.CharInputPaneConstructor](by-memory/0x004f28a0-0x004f2913.CharInputPaneConstructor.md), and [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md). Fresh PE scan found no rel32 call/jump, absolute VA, or RVA pointer route to `0x005aa140` while positive controls found the [UID:0003O6][0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md) vtable pointer, 50 rel32 calls to `CharInputPane::CharInputPane`, and 1,785 rel32 calls to the operator-new wrapper; keep immediate owner/emitter [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md) pending coordinated `CommandInputPanes` consolidation.
```

No direct edit to `by-memory/-coverage-report.md` should be made by B012 during the report-only phase.

## Validation Commands Needed After Implementation

Run from `E:\NTK\GhidraBridge` after the implementation callback applies accepted edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001KQ-SelfSaveInputPaneFactory-source-quality-removed.md](0001KQ-SelfSaveInputPaneFactory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional resource/global notes are edited:

> Executable block R002 was removed from this report and preserved verbatim in [0001KQ-SelfSaveInputPaneFactory-source-quality-removed.md](0001KQ-SelfSaveInputPaneFactory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After the supervisor applies the banned coverage row:

> Executable block R003 was removed from this report and preserved verbatim in [0001KQ-SelfSaveInputPaneFactory-source-quality-removed.md](0001KQ-SelfSaveInputPaneFactory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

No validators were run during this report-only pass because no by-* docs were edited.

## IDA Rename / Type / Comment Recommendations

Rename/type recommendations if IDA edits are later allowed:

- At `0x005aa140`:
  - Name: `CreateSelfSaveInputPane`
  - Type: `SelfSaveInputPane *__cdecl CreateSelfSaveInputPane(void)`
  - Comment: "Retained no-route source helper. Allocates 0x108-byte SelfSaveInputPane, inlines constructor prompt id 0x26 (`Save profile? (Y/N) `), installs SelfSave vtables; B012 PE scan found no rel32/VA/RVA route."
- At `0x005b67c0`:
  - Name if forcing a raw label: `SelfSaveInputPane_ctor_raw`
  - Preferred source name if modeled: `SelfSaveInputPane::SelfSaveInputPane`
- At `0x005b6870`:
  - Audit label: `SelfSaveInputPaneSendSelfSavePacketRaw`
  - Source name if route appears: `SelfSaveInputPane::SendSelfSavePacket`
- At `0x0067a750`:
  - Keep/confirm `g_pLanguageMan`.
- At `0x004f0350`:
  - Keep/confirm `LanguageMan::GetLocalizedString`.

Confidence:

- High for target behavior, size, and dependency roles.
- Medium-high for `CreateSelfSaveInputPane` name because original spelling is not proven.
- High for `g_pLanguageMan`, `operator new`, and `GetLocalizedString` role names based on existing docs.
- Low for runtime liveness because no ordinary target route exists.

## Open Questions Closed Or Remaining

Closed:

- Source-bearing vs compiler glue: source-bearing retained helper.
- Exact allocation size: `0x108` / decimal `264`.
- Localized string id: `0x26` / decimal `38`.
- Localized string current text: `Save profile? (Y/N) `.
- Base constructor: `CharInputPane::CharInputPane`.
- Vtable family: `SelfSaveInputPane` primary/secondary/tertiary views at `0x006305c0/0x00630610/0x00630640`.
- Factory source shape: `CreateSelfSaveInputPane()` returning `new SelfSaveInputPane`.
- LivingObjectPane ownership: rejected.
- Generic `InputPanes.cpp` ownership: rejected.
- Immediate metadata route: keep [UID:0000NM] for now.

Remaining:

- No ordinary runtime route to `0x005aa140` is known. This caps confidence and should stay visible in target/support docs.
- Exact original helper spelling is inferred. `CreateSelfSaveInputPane` is best descriptive source name, not proven original.
- Final source-file consolidation remains open. [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) is the likely final file, but moving only this helper would fragment the family.
- Formal C++ insertion depends on whether the supervisor accepts emitting retained no-route helpers at this stage. The draft is ready; a blank formal block is defensible only with the explicit defer proof above.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/0001KQ-SelfSaveInputPaneFactory-source-quality.md`
- Modified: none outside the B012 research folder.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/0001KQ-SelfSaveInputPaneFactory-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"0001KQ"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001KQ-SelfSaveInputPaneFactory-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/0001KQ-SelfSaveInputPaneFactory-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001KQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
