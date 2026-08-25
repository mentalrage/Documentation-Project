** TARGET-REPORT-UID:0003O5 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003O5 **
# 0003O5 SelfSaveInputPaneConstructorRaw Source-Quality Research

## Final Recommendation

- Keep [UID:0003O5] source-bearing and reconstructable as `SelfSaveInputPane::SelfSaveInputPane()`.
- Recommended metadata: `COMPLETION:88`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:0000CW`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000CW`.
- The old blank-C++ blocker is stale. IDA still lacks a function object at `0x005b67c0`, and no direct caller/start pointer is currently known, but the body is a complete unique constructor-shaped range with exact source semantics, class-owned vtable installation, and the active `85/85` gate clears.
- Emit first-draft constructor C++ on this target page. Omit the three vptr stores from C++ because they are compiler-generated effects of the derived class declaration.
- Keep direct owner/emitter [UID:0000CW] `SelfSaveInputPane`. The current source-file route remains [UID:0000NM] `SelfSaveInputPane` / `NexusTK/ui/dialogs/SelfSaveInputPane.cpp`; [UID:0000ID] `CommandInputPanes` remains a plausible final grouping alternate but is not strong enough to move this exact constructor child.
- No by-* docs, generated files, IDA DB, project-level reports, or `by-memory/-coverage-report.md` were edited in this report-only pass.

## Target Paths

- Target UID: [UID:0003O5]
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B005\research\0003O5-SelfSaveInputPaneConstructorRaw-source-quality.md`
- Current target state: `85/86`, `CANONICAL_OWNER:0000CW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CW`, blank formal C++.

## Evidence Checked

- Workflow and source-quality rules:
  - `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
  - `.codex/AGENTS.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B005/goal.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B005/notes.md`
- Target/support docs:
  - `by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md`
  - `by-memory/0x005b67c0-0x005b68b0.SelfSaveInputPane.md`
  - `by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md`
  - `by-memory/0x005b6870-0x005b68b0.SelfSaveInputPaneSendSelfSavePacketRaw.md`
  - `by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md`
  - `by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md`
  - `by-type/by-vtable/SelfSaveInputPaneVtables.md`
  - `by-class/SelfSaveInputPane.md`
  - `by-file/SelfSaveInputPane.md`
  - `by-file/CommandInputPanes.md`
  - `by-class/CharInputPane.md`
  - `by-memory/0x004f28a0-0x004f2913.CharInputPaneConstructor.md`
  - `by-file/InputPanes.md`
  - `by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md`
  - `by-memory/0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks.md`
  - `by-file/LanguageMan.md`
  - `by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md`
  - `by-global/g_pLanguageMan.md`
  - `by-resource/str-res-localized-strings.md`
- Generated/exported data checked as historical evidence only:
  - `auto-generated/NexusTK/ui/dialogs/SelfSaveInputPane.cpp`
  - `resources/exported_data/master_names.json`
  - `resources/exported_data/master_function_list.json`
  - `resources/exported_data/master_vtables.json`
  - `source-3/core/data/readonly/wave2/metadata/reports/report-0.json`
- Current coverage context:
  - `by-memory/-coverage-report.md` around the `0x005b67c0` SelfSave island.
- Local PE / Capstone recheck:
  - Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - Size: `2679296`
  - MD5: `4247e04e20b65d6414c7238aa8ff5515`
  - SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
  - Image base: `0x00400000`
  - Sections checked: `.text 0x00401000-0x0060c600`, `.rdata 0x0060d000-0x0066c200`, `.data 0x0066d000-0x0069ce24`, `.rsrc 0x0069d000-0x006b2e00`
  - Capstone 5.0.7 was available. `pefile` was not used; the PE headers were parsed directly.
- Resource payload check:
  - `E:\2026\Resources\Read_Only\NexusTK\Data\baram.dat`
  - Existing resource docs identify `STR.RES` at offset `11,268,984`, size `7,058`.
  - Extracted that slice read-only and decoded through Windows codepage 949 for nearby ids.

## Exact Boundary, Bytes, And Route Evidence

- Exact target range: `0x005b67c0-0x005b6800`, half-open, size `0x40` / 64 bytes.
- File offset for target start in the checked PE: `0x001b5bc0` in `.text`.
- Target range hashes:
  - MD5: `ed9b6f2d02c635213f398645e58c086f`
  - SHA1: `c403a4bdc553134733eb8e5719f9cb47b0a393b6`
  - SHA256: `935e0b3fa94d6aa1b5125bcfea43f2187837ffa909ed56d7a3606cf95322f702`
