** TARGET-REPORT-UID:00018H **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00018H InterfaceEfxMgr TriggerInterfaceEffect Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: raise [UID:00018H] from `82/88` to `88/91`, keep `CANONICAL_OWNER:00006O`, keep `EMITTER_UIDS:00006O`, and populate formal reconstruction C++ for the exact method body.
- Final disposition: exact source-authored `InterfaceEfxMgr::TriggerInterfaceEffect(int effectId)` method. It should emit through [UID:00006O] `InterfaceEfxMgr` to [UID:0000K9] `NexusTK/ui/InterfaceEfx.cpp`.
- Required action: update the target page, refresh target/support wording for the `Shadow` config field and persistent effect member names, and replace the stale `by-memory/-coverage-report.md` rows listed below. No in-scope split is required.
- Confidence: high. The only remaining uncertainty is original spelling style for member names such as `shadowEnabled` and `m_characterEffect`; behavior, range, owner, emitter route, parameter semantics, resource mapping, and C++ shape are all directly supported.

## Supporting Research

## Target

- Target UID: [UID:00018H]
- Target path: `by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md`
- Current target state: `COMPLETION:82`, `CONFIDENCE:88`, `CANONICAL_OWNER:00006O`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006O`, blank `RECONSTRUCTION_CPP`.
- Source route: [UID:00006O] `InterfaceEfxMgr` -> [UID:0000K9] `InterfaceEfx` -> `auto-generated/NexusTK/ui/InterfaceEfx.cpp`.
- Supervisor assignment: `B003-goal2-interface-efxmgr-trigger-source-quality-00018H-20260617`.

## Executive Recommendation

[UID:00018H] can safely clear the active code gate. The method is an exact modeled body at `0x004e9ee0-0x004e9f2d`, has one direct caller from legacy `GeneralPurposePanel::SwitchActiveTab`, calls only `InterfaceEfx::Play`, and routes through an already-valid emitter path. Its source-facing shape is:

- `void InterfaceEfxMgr::TriggerInterfaceEffect(int effectId)`
- `effectId` is the legacy general-purpose-panel active tab id/effect id, not an arbitrary resource id.
- `0` and `1` play the persistent character interface effect (`CHREFX.EPD`, `+0xf8`).
- `2` plays the persistent item interface effect (`ITEMEFX.EPD`, `+0x100`).
- `3` plays the persistent magic interface effect (`MAGEFX.EPD`, `+0xfc`).
- The gate at `g_pConfig +0x28de5e` should be documented as the registry/UI `Shadow` graphics option, with descriptive field name `shadowEnabled` or `showShadow`; `shadowEnabled` is recommended for the first draft.

The target should not be left below 85. Every prior blocker in scope now has either a defensible resolution or a narrow non-blocking caveat.

## Supervisor Active Recheck

- This remains report-only B-agent work. I did not edit by-* docs, generated reports, generated source, IDA DB, source files, or `by-memory/-coverage-report.md`.
- Split-first review: no split/child page is required. `0x004e9ee0-0x004e9f2d` is a single exact IDA function. `0x004e9f2d-0x004e9f30` is alignment NOP data and `0x004e9f30-0x004e9f40` is compiler switch table data for the function, not a separate source-owned child.
- Open-question closure: the target's current caveats about field names, source split, generated output omission, caller semantics, and config flag naming are resolvable enough for `88/91` and formal C++ entry. They should not remain as target-blocking open questions.

## Inference Research Guidance Check

I treated existing docs as leads, not authority. IDA MCP confirms the function boundary, caller/callee set, constructor resource mapping, switch-table layout, and config-field consumers. Documentation evidence then adds child-index names, resource-family context, and source-tree route. Inference is limited to source-facing descriptive names where original spelling is not present in type data.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Candidates and rejected alternatives | Best defensible conclusion and impact |
| --- | --- | --- | --- |
| Method name and signature | IDA decompile shows `int __thiscall sub_4E9EE0(_DWORD *this, int a2)`, but all paths are side-effect-only and the sole caller ignores the return. Existing docs and class/file pages already use `TriggerInterfaceEffect`. | Rejected `int` return because any `eax` value is incidental from global load or callee return. Rejected `GeneralPurposePanel` ownership because the panel is only the caller. `PlayInterfaceEffect` is plausible but weaker than the established method name. | Use `void InterfaceEfxMgr::TriggerInterfaceEffect(int effectId)`. This closes the source-facing signature blocker and permits C++ entry. |
| Input id semantics | Decompile of `0x004b8650` shows the legacy branch stores the requested active child index and calls `0x004e9ee0(this[8])`. GeneralPurposePanel docs map indexes `0` self-look, `1` user/profile, `2` inventory, `3` spell inventory. | Rejected "arbitrary resource id" because there is one direct caller and it passes the active tab index. Rejected packet opcode semantics because packet paths call the panel switcher, not this helper directly. | Parameter is a legacy side-panel tab/effect id. Cases `0/1` are character/self-user look, `2` inventory item, `3` spell/magic. This resolves the effect-id blocker. |
| `g_pConfig +0x28de5e` field name | Direct code hits include target `0x004e9ee8`, frame spawner `0x004e9ffe`, MapPane render refresh hits around `0x00509579/0x005095b0`, option/update helpers, and ScreenPanePaletteState reset. `get_bytes 0x00617580` decodes UTF-16 strings including `Shadow`, `Balloon`, `GraphicsSetting`, and `MapEffect`; `xrefs_to 0x0061758c` reports save/load/UI option refs at `0x491e56`, `0x492e76`, and `0x541426`. `0x00541040` writes `+0x28de58`, `+0x28de5e`, and `+0x28de5c` for low/high display mode sync. | Rejected target-local `interfaceEffectsEnabled`; too narrow because MapPane, ScreenPanePaletteState, registry save/load, and option UI use the same byte. Rejected pure `displayMode` for `+0x28de5e`; `Shadow` is the persisted/UI label and `GraphicsSetting` is a neighboring distinct registry string. Rejected `MapEffect`; it is a separate string at `0x00617680`. | Document `+0x28de5e` as the `Shadow` graphics option byte. Recommended descriptive field name: `shadowEnabled` with accepted alias `showShadow` if Config docs later standardize `Show*` naming. For this target, the field gates interface-effect playback as one consumer of the broader shadow/display-effects option. |
| Persistent effect member names and order | `0x004e9d00` constructor allocates three `InterfaceEfx` objects and stores `CHREFX.EPD` at `+0xf8`, `MAGEFX.EPD` at `+0xfc`, and `ITEMEFX.EPD` at `+0x100`. Destructor releases the same slots. Target switch loads `+0xf8`, `+0x100`, and `+0xfc` for ids `0/1`, `2`, and `3`. | Rejected leaving `this[62]`, `this[63]`, `this[64]` as unresolved because constructor strings directly identify roles. Rejected swapping item/magic by construction order because the switch explicitly maps id `2` to `+0x100` and id `3` to `+0xfc`. | Use `m_characterEffect`, `m_magicEffect`, and `m_itemEffect` as descriptive source member names. Original spelling is not proved, but behavior/slot roles are strong enough for final C++. |
| Resource-to-member mapping | Resource docs and IDA xrefs confirm `CHREFX.EPD`, `MAGEFX.EPD`, `ITEMEFX.EPD`, `FRMLEFX.EPD`, `FRMREFX.EPD`, and shared `INTEFX.PAD`. | Rejected folding manager-trigger resources into InventoryPane/SpellInventoryPane ownership; those are separate consumers of shared interface-effect resources. Rejected treating frame resources as target cases; they are used by `0x004e9f40`, not this method. | Target only dispatches persistent character/item/magic members. Frame resources remain in the manager spawner documentation. |
| Switch table and range handling | `lookup_funcs` reports `sub_4E9EE0` size `0x4d`, ending at `0x004e9f2d`; no function starts at `0x004e9f2d` or `0x004e9f30`; next function starts at `0x004e9f40`. Existing target docs identify `0x004e9f2d-0x004e9f30` as NOP alignment and `0x004e9f30-0x004e9f40` as a four-entry jump table. | Rejected child split for `0x004e9f30`; it is compiler-generated switch data with no independent owner/emitter. Rejected extending the function range through the table because IDA's modeled body and half-open source range end at `0x004e9f2d`. | Keep the current target range. Document the switch table as compiler-emitted data belonging to this function's implementation, not a source child. |
| Generated-output omission | `auto-generated/-ag-memory-coverage.md` routes [UID:00018H] to `auto-generated/NexusTK/ui/InterfaceEfx.cpp`, but that generated file currently contains only a placeholder because formal C++ is blank. | Rejected "dead emitter route" because the coverage route is valid through [UID:00006O] and [UID:0000K9]. Rejected using generated source as authority because it omits the IDA-confirmed body. | Omission is a documentation/C++ population gap, not a range or ownership blocker. First-draft C++ should be populated in the target. |
| Source placement | Function address cluster sits inside `InterfaceEfxMgr` between constructor and frame spawner. Class/file docs route the manager through [UID:0000K9] `InterfaceEfx` under `NexusTK/ui/`. Vtable/resource string docs support the same file. | Rejected `GeneralPurposePanel.cpp`; it is the caller source only. Rejected `OptionPane.cpp`/`Config.cpp`; they write or label the config byte but do not own manager playback. Rejected `Effects.cpp`; these are UI/interface effect wrappers, not map/screen overlay effecters. A later `InterfaceEfxMgr.cpp` split is possible but not required by current source tree. | Keep [UID:00006O] owner/emitter and [UID:0000K9] source file route. Source split uncertainty is non-blocking for this exact child. |
| Aggregate versus exact-child emission | [UID:00018G] is a class-method aggregate with blank C++; [UID:00018H] is the exact source method. | Rejected putting the target body into [UID:00018G], which would duplicate child code and blur method ownership. Rejected leaving [UID:00018H] blank now that it clears the code gate. | Emit first-draft C++ on [UID:00018H]. Keep [UID:00018G] as a route/index/summary page unless separately audited for aggregate C++. |

Remaining uncertainty: local UDT records do not prove original member spelling, and no original file proves whether the manager was split into a separate `InterfaceEfxMgr.cpp`. These uncertainties cap the target below final-audit scores, but they do not cap it below 85 completion or block formal first-draft C++ because all executable behavior and source placement needed by this method are resolved.

## Evidence Standards Used

- IDA MCP: `lookup_funcs`, `analyze_function`, `decompile`, `xrefs_to`, direct byte reads, and code-hit searches for `0x28de5e`.
- Documentation evidence: target page, `InterfaceEfxMgr`, `InterfaceEfx`, `InterfaceEfxAndMgr`, `GeneralPurposePanel`, `GeneralPurposePanel::SwitchActiveTab`, `g_pConfig`, registry save/load, option helper, resource-family docs, generated coverage, and current generated source placeholder.
- Negative evidence: no local UDT records proving exact member spellings; no direct evidence that `0x004e9f30` is independent source; no source-route dead end; no prior executed B report for this UID except the read-only-data anchor report.

## IDA MCP Facts

- `lookup_funcs 0x004e9ee0`: `sub_4E9EE0`, size `0x4d`, exact half-open range `0x004e9ee0-0x004e9f2d`.
- `lookup_funcs 0x004e9f30`: no function; target switch table data begins at `0x004e9f30`.
- `lookup_funcs 0x004e9f40`: next modeled function `sub_4E9F40`, manager frame spawner.
- `analyze_function 0x004e9ee0`: tests `byte ptr [g_pConfig+0x28de5e]`, switches on the argument, and calls `sub_4E9950` on manager slots `+0xf8`, `+0x100`, and `+0xfc`.
- `decompile 0x004e9d00`: constructor stores `CHREFX.EPD` at `+0xf8`, `MAGEFX.EPD` at `+0xfc`, and `ITEMEFX.EPD` at `+0x100`.
- `decompile 0x004b8650`: legacy tab-switch branch calls `sub_4E9EE0(this[8])`, where `this[8]` is the active child index.
- `get_bytes 0x00617580`: decoded UTF-16 option strings around `Shadow`, `Balloon`, `GraphicsSetting`, and `MapEffect`; `Shadow` starts at `0x0061758c`.
- `xrefs_to 0x0061758c`: refs from registry save `0x00491b30`, registry load `0x004926a0`, and option UI setup `0x00541240`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004e9ee0-0x004e9f2d` | [UID:00018H] target | Exact `InterfaceEfxMgr::TriggerInterfaceEffect` body | TRUE | [UID:00006O] | Recommend `88/91` | Emit formal C++ |
| `0x004e9f2d-0x004e9f30` | ignored/padding in surrounding coverage | NOP alignment after target body | no | none | unchanged | No split |
| `0x004e9f30-0x004e9f40` | compiler data adjacent to target | Switch jump table for ids `0..3` | no independent source item | target implementation artifact | unchanged | No child page |
| `0x004e97b0-0x004ea121` | [UID:00018G] aggregate | InterfaceEfx/InterfaceEfxMgr method cluster | TRUE | [UID:0000K9] | existing page `85/89`; coverage row stale at `84` | Keep blank aggregate C++; update coverage row only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004b880b` | caller inside [UID:00015X] `GeneralPurposePanel::SwitchActiveTab` | Sole direct call, legacy side-panel branch passes active tab id. |
| `0x004e9f06` | call `0x004e9950` | `m_characterEffect->Play()` for ids `0` and `1`. |
| `0x004e9f15` | call `0x004e9950` | `m_itemEffect->Play()` for id `2`. |
| `0x004e9f24` | call `0x004e9950` | `m_magicEffect->Play()` for id `3`. |
| `0x004e9ee8` | read `g_pConfig +0x28de5e` | `Shadow` graphics option gate for direct trigger helper. |
| `0x004e9ffe` | read `g_pConfig +0x28de5e` | Same gate for periodic frame-effect spawner. |

## Documentation Evidence And IDA Status

- Target [UID:00018H] already has correct exact range, owner, caller/callee set, dispatch table, switch-table placement, and resource mapping as raw facts.
- Target wording is stale where it calls `+0x28de5e` an `interface-effect option byte` and leaves final field names/source split as blockers. Current evidence supports `Shadow` graphics option naming and descriptive persistent-effect member names.
- [UID:00006O] `InterfaceEfxMgr` already meets the gate and should keep ownership. Its state table should be tightened with `m_characterEffect`, `m_magicEffect`, `m_itemEffect`, and `shadowEnabled` wording.
- [UID:0000K9] `InterfaceEfx` remains the best file route. A separate `InterfaceEfxMgr.cpp` can remain an optional future source organization note, but it should not block this exact method.
- `auto-generated/NexusTK/ui/InterfaceEfx.cpp` currently contains only `// Documentation placeholder for proposed reconstruction path.` This confirms a generated-output omission, not contradictory source.
- Executed B-report search found no prior report for [UID:00018H]. The only executed B hit was `Agent-B001/research/executed/older/00025K-InterfaceEfxReadOnlyData-advanced-scan.md`, which only confirms related code anchors including `0x004e9ee0` size `0x4d`.

