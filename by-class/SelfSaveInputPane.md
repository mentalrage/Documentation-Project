*** UID:0000CW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SelfSaveInputPane : public CharInputPane
{
public:
    SelfSaveInputPane();

protected:
    virtual void OnConfirmInput();

    static const int kSelfSavePromptStringId = 0x26;

private:
    void SendSelfSavePacket();
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SelfSaveInputPane

## Status

- Confidence: very strong for class behavior, hierarchy/layout, vtable identity, active handler, constructor/helper/factory source shape, and compiler-wrapper disposition; strong for the immediate file route, with historical grouping still inferential.
- Immediate source file: [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md), generating `NexusTK/ui/dialogs/SelfSaveInputPane.cpp`. [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) remains only a coordinated future grouping candidate, not the current destination.
- Vtable page: [UID:0003HM][SelfSaveInputPaneVtables](by-type/by-vtable/SelfSaveInputPaneVtables.md), split from aggregate [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- Historical recovered artifact: `source-3/simroot_v2/class_SelfSaveInputPane.cpp`; it is evidence only and does not override current ordinary pages or generated output.
- Historical Wave3 artifact: grade `97.5` with two modeled methods. This is not current source-quality or lifecycle state.
- Historical B007 2026-06-19 source-quality status selected file-static `SendSelfSavePacket()` from no `this` usage and no ordinary route. B004's current source-family ABI and normalized-clone analysis supersedes that declaration with private nonvirtual `void SendSelfSavePacket()`; the no-route fact remains unchanged.
- B005 2026-06-21 constructor status: [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md) is now source-ready as `SelfSaveInputPane::SelfSaveInputPane()`, using `kSelfSavePromptStringId = 0x26`; current `STR.RES` id `0x26` text is `Save profile? (Y/N) `. The raw-start/no-direct-caller caveat remains, but it no longer blocks first-draft constructor C++.
- B012 2026-06-19 factory status: [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md) is a related file-level retained factory helper, not a class method. Best source-facing form is `CreateSelfSaveInputPane()` returning `new SelfSaveInputPane`; no ordinary route to `0x005aa140` is known.

## Class Purpose

`SelfSaveInputPane` is a [UID:00001P][CharInputPane](by-class/CharInputPane.md) derivative for self-save confirmation. Its constructor looks up localized prompt id `0x26` through [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), which currently resolves to `Save profile? (Y/N) `, and passes the resulting `const wchar_t *` to `CharInputPane::CharInputPane`. The active handler then requires a single-character answer and sends opcode `0x25` only when the user enters `y` or `Y`.

Human source has one call from vtable-routed [UID:0003O6][0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md) to private nonvirtual [UID:0003O7][0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md). The optimized binary inlines the exact helper send core into the active handler while retaining the out-of-line definition. The helper reads no input or object field and has no ordinary rel32/pointer route; those are binary/liveness facts, not proof of file scope.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SelfSaveInputPane::SelfSaveInputPane()` | `0x005b67c0-0x005b67ff` | Raw constructor-shaped body that reads `g_pLanguageMan`, calls `LanguageMan::GetLocalizedString(0x26)`, passes the returned prompt to `CharInputPane::CharInputPane(const wchar_t *)`, returns `this`, and installs three compiler-emitted `SelfSaveInputPane` vptrs. IDA currently does not model this start as a function, but B005's PE/Capstone pass proves a unique complete constructor body and first-draft C++ readiness. |
| `OnConfirmInput` | `0x005b6800-0x005b686b` | Active vtable-routed handler. Human source checks input length, reads one UTF-16 character, accepts only `y`/`Y`, then calls `SendSelfSavePacket()`. Exact release bytes inline the helper's opcode `0x25`, byte-one clear, and one-byte Socket send core. |
| `SendSelfSavePacket` | `0x005b6870-0x005b68b0` inclusive body, half-open page [UID:0003O7][0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md) | Private nonvirtual member definition retained after its source call was inlined. It writes opcode `0x25`, preserves explicit `packet[1]=0`, and calls `g_packetSender->QueueAndSendPacket(packet, 1)`. Exact frame/base/cookie is `0x14/-0x14/-4`; inferred `unsigned char packet[16]` is highest probability, with `[2]` plus exact-toolchain padding retained as the bounded runner-up. |
| `CreateSelfSaveInputPane` related factory helper | `0x005aa140-0x005aa1bf` | File-level helper that allocates 264 bytes, looks up localized string id `0x26`, constructs the `CharInputPane`/`SelfSaveInputPane` layout inline, installs the same three vtables, and still has no direct caller route. This is source-authored retained factory code under [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md), not a class instance method and not compiler glue. |

## Evidence Notes

- 2026-05-25 IDA MCP recheck confirms the same boundary shape: raw constructor at `0x005b67c0`, real handler at `0x005b6800`, raw send helper at `0x005b6870`, and real factory at `0x005aa140`.
- 2026-05-26 IDA MCP recheck reports the same shape: `0x005b67c0` and `0x005b6870` are still not IDA functions, `0x005b6800` is still size `0x6c`, and `0x005aa140` is still size `0x80`.
- IDA confirms `0x005b6800` as a real function and shows a vtable data reference from `0x00630608`.
- IDA MCP confirms three `SelfSaveInputPane` vtable views at `0x006305c0`, `0x00630610`, and `0x00630640`, with stores in both the factory/open helper at `0x005aa140` and raw constructor-shaped bytes at `0x005b67c0`.
- IDA reports `0x005b67c0` as "Not a function", but disassembly is constructor-shaped and matches the generated source.
- IDA vtable xrefs show a separate factory at `0x005aa140` installing the same `SelfSaveInputPane` vtables inline.
- The adjacent raw helper at `0x005b6870` sends the same opcode `0x25` without checking input. B007's file-static conclusion is retained historically; B004 resolves private nonvirtual membership from Wield's explicit object-call setup, the Wear parallel, exact normalized active/target identity, source order, and expected absence from the vtable. Generic sender, SelfSaveOKPane, compiler-only, padding, class-static, and virtual alternatives remain rejected.
- Sender storage is the shared [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / `dword_67A7EC`, not a SelfSave-specific global.
- Current `simroot_v2/class_SelfSaveInputPane.cpp` still omits the `0x005b6870` raw helper and the `0x005aa140` factory/open helper.
- 2026-06-02 IDA MCP recheck keeps `0x005b67c0` and `0x005b6870` as non-modeled raw starts, confirms `0x005b6800-0x005b686c` as `sub_5B6800`, confirms `0x005aa140-0x005aa1c0` as `sub_5AA140`, and reconfirms no direct callers for the constructor/factory/helper addresses.
- 2026-06-02 IDA MCP raw bytes show constructor-shaped code from `0x005b67c0`, the modeled handler from `0x005b6800`, and the raw send helper from `0x005b6870`; B007's 2026-06-19 PE recheck corrects the written boundary by proving `0x005b68b0` is the helper `ret` and alignment starts at `0x005b68b1`.
- B007's whole-image PE scan found no rel32 call/jump/conditional branch, no absolute VA/RVA/raw-offset pointer, and no target-range pointer to `0x005b6870-0x005b68b1`. Positive controls did find the [UID:0003O6][0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md) vtable pointer at `0x00630608` and the high-fanout `g_packetSender` references, so the negative route result is meaningful.
- B005's constructor PE/Capstone pass found the exact `0x40` constructor bytes at `0x005b67c0-0x005b6800` exactly once, with predecessor `ret 4`, immediate successor [UID:0003O6][0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md), no rel32/short branch or VA/RVA/raw pointer route to `0x005b67c0`, and matching vtable-base literal hits only at this constructor and the [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md).
- The constructor's current localized prompt is resource-owned text: `STR.RES` id `38` / `0x26` is `Save profile? (Y/N) `, including the trailing space. Source should use `kSelfSavePromptStringId = 0x26` or a later project-wide string-id enum name, not hard-code the English text.
- The vptr writes at `+0`, `+0xa0`, and `+0xa4` are compiler output from the class declaration. They prove the primary/secondary/tertiary vtable layout but should not be emitted as handwritten source statements.
- Generated names `ctor_0x5b67c0`, `FUN_005b67c0`, `sub_5B67C0`, control-character `SelfSaveInputPane\r`, raw vftable labels, and documentation filename labels are rejected as source-facing names. Use `SelfSaveInputPane::SelfSaveInputPane()`, `SelfSaveInputPane::OnConfirmInput`, and private `SelfSaveInputPane::SendSelfSavePacket()`.
- B012's factory reanalysis rejects making the `0x005aa140` helper a class member at this stage. It has no `this` input, no vtable slot, no class-static proof, and no caller route; keep it as related file-level `CreateSelfSaveInputPane()` source under [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md). The helper's allocation/base-constructor/vtable sequence corroborates the class layout but should not be represented in the class declaration.

## Source Placement And C++ Notes

This class page carries the accepted declaration with constructor, new virtual confirmation handler, prompt constant, private nonvirtual `SendSelfSavePacket`, and child emission. Method bodies remain on exact child pages. Constructor UID0003O5, active handler UID0003O6, and retained member definition UID0003O7 are source-ready; exact route distinctions remain documented without forcing binary callgraph shape into human source.

Keep current source-file route [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md). [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) remains a plausible final source grouping for the whole command-input family, but a move must be coordinated for the file, class, factory, constructor, handler, helper, vtable data, and vtable type pages. Do not move only one child to `CommandInputPanes.cpp`. [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md) now carries first-draft `CreateSelfSaveInputPane()` C++ as a file-level helper; this class declaration should not duplicate it.

Rejected direct owners for this constructor/class fact are [UID:0000K7][InputPanes](by-file/InputPanes.md), [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md), [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), [UID:0000CX][SelfSaveOKPane](by-class/SelfSaveOKPane.md), `MapPane`, `LanguageMan`, and [UID:0000Q5][g_packetSender](by-global/g_packetSender.md). Those pages are base infrastructure, successor context, feature-adjacent panes, resource/sender providers, or broader grouping candidates, not the direct class owner.

## Batch 023 Vtable Parent Evidence

Live IDA MCP on 2026-06-07 rechecked `NexusTK.exe` (`sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`) for the exact vtable-data child [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md):

- The three vtable bases remain `0x006305c0`, `0x00630610`, and `0x00630640`, named as the primary, secondary, and tertiary `SelfSaveInputPane` views.
- Key class-owned slot `0x00630608 -> 0x005b6800` still points at the modeled confirmation handler.
- Store xrefs remain the factory/open-helper writes at `0x005aa196/0x005aa19c/0x005aa1a6`, plus raw constructor-shaped stores at `0x005b67df/0x005b67e7/0x005b67f1`.
- Boundary dwords at `0x0063060c` and `0x0063063c` are the secondary and tertiary RTTI locators; the exclusive end remains `0x00630648` before `BlockListenInputPane`.

This class page is the direct source-level owner for the vtable-data child because the child is a compiler-emitted artifact of this class declaration and virtual method set. The retained helper remains no-route but source-authored as a private nonvirtual member; the active source calls it while exact release bytes inline it. UID0002N8/UID0003HM emit only compiler-generated disposition markers. Historical file grouping remains a confidence cap, not a C++ blocker.

## Historical 2026-07-13 B002 UID0002N8 Class And Emission Callback

This subsection preserves B002's exact hierarchy/layout/vtable work. Its file-static/no-call helper statements are evidence-time source conclusions superseded by the B004 member/inlining reconciliation below.

Current live RTTI independently proves direct inheritance `SelfSaveInputPane -> CharInputPane -> LineInputPane -> Pane`, the GrafPort/LObject primary chain, EventHandler at object offset `+0xa0`, and TimerHandler at `+0xa4`. The three complete-object locators share SelfSave type descriptor `0x0067a240` and CHD `0x00653830`; their object offsets are `0`, `0xa0`, and `0xa4`.

Factory allocation is `0x108`, and the raw constructor/factory writes after base construction are only the three compiler vptr stores at `+0`, `+0xa0`, and `+0xa4`. No SelfSave-specific persistent field write exists. The class therefore adds no data member or generic reserve; its extent is the inherited `CharInputPane` layout.

The `SelfSaveInputPane` primary table has 19 slots. `LineInputPane`/`CharInputPane` own the inherited interface through offset `+0x44`; the class-specific final slot at `+0x48` is `0x005b6800`. Because no base declaration supplies that slot, the prior `void OnConfirmInput() override;` token was compile-invalid and is now superseded. The highest-probability mid-2000s declaration is `virtual void OnConfirmInput();` as installed in the formal block.

Exact vtable layout and source effect:

| View | Base | Object offset | Class/source effect |
| --- | --- | --- | --- |
| primary | `0x006305c0` | `+0` | implicit scalar deleting destructor wrapper, inherited pane/input methods, new `OnConfirmInput` at `+0x48` |
| EventHandler | `0x00630610` | `+0xa0` | compiler destructor adjustor plus inherited event interface |
| TimerHandler | `0x00630640` | `+0xa4` | compiler destructor adjustor plus inherited/default timer callback |

The exact generated target [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md) is one `0x88`-byte cluster with 19 primary slots, an internal EventHandler COL and 11 slots, an internal TimerHandler COL and two slots. There is no target padding or source-authored constant. Its formal marker and [UID:0003HM][SelfSaveInputPaneVtables](by-type/by-vtable/SelfSaveInputPaneVtables.md) marker prevent empty placeholders without hand-authoring vtable/RTTI dwords.

Shared scalar deleting wrapper `0x005b7940` calls LineInputPane cleanup, interprets compiler deletion flags, and conditionally deletes. Its 25 xrefs and adjustor tails `0x005b77c8/0x005b77d3` prove compiler ABI sharing. Do not add an explicit destructor, scalar-wrapper definition, adjustor thunk, vtable array, or RTTI record to this class.

The complete deterministic source order under [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md) is:

| Position | UID | Emitted source role |
| --- | --- | --- |
| `0` | UID0000CW | this class declaration and `[[CHILDREN]]` |
| `10` | UID0003O5 | `SelfSaveInputPane::SelfSaveInputPane()` |
| `20` | UID0003O6 | active `SelfSaveInputPane::OnConfirmInput()` |
| `30` | UID0003O7 | retained private `SelfSaveInputPane::SendSelfSavePacket()` definition |
| `40` | UID0002N8 | exact generated-binary disposition marker |
| `50` | UID0003HM | source-local vtable-index disposition marker |
| `60` | UID0001KQ | retained file-level `CreateSelfSaveInputPane()` factory |

Constructor semantics remain exact: load `g_pLanguageMan`, look up resource id `0x26` / decimal `38` (current text `Save profile? (Y/N) ` including trailing space), and pass the returned `const wchar_t *` to `CharInputPane`. The three vptr stores are compiler effects and stay out of C++.

Exact release confirmation semantics remain: require `TextLength() == 1`; copy one `wchar_t`; accept only `L'y'` or `L'Y'`; then execute the inlined opcode `0x25`, byte-one clear, and one-byte sender core. Human source expresses that core as one call to the private helper.

Retained helper `0x005b6870-0x005b68b1` reads no input or object field and has no ordinary route; private nonvirtual membership is selected from same-family object-call and inlining evidence. Retained factory `0x005aa140-0x005aa1bf` remains a separate file-level source helper. Those negatives cap confidence but do not make either body dead padding or compiler glue.

Keep immediate source file UID0000NM. A partial move to CommandInputPanes is rejected because it would divide the class and its exact children across emitters. InputPanes, BlockListenInputPanes, ItemActionInputPanes, SelfSaveOKPane, LanguageMan, `g_pLanguageMan`, and `g_packetSender` remain base/successor/feature/provider contexts, not direct class owners.

The B002 score at that evidence time was `90/92`. Current class score is `91/93` after closing the private-helper source contract and call/inlining relation.

## 2026-07-13 B004 Private Helper And Source-Order Reconciliation

The class adds no field beyond inherited `CharInputPane` extent `0x108`; `SendSelfSavePacket` is behavior-only. Wield's explicit `ECX=this` helper call and Wear's retained/inlined parallel support private nonvirtual membership even though the SelfSave body does not read a field. Its lack of a vtable slot is expected. The active and retained packet cores normalize to identical SHA256 `3844f03d9ccc79066d190bb05f2908454eeaaee2844c1b056762124a3f57b093`, so the declaration, one active call, and one out-of-line definition are the coherent source model.

The exact member body uses opcode `0x25`, explicit byte-one zero, `Socket *g_packetSender`, and sent length one. Exact binary frame/base/cookie and touched-byte facts stay on the method pages. The class declaration intentionally contains no packet array, vptr, cookie, destructor, adjustor, RTTI, or vtable source. The selected helper declaration is inferred `private`; stripped original access-token placement and capitalization cap confidence without blocking reconstruction.

Completion `91` records the complete class contract, source call/definition relation, hierarchy/layout, prompt, constructor/factory, compiler ABI exclusions, deterministic positions `0/10/20/30/40/50/60`, and rejected alternatives. Confidence `93` reflects agreement among normalized bytes, source-family calls, vtable absence, class order, and providers, with caps for no-route retained bodies and historical translation-unit grouping.

## Cross-References

- [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md)
- [UID:0003HM][SelfSaveInputPaneVtables](by-type/by-vtable/SelfSaveInputPaneVtables.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0001MU][0x005b67c0-0x005b68b1.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b1.SelfSaveInputPane.md)
- [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md)
- [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md)
- [UID:0003O6][0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md)
- [UID:0003O7][0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md)
- [UID:00001P][CharInputPane](by-class/CharInputPane.md)
- [UID:0000CX][SelfSaveOKPane](by-class/SelfSaveOKPane.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `74`, confidence `76`.
- Evidence: the page documents the confirmation role, vtable family, constructor-shaped bytes, real input handler, opcode behavior, shared packet sender, and factory/open-helper caveats; completion remains limited because the raw send helper and factory ownership still need final placement.
- 2026-06-02: Raised to `80/82`, marked `RECONSTRUCTABLE:TRUE`, and attached to [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md).
  Evidence: current IDA MCP reconfirms the exact factory boundary, modeled handler, vtable data reachability, raw constructor/helper byte layout, and absence of direct caller xrefs.
- 2026-06-07 A003 Batch 023 parent gate:
  - Before: `80/82`, below the corrected direct-parent gate for the exact vtable-data child.
  - After: `85/86`, with current hash-backed vtable slot, xref, and boundary evidence.
  - Summary/evidence: the class page already documented confirmation behavior, raw constructor/helper caveats, factory evidence, packet sender state, and source placement; the Batch 023 IDA recheck closes the specific vtable ownership gate while keeping final C++ blocked by the raw helper and file-grouping questions.
- 2026-06-12 A004 Batch 313 cross-reference update: added [UID:0003HM][SelfSaveInputPaneVtables](by-type/by-vtable/SelfSaveInputPaneVtables.md) as the source-local reconstructable vtable page for this class. Scores stay `85/86`; the direct-parent gate was already closed by the 2026-06-07 evidence.
- 2026-06-19 Agent-B007 implementation: Updated the class page for the corrected [UID:0003O7][0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md) range, recorded the retained file-local `SendSelfSavePacket()` source shape, and distinguished the constructor raw body, vtable-routed confirm handler, no-route send helper, and factory/open helper.
- 2026-06-21 Rule 26 B005 incorporation:
  - Changed from: `85/86`, blank class C++, and constructor C++ blocked by raw-start/source-grouping caveats.
  - Changed to: `87/89` with declaration-only first-draft C++.
  - Summary/evidence: B005's constructor pass resolved [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md) as source-ready `SelfSaveInputPane::SelfSaveInputPane()`, mapped `STR.RES` id `0x26` to `Save profile? (Y/N) `, documented the `g_pLanguageMan`/`CharInputPane` call sequence, kept vptr stores as compiler output, preserved no-direct-start-route and final grouping caveats, and rejected base-infrastructure, successor, item-action, SelfSaveOKPane, resource, sender, and generated-name alternatives.
- 2026-06-21 Rule 26 B012 incorporation:
  - Scores remain `87/89`.
  - Added the factory relation for [UID:0001KQ][0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory](by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md): related file-level `CreateSelfSaveInputPane()` source, not a class method; no ordinary route to the helper start; first-draft C++ belongs on the by-memory helper page; and coordinated [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) consolidation must move the whole SelfSave family together if accepted later.
- 2026-07-13 Agent-B002 UID0002N8 callback: raised `87/89 -> 90/92`, set position `0`, replaced compile-invalid `override` with period-plausible `virtual`, documented the inherited `0x108` layout/no added fields, exact three-view hierarchy, implicit destructor/adjustor disposition, source-ready children and positions, prompt/protocol behavior, generated-data markers, no-route caps, and coordinated-only source-file alternative.
- 2026-07-13 Agent-B004 UID0003O7 callback: raised `90/92 -> 91/93`, added the exact private nonvirtual helper declaration, preserved `virtual OnConfirmInput`, prompt constant and `[[CHILDREN]]`, replaced file-static/no-call conclusions with one source call plus retained inlined definition, and preserved every hierarchy/layout/vtable/compiler/factory/grouping fact.