- Exact bytes:

```text
55 8b ec 51 56 8b f1 8b 0d 50 a7 67 00 6a 26 89
75 fc e8 79 9b f3 ff 50 8b ce e8 c1 c0 f3 ff c7
06 c0 05 63 00 8b c6 c7 86 a0 00 00 00 10 06 63
00 c7 86 a4 00 00 00 40 06 63 00 5e 8b e5 5d c3
```

- Full 64-byte target sequence occurs exactly once in the PE. The first 16 bytes and the post-prologue core from `0x005b67c7` also occur exactly once.
- Predecessor bytes at `0x005b67b0-0x005b67c0`:

```text
8b 4d fc 33 cd e8 75 0f 01 00 8b e5 5d c2 04 00
```

  These are the predecessor body's epilogue and `ret 4`; there is no `0xcc` padding before the constructor start.
- Successor bytes at `0x005b6800-0x005b6810`:

```text
55 8b ec 83 ec 18 a1 24 2f 67 00 33 c5 89 45 fc
```

  `0x005b6800` begins the modeled confirm-input handler [UID:0003O6] immediately. There is no trailing padding after this constructor.
- `0x005b686c-0x005b6870` is four `0xcc` bytes between [UID:0003O6] and the raw send helper [UID:0003O7]. `0x005b68b0-0x005b68c0` is the later padding before the BlockListen neighborhood, not part of this target.
- Raw branch scan over `.text` found:
  - zero direct `call`, `jmp`, `jcc`, or short-branch refs to `0x005b67c0`;
  - zero direct branch refs to `0x005b6800`;
  - zero direct branch refs to `0x005b6870`;
  - zero direct branch refs to `0x005aa140`.
- Literal scan found:
  - zero absolute VA hits for `0x005b67c0`;
  - zero RVA hits for `0x001b67c0`;
  - zero raw-offset hits for the target start;
  - exactly one absolute pointer to `0x005b6800`, at `0x00630608` in `.rdata`, the primary SelfSaveInputPane vtable confirm-input slot.
- Vtable-base literal hits:
  - `0x006305c0`: two text immediates, factory store at `0x005aa196` and raw constructor store at `0x005b67df`;
  - `0x00630610`: two text immediates, factory store at `0x005aa19c` and raw constructor store at `0x005b67e7`;
  - `0x00630640`: two text immediates, factory store at `0x005aa1a6` and raw constructor store at `0x005b67f1`.
- This proves the constructor start is route-negative by current static references, while the body itself and the matching factory both install the same class vtables. The modeled runtime-dispatch route exists for the confirm handler through `0x00630608`, not for the raw constructor start.

## Disassembly-Level Body Evidence

Capstone disassembly of `0x005b67c0-0x005b6800`:

```text
005b67c0: push ebp
005b67c1: mov ebp, esp
005b67c3: push ecx
005b67c4: push esi
005b67c5: mov esi, ecx
005b67c7: mov ecx, dword ptr [0x67a750]
005b67cd: push 0x26
005b67cf: mov dword ptr [ebp - 4], esi
005b67d2: call 0x4f0350
005b67d7: push eax
005b67d8: mov ecx, esi
005b67da: call 0x4f28a0
005b67df: mov dword ptr [esi], 0x6305c0
005b67e5: mov eax, esi
005b67e7: mov dword ptr [esi + 0xa0], 0x630610
005b67f1: mov dword ptr [esi + 0xa4], 0x630640
005b67fb: pop esi
005b67fc: mov esp, ebp
005b67fe: pop ebp
005b67ff: ret
```

Source-shape interpretation:

- `ECX` on entry is `this`.
- The constructor saves `this` in `ESI` and local `[ebp-4]`.
- It reads [UID:0000RC] `g_pLanguageMan` / `dword_67A750`.
- It pushes string id `0x26` / decimal `38`.
- It calls [UID:00018U] `LanguageMan::GetLocalizedString` at `0x004f0350`.
- It passes the returned `const wchar_t *` as the sole explicit argument to [UID:000363] `CharInputPane::CharInputPane` at `0x004f28a0`, with `ECX=this`.
- It installs the primary `SelfSaveInputPane` vtable at object `+0x00`, the secondary view at `+0xa0`, and the tertiary view at `+0xa4`.
- It sets `EAX=this` at `0x005b67e5` and returns with plain `ret`, so the source signature has no explicit constructor arguments.