## Ranked Ownership Analysis

### 1. [UID:00006O] InterfaceEfxMgr

- Evidence for: target lies inside the manager method island; constructor initializes the three effect members used here; destructor releases them; class docs already attach manager to [UID:0000K9]; caller reads `g_pInterfaceEfxMgr` before invoking the helper.
- Evidence against: no local UDT records prove exact field names. This affects spelling only, not ownership.
- Decision: keep as direct owner and emitter.

### 2. [UID:0000K9] InterfaceEfx file

- Evidence for: proposed source tree places the UI/interface effect class and manager under `NexusTK/ui/InterfaceEfx.cpp`; resource strings, vtables, singleton, constructor/spawner/destructor, and generated route all point here.
- Evidence against: original source might have used a separate `InterfaceEfxMgr.cpp`. No current docs or source tree require that split.
- Decision: keep current source route. Optional later file split is not a target blocker.

### 3. [UID:0000JQ] GeneralPurposePanel

- Evidence for: sole direct caller at `0x004b880b` passes the active child index.
- Evidence against: no writes to manager state or resources; panel owns tab switching, not effect playback.
- Decision: caller context only; rejected as owner/emitter.

### 4. Config / OptionPane / RegistryConfig

- Evidence for: these docs label, load, save, and update the `Shadow` config byte.
- Evidence against: they do not own the manager effect objects or trigger dispatch.
- Decision: support context only. Update wording for the shared field, but do not change target ownership.

### 5. Effects / EffectObj systems

- Evidence for: adjacent conceptual effect infrastructure.
- Evidence against: this code owns UI pane/interface art resources (`CHREFX.EPD`, `MAGEFX.EPD`, `ITEMEFX.EPD`), not map/screen overlay effecters.
- Decision: rejected.

## Negative Evidence Summary

- `search_structs InterfaceEfxMgr` and `search_structs InterfaceEfx` did not recover local UDT member names. This prevents final-audit original spelling, but constructor/resource evidence supplies strong descriptive names.
- No IDA function object or caller points to `0x004e9f30` as an independent entry. It is switch table data and should not be split.
- No direct evidence proves a separate original `InterfaceEfxMgr.cpp`; current file route is valid and should remain active.
- No direct caller other than `GeneralPurposePanel::SwitchActiveTab` was found. This narrows parameter semantics instead of blocking them.

## First-Draft C++ Recommendation

Formal C++ should be populated for [UID:00018H]. The active gate is satisfied: `RECONSTRUCTABLE:TRUE`, nonblank emitter route through [UID:00006O] to [UID:0000K9], and recommended score average `(88 + 91) / 2 = 89.5`.

Recommended formal body:

```cpp
void InterfaceEfxMgr::TriggerInterfaceEffect(int effectId)
{
    if (!g_pConfig->shadowEnabled)
        return;

    switch (effectId) {
    case 0:
    case 1:
        m_characterEffect->Play();
        break;

    case 2:
        m_itemEffect->Play();
        break;

    case 3:
        m_magicEffect->Play();
        break;

    default:
        break;
    }
}
```