The matching factory/open helper at `0x005aa140-0x005aa1c0` duplicates the same class construction sequence after allocation and EH setup:

```text
005aa164: push 0x108
005aa169: call 0x4f4aa0
...
005aa181: mov ecx, dword ptr [0x67a750]
005aa187: push 0x26
005aa189: call 0x4f0350
005aa18e: push eax
005aa18f: mov ecx, esi
005aa191: call 0x4f28a0
005aa196: mov dword ptr [esi], 0x6305c0
005aa19c: mov dword ptr [esi + 0xa0], 0x630610
005aa1a6: mov dword ptr [esi + 0xa4], 0x630640
```

This factory allocates `0x108` bytes, uses the same prompt id, calls the same base constructor, and writes the same vptrs. The factory still has zero direct callers/xrefs to its start in current docs and local branch/literal scans, so it should remain a separate route/liveness caveat rather than the owner for this constructor page.

## Localized Prompt Evidence

- The constructor passes id `0x26` / decimal `38` to `LanguageMan::GetLocalizedString`.
- Existing resource docs place `STR.RES` in `baram.dat`, entry index `9`, offset `11,268,984`, size `7,058`.
- Read-only extraction of that slice and codepage-949 decoding gave these nearby zero-based entries:

```text
32: Which expression? [a-%c ? ] 
33: Wear what? [%s ?] 
34: Take off what? [washnlrfmc[]12A ?]
35: Throw what? [%s ?] 
36: Cast which spell? [%s ?] 
37:       - Usable spells -
38: Save profile? (Y/N) 
39: Ignore list - (A)dd,(D)elete,(?)List 
40: Who do you wish to ignore? > 
41: Who do you wish to hear? > 
42: What do you wish to give, and no longer own? [%s\?] 
```

- The concrete current-package text for id `0x26` is therefore `Save profile? (Y/N) `, including the trailing space.
- This aligns with the handler behavior in [UID:0003O6], which accepts only `y`/`Y` and then sends opcode `0x25`.
- The prompt text belongs to `STR.RES` / `LanguageMan`; the constructor should source-reference a symbolic string id such as `kSelfSavePromptStringId` rather than hard-code the English text.

## Vtable View Evidence

Current vtable docs and local byte scans agree on the three `SelfSaveInputPane` views:

| View | Table base / range | Object offset | Constructor store | Key source meaning |
| --- | --- | --- | --- | --- |
| Primary | `0x006305c0-0x0063060c` | `+0x00` | `0x005b67df` | complete-object view; scalar deleting destructor slot `0x005b7940`; confirm handler slot `0x00630608 -> 0x005b6800` |
| Secondary | `0x00630610-0x0063063c` | `+0xa0` | `0x005b67e7` | adjusted input/control-pane secondary view; adjustor thunk `0x005b77c8` |
| Tertiary | `0x00630640-0x00630648` | `+0xa4` | `0x005b67f1` | adjusted event/update view; adjustor thunk `0x005b77d3`, inherited slot `0x00544e90` |

The secondary and tertiary destructor adjustor thunks at `0x005b77c8` and `0x005b77d3` are shared compiler-generated input-pane thunks. They prove the `+0xa0/+0xa4` layout but should not be emitted as handwritten SelfSaveInputPane code.

## Heuristic / Inference Reanalysis And Validation

### Raw Constructor Status

Best conclusion: `0x005b67c0-0x005b6800` is a source-authored default constructor body that IDA failed to model as a function, not padding, not a compiler thunk, and not generated-only vtable data.

Evidence:

- Complete function-shaped prologue/epilogue and plain `ret`.
- No fall-through from predecessor: predecessor ends with `ret 4` at `0x005b67bd`.
- No fall-through into successor: this constructor ends at `0x005b67ff`; [UID:0003O6] begins with a fresh prologue at `0x005b6800`.
- Full byte sequence is unique.
- Body calls a project localization helper and the source-owned `CharInputPane` base constructor.
- Body installs all three class vtable views at the expected object offsets and returns `this`.
- Matching factory construction path at `0x005aa140` duplicates the same construction semantics.

The route-negative state remains real:

- local scan found no direct branch refs and no absolute/RVA/raw pointer refs to `0x005b67c0`;
- existing docs also record IDA `lookup_funcs 0x005b67c0` as "Not a function";
- active generated output currently emits only empty markers through the validator autogen page.

Impact: route-negative raw status caps the score and should stay in docs, but it no longer justifies blank C++. The target is already class-owned and reconstructable, and the source body is short and exact.

### Base Constructor Signature

Recommended base signature for this target:

```cpp
CharInputPane::CharInputPane(const wchar_t *promptText);
```

Evidence:

- `0x005b67d2` calls `LanguageMan::GetLocalizedString`, returning a string pointer in `EAX`.
- `0x005b67d7` pushes that one value.
- `0x005b67d8` sets `ECX=this`.
- `0x005b67da` calls `0x004f28a0`, the exact `CharInputPane` constructor page.
- The target returns with plain `ret`, so `SelfSaveInputPane::SelfSaveInputPane()` has no explicit parameters; the only explicit stack argument is consumed by the base constructor call.

Rejected base/source interpretations:

- `LineInputPane` direct construction: rejected because the call target is `0x004f28a0`, documented as `CharInputPane::CharInputPane`, not `LineInputPane::LineInputPane`.
- `ConfirmInputPane` construction: rejected because no callback/action pointer is stored and the class vtables are SelfSave, not Confirm.
- `SelfSaveOKPane` or MapPane confirmation dialog construction: rejected because this body derives from `CharInputPane` and lives in the command-input vtable neighborhood, while SelfSaveOKPane is a separate status pane/dialog island.

### Source-Facing Constructor Name And Shape

Recommended target source name/signature:

```cpp
SelfSaveInputPane::SelfSaveInputPane();
```

The source-facing body should express the localized prompt and base construction. It should not express vtable stores, `[ebp-4]`, `ESI`, or raw `dword_67A750` names.

Recommended symbolic constant:

```cpp
static const int kSelfSavePromptStringId = 0x26; // "Save profile? (Y/N) "
```

The exact original constant spelling is unproven. `kSelfSavePromptStringId` is a descriptive project-facing name that should be used until a broader string-id enum pass standardizes localized prompt ids.

Rejected names:

- `ctor_0x5b67c0`: generated/OOAnalyzer artifact, not source-facing.
- raw `SelfSaveInputPane` function label without `::SelfSaveInputPane`: ambiguous class/function artifact.
- `SelfSaveInputPaneRawConstructor`: documentation slug only.
- `FUN_005b67c0` / `sub_5B67C0`: generated raw label, not source-facing.

### Vtable Stores And Generated-Name Cleanup

The three vtable writes are important evidence but should be documented as compiler-emitted constructor tail effects, not handwritten source statements.

Generated pollution to clean up or quarantine in docs:

- Ghidra names `0x005b67c0` as `SelfSaveInputPane`, while IDA has no function object. Source docs should call it a raw constructor-shaped body and recommend IDA creation/rename only after route review.
- Ghidra names `0x005b6800` `virt_meth_0x5b6800`; source docs should prefer `SelfSaveInputPane::OnConfirmInput` or a closely equivalent confirmation handler name.
- Ghidra names `0x005b6870` `FUN_005b6870`; source docs should prefer `SelfSaveInputPane::SendSelfSavePacket` / private helper wording, with no-direct-xref caveat.
- Old rename metadata contains `SelfSaveInputPane\r`; treat the control-character name as stale generated metadata, not source evidence.
- `SelfSaveInputPane::vftable_6305c0` and raw `vftable_006305c0` labels are data artifacts; source docs should present primary/secondary/tertiary vtable views and let class declaration regenerate them.

### Owner, Emitter, And Source Placement

Keep:

- target owner [UID:0000CW] `SelfSaveInputPane`;
- target emitter [UID:0000CW];
- class/file route through [UID:0000NM] `SelfSaveInputPane`.

Ranking:

1. [UID:0000CW] `SelfSaveInputPane` class is the direct semantic owner for this target. The body constructs that class, installs its vtables, and belongs with its confirm-input and packet-send siblings.
2. [UID:0000NM] `SelfSaveInputPane` file is the current best emitter/source route because the project already has a dedicated file page, generated output path, class parent, factory page, and vtable page for the feature.
3. [UID:0000ID] `CommandInputPanes` remains a plausible final original grouping because SelfSave sits in the command-input address neighborhood with Emotion/Group/Post/BlockListen and derives from shared input-pane bases. This is a source-tree grouping question, not a target owner change.
4. [UID:0000K7] `InputPanes` owns `CharInputPane` infrastructure only. It should not own this feature-specific self-save prompt constructor.
5. [UID:0000HS] `BlockListenInputPanes` is successor context only. The successor constructor at `0x005b68c0` uses id `0x27`, not id `0x26`, and different vtables.
6. [UID:0000KC] `ItemActionInputPanes` is rejected. The adjacent Wear helper ends exactly at `0x005b67c0`; this constructor uses self-save opcode/prompt/vtables, not item-slot logic.
7. `SelfSaveOKPane`, `MapPane`, `UserPane`, `LanguageMan`, and `g_packetSender` are rejected as owners. They are feature-adjacent, resource-provider, or packet-provider contexts, not owners of this constructor body.

### Relationship To Confirm Handler, Raw Send Helper, And Factory

- [UID:0003O6] `0x005b6800-0x005b686c` is the virtual confirm-input handler. The primary vtable slot `0x00630608` points there. It accepts one-character `y`/`Y` input and sends opcode `0x25`.
- [UID:0003O7] `0x005b6870-0x005b68b0` is a raw packet helper-shaped body that sends opcode `0x25` without reading input. It still has no known direct start reference. It should be named/described as a SelfSave private packet helper, but its source placement/liveness should remain caveated separately.
- [UID:0001KQ] `0x005aa140-0x005aa1bf` is a factory/open helper that allocates `0x108` bytes and duplicates the same `SelfSaveInputPane` construction sequence. It has no known direct callers/xrefs. It should remain a source-module factory/open-helper candidate, not be merged into this constructor page.
- The constructor target should not be downgraded to no-code simply because the factory also performs inline construction. The standalone constructor bytes are unique, complete, and already represented as a split reconstructable child.

### First-Draft C++ Decision

First-draft C++ should be emitted now for this target after supervisor acceptance.

Reasons:

- Current target score and owner/emitter route clear the active reconstruction-code gate.
- The body has no unresolved control flow, local state, branch tables, packet format, or field layout beyond compiler vptr writes.
- The only semantic input is a localized string id, now resolved to current-package text.
- Base constructor signature is strongly inferred from the exact push/call sequence and CharInputPane support docs.
- Vtable stores are ordinary compiler constructor output and should be omitted from handwritten C++.

No-code proof is not applicable for this target. The exact no-code policy applies to the vtable-data page and adjustor thunks, not to this constructor body.

## First-Draft C++

Recommended formal C++ for `by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md`:

```cpp
SelfSaveInputPane::SelfSaveInputPane()
    : CharInputPane(g_pLanguageMan->GetLocalizedString(kSelfSavePromptStringId))
{
}
```

Recommended support constant in the class/file docs:

```cpp
static const int kSelfSavePromptStringId = 0x26; // "Save profile? (Y/N) "
```

Implementation notes:

- If the project standardizes the localization API as `LanguageMan::GetString` or a free `GetLocalizedString` wrapper, adapt the call spelling only. Keep id `0x26`.
- If class declaration C++ is added on the class page, use a normal declaration:

```cpp
class SelfSaveInputPane : public CharInputPane
{
public:
    SelfSaveInputPane();

protected:
    void OnConfirmInput() override;

    static const int kSelfSavePromptStringId = 0x26;

    [[CHILDREN]]
};
```

- Do not emit `*(void **)this = ...`, `*(void **)((char *)this + 0xa0) = ...`, or `*(void **)((char *)this + 0xa4) = ...` in source C++. Those are compiler-generated vptr stores.

## Recommended Target Changes

Target: `by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md`

1. Update metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Replace the stale blank-C++ note with:

```text
Formal C++ is ready as `SelfSaveInputPane::SelfSaveInputPane()`. IDA still lacks a function object and no direct caller/start pointer is known, but the raw bytes are a complete unique constructor body, the source owner/emitter gate clears, the localized prompt id is resolved, and the vtable stores are compiler-generated effects of the class declaration rather than a no-code reason.
```

3. Populate formal C++ with the first-draft constructor body above.
4. Add exact local PE/Capstone evidence:
   - PE hashes and section map.
   - Exact `0x40` body size and range hashes.
   - Full bytes or representative disassembly.
   - No `0xcc` padding before the start; predecessor ends with `ret 4`.
   - No trailing padding after the target; successor [UID:0003O6] begins at `0x005b6800`.
   - Full range is unique.
   - Zero branch refs and zero VA/RVA/raw pointer refs to `0x005b67c0`.
   - Vtable-base literal hits only at factory and target stores.