Safety notes:

- Do not add null checks for `g_pConfig` or member pointers; the binary does not check them and startup guarantees these objects before legacy tab dispatch.
- If the Config layout standardizes the field as `showShadow` instead of `shadowEnabled`, only that field spelling should change.
- If the manager member naming standardizes without `m_`, only member spelling should change. The member/resource mapping must stay `character +0xf8`, `magic +0xfc`, `item +0x100`.

## Supervisor-Owned Target Doc Edits

Recommended metadata for [UID:00018H]:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006O | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006O | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the target's current `Function Summary` paragraph with:

```markdown
`0x004e9ee0` is `InterfaceEfxMgr::TriggerInterfaceEffect(int effectId)`, the old-layout interface-effect trigger used by [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md). The only direct caller passes the legacy general-purpose-panel active child index as `effectId`: ids `0` and `1` are self/user-look character effects, id `2` is the inventory/item effect, and id `3` is the spell-inventory/magic effect. The method checks the `Shadow` graphics option byte at [UID:00028Q][g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md) offset `0x28de5e` (`shadowEnabled` / `showShadow` descriptive field name); when enabled, it calls `InterfaceEfx::Play` on the selected persistent effect member.
```

Replace the target's `Dispatch Table` with:

```markdown
| Input id | Source-facing role | Effect member | Resource created by constructor |
| --- | --- | --- | --- |
| `0` | legacy self-look / character effect | `m_characterEffect` at `this +0xf8` | `CHREFX.EPD` |
| `1` | legacy user-look/profile / character effect | `m_characterEffect` at `this +0xf8` | `CHREFX.EPD` |
| `2` | legacy inventory / item effect | `m_itemEffect` at `this +0x100` | `ITEMEFX.EPD` |
| `3` | legacy spell inventory / magic effect | `m_magicEffect` at `this +0xfc` | `MAGEFX.EPD` |
```

Replace the target's `Touched State` row for `g_pConfig +0x28de5e` with:

```markdown
| [UID:00028Q][g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md) + `0x28de5e` | `Shadow` graphics option byte (`shadowEnabled` / `showShadow` descriptive name). Zero suppresses direct interface-effect triggering and periodic frame-effect playback. |
```

Replace the target's `Data Caveats` section with:

```markdown
## Source-Quality Notes

- The active generated `InterfaceEfx.cpp` currently contains only a placeholder because this target's formal C++ block is blank, not because the emitter route is invalid.
- `m_characterEffect`, `m_magicEffect`, `m_itemEffect`, and `shadowEnabled` are descriptive source-quality names inferred from constructor resource strings, destructor slot cleanup, registry/option `Shadow` labeling, and caller behavior. Original spelling is not proved by UDT metadata, but the roles are strong enough for first-draft C++.
- `0x004e9f30-0x004e9f40` is compiler switch-table data for this method and should not become a separate source-emitting child.
- A later `InterfaceEfxMgr.cpp` file split remains possible, but the current accepted route through `NexusTK/ui/InterfaceEfx.cpp` is valid and should not block this exact method.
```

Add this score rationale to the target:

```markdown
## Score Rationale

Completion is `88` because the exact function range, caller/callee set, disabled/default paths, effect-id semantics, persistent member/resource mapping, `Shadow` config gate, switch-table treatment, source route, generated-output omission, and first-draft C++ shape are all documented. Confidence is `91` because IDA directly supports the behavior and range, and support docs confirm the caller index map and resource family. Confidence stays below final-audit quality only because original member/field spelling and the one-file versus separate-manager source split are inferred rather than source-proved.
```