5. Add the resource finding:
   - id `0x26` / decimal `38`;
   - current `STR.RES` text `Save profile? (Y/N) `;
   - source should use a symbolic prompt id and not hard-code the English text.
6. Add base/signature evidence:
   - `0x005b67c7` loads `g_pLanguageMan`;
   - `0x005b67cd` pushes id `0x26`;
   - `0x005b67d2` calls `0x004f0350`;
   - `0x005b67d7` pushes returned string;
   - `0x005b67da` calls `CharInputPane::CharInputPane`;
   - vptr stores at `0x005b67df`, `0x005b67e7`, and `0x005b67f1`;
   - return at `0x005b67ff`.
7. Add rejected alternatives and cleanup guidance:
   - reject no-code/generate-only classification;
   - reject InputPanes, BlockListen, ItemAction, SelfSaveOKPane, MapPane, LanguageMan, and g_packetSender ownership;
   - reject decompiler/generated names `ctor_0x5b67c0`, `FUN_005b67c0`, and control-character `SelfSaveInputPane\r` as source names.
8. Add change-log entry:
   - B005 source-quality pass recommended `88/90`, resolved prompt id and source shape, preserved raw/no-xref caveat, and declared first-draft C++ readiness.

## Recommended Support-Doc Updates

Only update support docs during a supervisor implementation callback if facts are missing or weaker than this report.

- `by-class/SelfSaveInputPane.md`
  - Raise to approximately `87/89` if implementing all report details.
  - Add a class declaration shell with `SelfSaveInputPane()`, `OnConfirmInput()`, `kSelfSavePromptStringId = 0x26`, and `[[CHILDREN]]`, or add an equivalent source-shape note if the class page should stay declaration-blank.
  - Update the constructor row to source-facing `SelfSaveInputPane::SelfSaveInputPane()`, not just "constructor".
  - Record that `STR.RES` id `0x26` is current text `Save profile? (Y/N) `.
  - State that vptr stores at `+0/+0xa0/+0xa4` are compiler output from the declaration and should not block source C++.
  - Preserve direct class ownership and the route-negative raw-constructor caveat.
  - Reject `InputPanes`, `CommandInputPanes` as direct class owner, `SelfSaveOKPane`, `BlockListenInputPane`, and packet-sender/global ownership for this constructor.
- `by-file/SelfSaveInputPane.md`
  - Raise confidence to approximately `87` if the constructor/factory/source-route facts are added; keep completion near `86/87` unless raw send/factory C++ is also resolved.
  - State that `NexusTK/ui/dialogs/SelfSaveInputPane.cpp` can emit the constructor child as first-draft source now.
  - Keep the broader source grouping caveat: `CommandInputPanes.cpp` remains a plausible final original grouping, but current documentation/emitter route stays [UID:0000NM].
  - Add prompt id/text, matching factory construction, no direct start refs for constructor/factory/send helper, and no-code rejection for the constructor.
- `by-memory/0x005b67c0-0x005b68b0.SelfSaveInputPane.md`
  - Keep aggregate `RECONSTRUCTABLE:FALSE` and non-emitting.
  - Update stale coverage/doc wording if present: exact child [UID:0003O5] carries constructor C++; aggregate should not emit duplicate code.
  - Replace old "raw constructor blank" language with "constructor child source-ready; raw send/factory remain separate route caveats."
- `by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md`
  - Add that it duplicates the accepted constructor's source semantics after `0x108` allocation and EH setup.
  - Preserve no-direct-caller caveat and keep C++ blank unless a later pass resolves factory/open-helper liveness/name.
  - Suggested source-facing name remains `CreateSelfSaveInputPane` / `OpenSelfSaveInputPane` with medium confidence, not a class constructor.
- `by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md`
  - If touched, update blank-C++ wording to say remaining code-entry blockers are handler/helper source names and packet helper split, not constructor uncertainty.
  - Keep `OnConfirmInput` as the best source-facing name for the vtable slot, with `OnCharInput`/`OnConfirm` as naming-sweep alternates.