## Support Docs To Update

Recommended support updates, no score change required unless the supervisor wants to rescore support docs after applying wording:

- [UID:00006O] `InterfaceEfxMgr`: replace generic `InterfaceEfxMgr +0xf8/+0xfc/+0x100` wording with `m_characterEffect`, `m_magicEffect`, and `m_itemEffect`; replace `client option byte` with `Shadow graphics option byte at g_pConfig +0x28de5e`.
- [UID:0000K9] `InterfaceEfx`: state that `InterfaceEfx.cpp` remains the active route for the manager; `InterfaceEfxMgr.cpp` is an optional later source organization, not a blocker for [UID:00018H].
- [UID:00028Q] `g_pConfig`: add known field cluster `+0x28de58/+0x28de5c/+0x28de5e` for low/high graphics/display option mirrors and specifically note `+0x28de5e` has registry/UI label `Shadow` and gates MapPane render refresh, ScreenPanePaletteState palette bank selection, and InterfaceEfx playback/spawn.
- [UID:0003NS] `SendLowHighDisplayModeOption`: refine the `+0x28de5e` row from `Mirrored display-mode byte` to `Shadow/display-effects mirror byte written by the low/high display helper; registry/UI label is Shadow`.
- [UID:0001RE] `interface-efx-resources`: update the persistent trigger naming caveat to note this pass validates the current tab/effect mapping for [UID:00018H]: `0/1` character, `2` item, `3` magic. Resource-payload provenance questions remain separate and do not block the method body.
- [UID:00015X] `GeneralPurposePanelSwitchActiveTab`: add that the legacy branch passes the active child index directly as `InterfaceEfxMgr::TriggerInterfaceEffect(effectId)`.
- [UID:0002AZ] `MapPaneRenderScratchFlag`: replace unresolved `config-field name` wording with `shadowEnabled/showShadow` as the best current descriptive name for `g_pConfig +0x28de5e`; keep its own final global symbol name unresolved if desired.

## Exact by-memory/-coverage-report.md Rows

Placement context: replace the existing [UID:00018G] and [UID:00018H] rows in `by-memory/-coverage-report.md` in the `0x004e97b0-0x004ea121` InterfaceEfxAndMgr block, between the `0x004e97a3-0x004e97b0` padding row and [UID:00018I].

Replacement [UID:00018G] support sync row:

```markdown
    - [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md) 0x004e97b0-0x004ea121 | class-method-cluster | InterfaceEfxAndMgr : reconstructable : 85% : strong : Live IDA confirms InterfaceEfx/InterfaceEfxMgr aggregate parent attachment to InterfaceEfx.cpp, exact local function inventory through scalar destructor, constructor/play/render/tick behavior, manager singleton/resource lifecycle, trigger/spawner/helper child links, vtable xrefs, `g_pInterfaceEfxMgr` and config option gates, and blank aggregate C++ because exact child methods such as [UID:00018H] emit their own bodies; final inherited field/base names and optional manager source split remain below final-audit quality.
```

Replacement [UID:00018H] target row:

```markdown
    - [UID:00018H][0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect](by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md) 0x004e9ee0-0x004e9f2d | method | InterfaceEfxMgr::TriggerInterfaceEffect : reconstructable : 88% : very-strong : B003 2026-06-17 source-quality reanalysis validates the exact 0x4d body, active InterfaceEfx.cpp emitter route, source-facing `void TriggerInterfaceEffect(int effectId)` signature, sole legacy `GeneralPurposePanel::SwitchActiveTab` caller at 0x004b880b, tab/effect id semantics 0/1 self-user character, 2 inventory item, 3 spell inventory magic, `g_pConfig +0x28de5e` Shadow graphics option gate, switch table at 0x004e9f30-0x004e9f40, persistent member mapping +0xf8 character/CHREFX.EPD, +0xfc magic/MAGEFX.EPD, +0x100 item/ITEMEFX.EPD, `InterfaceEfx::Play` dependency, generated-output omission cause, and formal C++ readiness.
```

No [UID:00018I] row change is recommended by this task. The existing [UID:00025K] read-only-data row remains stale from earlier work, but it is not owned by this target report.

## Validation Commands

Recommended supervisor/A-agent validation after applying target and support-doc changes:

> Executable block R001 was removed from this report and preserved verbatim in [00018H-interface-efxmgr-trigger-interface-effect-source-quality-removed.md](00018H-interface-efxmgr-trigger-interface-effect-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Commands actually run by B003 for this report: read-only `Get-Content`, `rg`, `Select-String`, and IDA MCP `lookup/decompile/xrefs/get_bytes` checks. No by-* validators were run because this was report-only and no by-* docs were modified.

## Final Recommendation

Apply the [UID:00018H] target update, populate the formal C++ block, keep owner/emitter unchanged, and synchronize the coverage row. This target should no longer remain below the 85/85 gate. The only retained caveat should be original spelling style for inferred names, not behavior, ownership, source placement, or C++ readiness.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/00018H-interface-efxmgr-trigger-interface-effect-source-quality.md`
- Modified: none outside Agent-B003 research.
- Leases used: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00018H-interface-efxmgr-trigger-interface-effect-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:26","uid":"00018H"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00018H-interface-efxmgr-trigger-interface-effect-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/00018H-interface-efxmgr-trigger-interface-effect-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00018H"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