- `by-memory/0x005b6870-0x005b68b0.SelfSaveInputPaneSendSelfSavePacketRaw.md`
  - If touched, name it as a private `SelfSaveInputPane::SendSelfSavePacket`-style helper with no-direct-xref caveat.
  - Do not use its raw/no-xref state to block constructor C++.
- `by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md` and `by-type/by-vtable/SelfSaveInputPaneVtables.md`
  - State that the constructor child is now source-ready, but vtable data remains source-declared/generated-binary no-code.
  - Preserve primary slot `0x00630608 -> 0x005b6800` and secondary/tertiary adjustor no-code policy.
- `by-resource/str-res-localized-strings.md`
  - Add a high-value string-id mapping row or note: id `38` / `0x26` is `Save profile? (Y/N) ` and is consumed by `SelfSaveInputPane::SelfSaveInputPane`.
  - Do not imply this text is hard-coded in source; it belongs to the `STR.RES` resource.
- `by-global/g_pLanguageMan.md` and/or `by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md`
  - Optional: add SelfSave constructor as another representative prompt consumer of `g_pLanguageMan`.
- `by-class/CharInputPane.md` and `by-memory/0x004f28a0-0x004f2913.CharInputPaneConstructor.md`
  - Optional: add `SelfSaveInputPane` as a concrete consumer of `CharInputPane::CharInputPane(const wchar_t *promptText)` if not already captured by broad command-input consumer wording.

## Score And Metadata Rationale

- `COMPLETION:88`: the report resolves exact bytes, size, uniqueness, predecessor/successor boundaries, raw-route searches, prompt id and current resource text, base constructor signature, vtable view/object offsets, source name/signature, owner/emitter route, rejected alternatives, generated-name cleanup, and first-draft C++.
- `CONFIDENCE:90`: body semantics are exact and cross-confirmed by target bytes, factory duplicate construction, vtable docs, CharInputPane docs, LanguageMan docs, and resource payload extraction. Confidence remains below final-audit range because no direct caller/start pointer is known, IDA still lacks a function object, the factory/open-helper route remains no-xref, and exact original source-file grouping is still uncertain.
- Keep `CANONICAL_OWNER:0000CW`: class construction, vtable stores, and confirm-handler relationship are SelfSaveInputPane-owned.
- Keep `RECONSTRUCTABLE:TRUE`: this is source-authored project code, not padding or pure generated binary.
- Keep `EMITTER_UIDS:0000CW`: current class child emitter route reaches [UID:0000NM] `SelfSaveInputPane`.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` during this report-only pass.

The current coverage report has only the aggregate [UID:0001MU] row near `0x005b67c0` and is missing the exact constructor child row. Insert this row immediately after the current [UID:0001MU] aggregate row and before [UID:0001MW] `BlockListenInputPanes`:

```markdown
    - [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md) 0x005b67c0-0x005b6800 | raw constructor | SelfSaveInputPaneConstructorRaw : reconstructable : 88% : very strong : B005 source-quality pass keeps this as source-bearing `SelfSaveInputPane::SelfSaveInputPane()` under [UID:0000CW] with emitter route through [UID:0000NM]; local PE/Capstone scan over `NexusTK.exe` confirms exact `0x40` unique raw constructor bytes, predecessor `ret 4` with no leading padding, immediate successor [UID:0003O6] at `0x005b6800` with no trailing padding, no direct branch/call refs and no VA/RVA/raw pointer refs to the raw start, localization through `g_pLanguageMan` and `LanguageMan::GetLocalizedString(0x26)`, current `STR.RES` id `0x26` text `Save profile? (Y/N) `, `CharInputPane::CharInputPane(const wchar_t *)` base construction, primary/secondary/tertiary SelfSaveInputPane vptr stores at `+0/+0xa0/+0xa4` to `0x006305c0/0x00630610/0x00630640`, matching factory construction at `0x005aa140`, generated-name cleanup, no-code rejection for this constructor, and first-draft constructor C++ readiness while preserving the no-direct-caller/factory-source-route caveat.
```

Recommended optional replacement for the stale aggregate row if the supervisor syncs nearby coverage at the same time:

```markdown
    - [UID:0001MU][0x005b67c0-0x005b68b0.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b0.SelfSaveInputPane.md) 0x005b67c0-0x005b68b0 | class method island | SelfSaveInputPane : ignored : 88% : strong : Non-emitting SelfSaveInputPane method-island map; exact children carry source reconstruction, with [UID:0003O5] now source-ready for `SelfSaveInputPane::SelfSaveInputPane()` using STR.RES id `0x26` / `Save profile? (Y/N) `, [UID:0003O6] modeled confirm handler reachable from vtable slot `0x00630608`, [UID:0003O7] raw no-xref opcode `0x25` packet helper, exact `0x005b686c-0x005b6870` and `0x005b68b0-0x005b68c0` alignment, matching factory construction at `0x005aa140`, and successor boundary before BlockListen input panes.
```

## Validator Needs

No validators were run because this was a report-only assignment and no by-* docs were edited.

Expected validation commands after an implementation callback, from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0003O5-SelfSaveInputPaneConstructorRaw-source-quality-removed.md](0003O5-SelfSaveInputPaneConstructorRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run additional scoped validators for any optional support docs touched:

> Executable block R002 was removed from this report and preserved verbatim in [0003O5-SelfSaveInputPaneConstructorRaw-source-quality-removed.md](0003O5-SelfSaveInputPaneConstructorRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After implementation, inspect `auto-generated/NexusTK/ui/dialogs/SelfSaveInputPane.cpp` and confirm [UID:0003O5] emits the first-draft constructor instead of an empty marker.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits were made. Recommended future IDA cleanup:

- Create or mark a function at `0x005b67c0` if IDA still treats it as raw bytes after analyst review.
- Rename `0x005b67c0` to `SelfSaveInputPane_ctor` or `SelfSaveInputPane::SelfSaveInputPane`.
- Apply type `SelfSaveInputPane *__thiscall SelfSaveInputPane_ctor(SelfSaveInputPane *this)`.
- Name/comment `0x005b67c7`: load `g_pLanguageMan`.
- Name/comment `0x005b67cd`: `kSelfSavePromptStringId = 0x26` / current STR.RES text `Save profile? (Y/N) `.
- Ensure `0x004f0350` uses a localization type such as `const wchar_t *__thiscall LanguageMan::GetLocalizedString(LanguageMan *this, int stringId)`.
- Ensure `0x004f28a0` uses a base-constructor type such as `CharInputPane *__thiscall CharInputPane::CharInputPane(CharInputPane *this, const wchar_t *promptText)`.
- Comment vptr stores:
  - `0x005b67df`: primary `SelfSaveInputPane` vtable at object `+0x00`.
  - `0x005b67e7`: secondary view at object `+0xa0`.
  - `0x005b67f1`: tertiary view at object `+0xa4`.
- Rename `0x005b6800` to `SelfSaveInputPane_OnConfirmInput` / `SelfSaveInputPane::OnConfirmInput` in a future handler pass.
- Rename `0x005b6870` to `SelfSaveInputPane_SendSelfSavePacket` if the raw helper pass accepts that source placement.
- Rename `0x005aa140` to `CreateSelfSaveInputPane` or `OpenSelfSaveInputPane` with medium confidence; keep no-caller caveat in the comment.
- Add comments to the three vtable bases `0x006305c0`, `0x00630610`, and `0x00630640` that they are primary/secondary/tertiary `SelfSaveInputPane` views generated from the class declaration.

## Remaining Issues And Impact

- No direct branch/call or pointer route to `0x005b67c0` is known. Impact: confidence cap and raw/liveness caveat remain, but the constructor body is complete and source-ready.
- `0x005aa140` duplicates construction after allocation but also has no direct route. Impact: it should be researched separately before emitting factory/open-helper C++; it does not block constructor C++.
- Exact original file grouping is not fully proven. Impact: retain [UID:0000NM] route for current emitter and keep [UID:0000ID] `CommandInputPanes` as an alternate source-tree grouping note.
- Exact original localization helper name is unproven. Impact: use `g_pLanguageMan->GetLocalizedString(...)` or the current project-normalized equivalent, with address evidence retained.
- Exact original constant spelling for id `0x26` is unproven. Impact: `kSelfSavePromptStringId` is a descriptive placeholder until a localized-string-id enum pass occurs.
- [UID:0003O6] and [UID:0003O7] still have blank C++. Impact: this constructor can still emit; the class/file docs should say remaining work is handler/helper C++ and factory liveness, not constructor shape.

FINISHED `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/0003O5-SelfSaveInputPaneConstructorRaw-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003O5","source_path":"executed-b-agent-research/B005/0003O5-SelfSaveInputPaneConstructorRaw-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
