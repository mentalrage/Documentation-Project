** TARGET-REPORT-UID:0003QN **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003QN SelfLookPaneOnPaint Source-Quality Research


## Finalized Report / Current Recommendation
- Applied callback state: UID0003QN remains the exact `SelfLookPane::OnPaint()` child owned and emitted by UID0000CU at `93/94`, with `RECONSTRUCTABLE:TRUE`, `Nested:0`, blank optional emitter position, and Destination 1 installed byte-for-byte as the complete behavior-identical source-era body.
- Final disposition: the child range remains `[0x00567480,0x00568bd0)`. The modeled method is `[0x00567480,0x00568bb4)`, the 20-byte compiler jump table at `[0x00568bb4,0x00568bc8)` belongs to the nation-name source `switch`, and `[0x00568bc8,0x00568bd0)` is eight bytes of compiler/linker `0xcc` alignment. No split, merge, or separate data emitter is warranted.
- Applied support closure: UID0003QU emits `DrawNumberString`; UID0003QV was UID-preservingly renamed to `SelfLookPaneGetSlotRect`; UID0003QW emits `HitTestSlot`; UID0003QP uses real output rectangles; UID0000CU carries the complete exact-layout class union with `};` before `[[CHILDREN]]`.
- Applied item-image dependency: Destination 1 includes `ItemObjImageLib.h`, declares the existing singleton `extern`, and calls `g_pItemObjImageLib->GetItemGlyphBounds(itemId, &imageBounds)`. UID0000UQ remains the public nonvirtual ItemObjImageLib member owned/emitted by UID00006W; UID0000RA remains the sole singleton definition. No free helper, SelfLookPane member, duplicate ItemObjImageLib declaration, or duplicate global definition was introduced.
- Applied layout support: UID0002RG represents mode-zero `+0x16fc..+0x170b` stores as clearing hover slots 7..20 plus `m_identityLine1[0]`; no `m_cachedLookState*` source alias remains.
- Applied resource/data disposition: UID0003EU, UID0003EW, UID0003F7, UID0003F9, and UID0003FB retain their source-local routes and now carry exact covered-by formals because Destination 1 represents their values as use-site literals/local arrays. Shared UID0003EV/UID0003EX remain unchanged pooled `NONE/FALSE` physical literals.
- Confidence: very strong for behavior, range, ABI, vtable route, helper signatures, ItemObjImageLib member receiver and singleton route, field offsets, resource literals, rectangle tables, source ordering, and class/file ownership; strong for descriptive private names, inferred include/header spelling, and the inferred unused `ProfilePane *` field at `+0x100`.

## Supporting Research
- Mandatory live evidence was collected from the active adopted NexusTK IDB session `64c11373`, discovered through a fresh `idb_list`. Evidence-time `server_health` returned `status:ok`, imagebase `0x00400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and cache size `2067`.
- The MCP session identifier is an evidence-collection-time observation only. This report does not assert present or future MCP availability.
- The exact target has no dedicated prior active, central executed, legacy executed, Older-Research, or SpecialReports report. Existing SelfLook family reports are supporting evidence and were independently checked against the current IDB and current ordinary docs.
- Central executed reports opened as relevant leads:
  - `executed-b-agent-research/B001/0001H7-selflookpane-source-split-audit.md`, SHA256 `626E82F1BA42B23E804070197ADF6050CCFC1FD59B67F863E3F14B2D1B697470`: accepted the exact child range and class/file route but intentionally left full paint source unresolved.
  - `executed-b-agent-research/B001/0002V2-LookGroupCollectionResourceStringData.md`, SHA256 `89DB1963D3B3F65F5EEF356A942A23F07B6614925853C03EFEE19C128D94B330`: split the SelfLook-local resource/constant runs and pooled comma literals.
  - `executed-b-agent-research/B002/0003RB-SelfLookPane2OnPaint-source-quality.md`, SHA256 `902A11F365D69C5F4EC237E72C7A2AADAB60190959A347643E30FBCFF196FC47`: supplied accepted sibling renderer/API/type conventions and exact class-layout precedent, but not this target body.
  - `executed-b-agent-research/B004/00039M-SelfLookPane2LookUpdateRawHelpers-source-quality.md`, SHA256 `0D4E676FAC6E6AF9DC1BC51AF766E0F772F6BAECD8E729D5881C738122C6EB2A`: supplied the accepted ObjectStatusBlob/packet/class union that must not be lost.
  - `executed-b-agent-research/B005/0003UL-UserPaneParsePlayerSettingsPacket-source-quality.md`, SHA256 `270F5C30DD094FB985C6848DF813DBC47B682CF0F31EEE9A726EB98C6220021F`: established settings bits 13/14 as the writers of Config `+0x28de60/+0x28de61`.
  - `executed-b-agent-research/B005/0003UP-UserPaneHandleMovementReplyPacket-source-quality.md`, SHA256 `CB31E9B73313D6E87D94F83515D2FE1F8402C81D908CD25424F3920ED3C400FF`: established current accepted names `m_selfLookTopButtonSelected` and `m_selfLookBottomButtonSelected`.
  - `executed-b-agent-research/B006/0002RC-SelfLookPaneEquipmentRecordParser-source-quality.md`, SHA256 `C6360222F03B567244E6D3084C192FE97A3A1C372A47EA1DC1C70D40CA1B3988`: established the sparse equipment-slot arrays and selector-to-visible-slot mapping.
  - `executed-b-agent-research/B007/0002RE-SelfLookPaneSummaryStatUpdate-source-quality.md`, SHA256 `CE951521BC9046C86051A99000FDDE94FAF913C37812B3765A020BBAE672F3B4`: established the summary tail field family.
  - `executed-b-agent-research/B011/0000NL-SelfLookPane-empty-emitter-family-source-quality.md`, SHA256 `367F8861FFC4DF8536BDEFB8832EC61BD218B94060D67B11F258FBF839636DCF`: established the current partial class emitter and existing child bodies whose complete union must be preserved.
- B005 dependency provenance and current archive:
  - current authoritative artifact: `executed-b-agent-research/B005/0003HT-ItemObjectPaneClearOutputRects-source-quality.md`, SHA256 `239A091708E0374010AD0481F3309F965A515FA12C87FB52CFEBC4BBF62D7C20`, 109,711 bytes / 1,332 lines;
  - validator-owned history records execution command `000000013891`, timestamp `2026-07-16T11:58:01-04:00`, from the former active source path into the centralized archive;
  - current tracker row records UID0003HT at `92/94`, author B005, current target path `by-memory/0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects.md`, and the centralized executed report path;
  - the former active path `tools/leaser/Agents/Agent-B005/research/0003HT-ItemObjectPaneClearOutputRects-source-quality.md` is absent.
- Historical B005 artifacts retained for provenance:
  - accepted report-only Gate-1 artifact SHA256 `39B65BAB47D85D79E7AD3C2FE4AF9D035520AA946C18ADAF1B1097C0E14FE68B` established the exhaustive 48-call receiver analysis;
  - pre-execution callback artifact SHA256 `CC1ADD0037A32B568BD690BB4BEE609A8483400AF2769CE9FFECDF91F37EFEF8`, 109,213 bytes / 1,328 lines, recorded 43 checked / 0 unchecked callback items and immutable callback marker `READY_FOR_SUPERVISOR_GATE2_REVIEW`;
  - callback commands `13820`-`13823`, including bounded contradiction repairs `13821`/`13822` and final waited command `13823`, remain evidence-time implementation provenance rather than current report location or lifecycle state.
- Current ownership boundary is unchanged: the executed B005 work owns UID0000UQ, ItemObjImageLib layout/class/file, and the member-definition correction. B002 owns only the SelfLookPane consumer call, compile-visible include/extern use, and no-loss coordination prose.
- Active B001/B003/B004/B005 research roots were searched for `SelfLookPane`, `UID0003QN`, `UID0003QU`, `UID0003QV`, `UID0003QW`, `UID0000UQ`, `GetItemGlyphBounds`, `ItemObjImageLib`, and `g_pItemObjImageLib`. No active report owns or is editing the SelfLookPane paint/helper/class support lane, and no active B005 UID0003HT report remains.
- Legacy per-agent `research/executed` roots, `Older-Research`, and `SpecialReports` were searched with the same terms and yielded no direct target artifact.
- Wave2/Wave3 material was not used as authority. Historical Wave labels found in ordinary docs remain historical only.

## Target
- Target UID: `0003QN`.
- Target path: `by-memory/0x00567480-0x00568bd0.SelfLookPaneOnPaint.md`.
- Source queue/report row: current reconstructable by-memory tracker item with zero dedicated tracker-linked reports.
- Current supervisor classification: reconstructable exact class method plus owned compiler-data tail.
- Applied scores and parent state: target `93/94`; canonical owner/emitter UID0000CU; blank position; complete formal C++; parent UID0001H7 is `89/92`, semantic owner UID0000CU, `RECONSTRUCTABLE:FALSE`, blank emitter/formal.

## Current Target State
- Applied metadata: `COMPLETION:93`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000CU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CU`, blank `EMITTER_POSITION_OPTIONAL`, complete formal C++, `Nested:0`.
- Owner/emitter/reconstructable state remains correct. The exact virtual method belongs to `SelfLookPane`; its generated route remains UID0000CU -> UID0000NL -> `NexusTK/ui/panels/SelfLookPane.cpp`.
- Historical pre-callback generated command `13791` contained the UID0003QN Empty Emitter Marker, no QU/QV/QW definitions, invalid null helper calls, and invented cache fields. Final waited command `13965` removes every one of those blockers.
- Item-image dependency state:
  - historical/pre-B005 generated SelfLookPane and sibling formals used unqualified `GetItemGlyphBounds(...)`, which was compatible only with the now-superseded free-helper hypothesis;
  - the current executed B005 archive and current ordinary pages establish UID0000UQ as `void ItemObjImageLib::GetItemGlyphBounds(short, RectBounds *)`, with all 48 direct callers supplying `g_pItemObjImageLib` in `ECX` and zero callers consuming `EAX`;
  - Destination 1 carries `#include "ItemObjImageLib.h"`, an external singleton declaration, and the qualified singleton member call. The exact original header basename remains inferred, but the current generated route proves compile visibility without duplicating B005-owned source.
- Blockers closed:
  - target fields/resources/fonts/colors are represented in complete source;
  - UID0003QV is rectangle-only `GetSlotRect`;
  - the owned target table is the five-case nation-name source switch;
  - source-local resources and packed rectangles are covered by use-site literals/local arrays.
- Evidence-time ordinary snapshots:

| Path | SHA256 | Bytes / lines |
| --- | --- | ---: |
| target UID0003QN | `A8F3B56BC025DDEC2E43F068BBBB52A276A52977B0545D9E12594D32E1EC2CEA` | 5,164 / 58 |
| UID0003QU | `1684FB582757954502E56B7A3B072FA26AF54F4A8D16678993D0AE8F842A0B8D` | 2,493 / 44 |
| UID0003QV | `9052209DC0C11A03E16D1FF03522FAD0624CA01211A8C493DC39E7E82961661A` | 3,071 / 46 |
| UID0003QW | `FF2B09628BAFEB7124F51F5ED801FB68A20A60AC89EF291FB7B31BA1766B27CC` | 3,060 / 46 |
| UID0003QP | `C65C4F2CF9AE096A5AE890462E8A83DE1C7C662AB4EB53665DFD9D2690BABBE9` | 14,136 / 234 |
| UID0002RG | `8B349A22494BCF77876B9F18318989B550C571B4BE472C91A08D1D7BED4B07C4` | 14,074 / 124 |
| UID0000CU | `EDE793D4F136A511D06F487C586C04241607A604323E8E263E09011029ADD244` | 36,441 / 252 |
| UID0000NL | `0E5177997D7E2C761A1328882740E9B47EC47CC120EF0CA776D1993E8890DC87` | 58,714 / 245 |
| UID0001H7 | `243E40578E87B62F01EAE8F128B93C375D9943C773AD348722475A3133A7EB9E` | 12,425 / 98 |
| exact vtable UID0002UY | `2511D319B44A341AF3A18427E6E43784FFCEF4F4BF099BE1F415840B0143AEF7` | 10,605 / 133 |
| UID0003EU | `DA115658214FDF38CBB50D4B9A002ECF51D43B9CA04277E89C2D93078C2F2C7D` | 4,414 / 53 |
| UID0003EW | `E6EBAB668ECABC2219AF313FAB3067AFFC7B8CE04A19477D04E52C235B669655` | 3,466 / 51 |
| UID0003F7 | `906AF881B61F4161767398DB5FD209DCEB6C41935551F04FC7BD12F765ACF9D2` | 2,982 / 51 |
| UID0003F9 | `57EFEFDFB0C4F46E2D93051C2CC1026BDBDAB494139B225FE3F0930AD4CC08FE` | 2,761 / 51 |
| UID0003FB | `D5EAC912B52451FE20B302F13C33024A2C9963E54E7F5BD31189C4A687A8E63C` | 3,357 / 52 |
| Config UID000031 | `9ECA99799904B0DD1E6D14E0C84DC784B578E2C31555C3AD7472C9B7A304B473` | 42,362 / 498 |

- Stable post-B005 ItemObjImageLib dependency snapshots:

| Path | SHA256 | Bytes / lines | Current dependency disposition |
| --- | --- | ---: | --- |
| UID0000UQ `GetItemGlyphBounds` | `07687EE62A3E6BF5A6082ED0C9468EDA2173883D29C07622AE6E8A02DD04812F` | 21,031 / 181 | `92/94`, owner/emitter UID00006W, qualified public member body; stale current free-helper wording historicalized by command `13821` |
| UID00017N ItemObjImageLib local cluster | `9006DAE70050AAB8C189FD52E9891F052A0788F4E38B78AA7A92F44FA76E61FA` | 45,089 / 243 | non-emitting index with current member/unused-this truth and superseded free-helper history after command `13822` |
| `by-type/by-struct/ItemObjImageLibLayout.md` | `EC0191F9A365911686F20A6FE1F8BD33AB1E6DF89D1089BB12755862618E08E8` | 15,903 / 138 | one public member declaration |
| `by-class/ItemObjImageLib.md` | `A55CF32348F11721627314215D85DEC93DB99B608CB16B100FE16A60F3A7AD1F` | 43,817 / 208 | class owner/index with member evidence and superseded free route |
| `by-file/ItemObjImageLib.md` | `C8029EDCF08BC14514B73FBCAC7628718F5B12885C766E50579BDC7AF49F7C81` | 40,567 / 209 | prose-only source root with one declaration/qualified-definition route |
| `by-global/g_pItemObjImageLib.md` | `CE6E2DB74A6C65ECE6A99810388B139F88FCF25EDF3F5AF2A21BE085F9690B43` | 9,945 / 96 | sole singleton definition/storage/lifecycle route; unchanged |
| generated `NexusTK/render/ItemObjImageLib.cpp` | latest observed `1BCFB5D0BFE355E3461AA28394B173B7A17B9B09E9ABE846EF5CB3BB6865F33A`; target-proof `9BD19CC95EDCCBDA8BA11FDDC386DC22ACA642763A65CA7250EE6B70976E5219` | 7,625 / 176 | authorized waited command `13965`, refreshed `2026-07-16T12:29:55-04:00`, proved one member declaration, one qualified definition, zero free definitions, zero UID0000UQ markers, and one singleton definition. Latest read-only command `13981`, refreshed `2026-07-16T12:40:20-04:00`, preserves the same bytes below the volatile header. |
| generated `NexusTK/ui/panels/SelfLookPane.cpp` | latest observed `F65D3598DE03DA44180B5648D789D1D5119FA89C43639445B976335F983EA86E`; target-proof `A184B35E3D415C1F0E9CDC920F659CD277CAA703FC372226CE557B9DE0E3C602` | 103,732 / 2,977 | authorized waited command `13965`, refreshed `2026-07-16T12:29:55-04:00`, proved one complete SelfLookPane class, one OnPaint/DrawNumberString/GetSlotRect/HitTestSlot, one qualified target glyph call, zero target unqualified calls, and zero target marker/GetSlotColors/null-slot/cache aliases. Latest read-only command `13981`, refreshed `2026-07-16T12:40:20-04:00`, preserves the same bytes below the volatile header. |

- Latest observed generated SelfLookPane preserves five separately accepted SelfLookPane2 qualified singleton calls while proving the UID0003QN target has exactly one qualified glyph-bounds call and zero unqualified target calls. Normalizing only command `13981`'s command-id and refreshed-at header lines back to command `13965` reproduces the exact target-proof SHA256 for both generated files, proving byte identity below the volatile four-line header.
- Current B005 report provenance is the centralized archive SHA `239A091708E0374010AD0481F3309F965A515FA12C87FB52CFEBC4BBF62D7C20`; the callback SHA is historical evidence only.
- Current artifact/lifecycle status: B002 implementation, scoped validation, waited generation, lease release, and report reconciliation are complete. Current/future Gate 2, manual coverage, execution, path, move, count, and archive state remain external validator/supervisor-owned facts and are not asserted.

## Executive Recommendation
- UID0003QN remains one source method; the nation table and alignment remain compiler-owned.
- `virtual void SelfLookPane::OnPaint()` now emits through UID0000CU in natural address order with blank optional position.
- UID0003QV retains its UID and range at the canonical `SelfLookPaneGetSlotRect` path with exact rectangle-only source.
- UID0003QU and UID0003QW now emit complete `DrawNumberString` and `HitTestSlot` source.
- UID0003QP now passes real `RectBounds` outputs for slots 0 and 1.
- UID0002RG now uses the real equipment-hover storage plus `m_identityLine1[0]`.
- UID0000CU now contains the complete `0x2340` declaration and preserves the full B004/B005/B006/B007/B011 union.
- UID0003QN consumes the B005-owned ItemObjImageLib member/singleton interface without duplicate ownership.
- The five owner-local resource/constant pages now carry exact covered-by comments; pooled comma pages remain unchanged.
- No target-source blocker remains after the stable B005 dependency rebase. Exact original private lexical spellings and header basename are unrecovered, but the chosen descriptive names and interface use are consistent with the accepted sibling class and current generated source family.

## Supervisor Active Recheck
- This report responds to the canonical B002 UID0003QN report-first assignment.
- The assigned item did not require a new child split. It required source-quality closure of an already exact method child and directly affected helpers/class/resource support.
- Every source-bearing item in scope is applied and validated. Destination 1 has a compile-visible ItemObjImageLib dependency and singleton member call; shared comma literals, vtable bytes, switch data, stack cookie, and alignment retain exact no-handwritten-source dispositions.
- Current B005 dependency provenance is the centralized executed archive `executed-b-agent-research/B005/0003HT-ItemObjectPaneClearOutputRects-source-quality.md` at SHA `239A091708E0374010AD0481F3309F965A515FA12C87FB52CFEBC4BBF62D7C20`; the old active path is absent.
- B005 UID0003HT remains a required coordination dependency only. B002 does not claim or duplicate its UID0000UQ/layout/class/file/global implementation work.

## Inference Research Guidance Check
- `by-structure.md` requires source-ready human C++ for eligible emitting items and forbids pasting sibling source into a broad parent. The recommendation therefore keeps source bodies on exact UID0003QN/QU/QV/QW/QP children, puts declarations/layout on UID0000CU, keeps UID0001H7 non-emitting, and keeps by-file prose-only.
- Existing assumptions treated as uncertain and rechecked:
  - IDA's `int __thiscall(_BYTE *this)` target prototype;
  - `GetSlotColors`;
  - generic unexplained switch-tail wording;
  - old `m_selfLookSlot5AlternateStyle` / `m_selfLookSlot6AlternateStyle` aliases;
  - `LOOK.EPF` on UID0003EU;
  - the claim that field/font/resource names still prevent code;
  - null output arguments in UID0003QP;
  - the free/`__stdcall` or unqualified `GetItemGlyphBounds` route.
- Direct IDA facts, documentation evidence, and source inference are separated throughout the report.
- Stale Wave2/Wave3 references were ignored as authority.

## Heuristic / Inference Reanalysis And Validation
- Target return type:
  - IDA guesses `int` because several branches tail-propagate a callee's EAX.
  - The method has only ECX receiver input, plain `ret`, vtable cell `0x006241cc`, and a sibling exact `virtual void OnPaint()` contract at the same primary `+0x44` slot.
  - Resolution: source ABI is `virtual void OnPaint()`. Branch-dependent EAX propagation is compiler residue from ignored call results.
- Target range/source shape:
  - The modeled body is 5,940 bytes and one coherent 162-block paint routine.
  - The five table targets at `0x00567ccb/0x00567cd2/0x00567cd9/0x00567ce0/0x00567ce7` select nation strings.
  - Resolution: one human method with normal source `switch`; no data declaration for the compiler table.
- View-mode source shape:
  - Values 0, 1, and 2 select background frames and default/equipment, stats/spelled, and legend views.
  - Any other value loads `COMMA.EPF` frame zero into the comma context, chooses `ITEMINV.PAL`, blits the still-only-initialized background context, and returns after the unsupported-mode branch.
  - Resolution: preserve this observed quirk; do not normalize it into a common comma load or suppress the initialized-context blit.
- Equipment slot arrays:
  - UID0002RC establishes sparse slot arrays at `+0x14c`, `+0x176`, `+0x18c`, `+0xc0c`, `+0x168c`, and `+0x16e0`.
  - Constructor zeroing and OnPaint reads establish 21 hover bytes at `+0x16f5`.
  - Resolution: use `m_equipmentSlotItemIds`, `m_equipmentSlotRecordStates`, `m_equipmentSlotNames`, `m_equipmentSlotDescriptions`, `m_equipmentSlotValues`, `m_equipmentSlotValueFlags`, and `m_equipmentSlotHoverStates`.
- Packed hover rectangle constants:
  - Direct bytes and local stack copies reconstruct 14 left coordinates `[7,63,121,7,63,121,7,63,121,7,63,121,7,63]` and 14 top coordinates `[10,10,10,62,62,62,114,114,114,166,166,166,218,218]`.
  - Each highlighted slot uses a 48x48 rectangle and offsets the item destination by `(-2,-2)`.
  - Resolution: two function-local `const int[14]` arrays are the most plausible source representation and naturally regenerate the packed `.rdata` copies.
- Config style fields:
  - Parser bits 13/14, exact Config layout, target reads, and slot rectangles prove top/bottom selected-state bytes.
  - Resolution: use accepted `g_pConfig->m_selfLookTopButtonSelected` and `m_selfLookBottomButtonSelected`. Historical alternate-style aliases remain superseded.
- UID0003QU:
  - It loads `9X11FONT.BIN` storage from `this+0xf8`, uses 9x11 cells with row stride 9, 99 bytes per glyph, glyph-set formula `character + 10*glyphSet - 47`, special FONTSYMB frame 4 for `'-'`, skips space and slash rendering, and always advances x by 9.
  - Callers pass glyph sets 0, 1, and 2; therefore a bool is invalid.
  - Resolution: `void DrawNumberString(const wchar_t *, int, int, unsigned char)`.
- UID0003QV:
  - The helper never reads or writes colors. It writes a `RectBounds` for slot IDs 0 through 20 and invalid bounds otherwise.
  - Slots 0/1/2 exist only in mode 0; slot 3 differs between modes 1 and 2; slot 4 exists in modes 0/1; slot 5 and slots 7-20 receive the `(2,272)` extended-layout offset; slot 6 does not.
  - Resolution: UID-preserving rename to `SelfLookPaneGetSlotRect`; `void GetSlotRect(short, RectBounds *) const`.
- UID0003QW:
  - The helper calls GetSlotRect for IDs 0..20, calls point-in-rect, returns the first slot, and returns `-1` in AX.
  - Resolution: `unsigned short HitTestSlot(int, int) const`, miss value `0xffff`.
- UID0003QP null arguments:
  - Binary xrefs at `0x568f5d`, `0x5691dd`, and `0x5691ed` call UID0003QV with real stack output rectangles.
  - UID0003QV has no null check and immediately writes the output.
  - Resolution: current formal nulls are invalid reconstruction, not an original behavior. Use scoped local rectangles.
- Item glyph helper receiver and compile visibility:
  - B005 audited all 48 direct UID0000UQ call sites across 23 functions; every call supplies `g_pItemObjImageLib` in `ECX`, and no caller consumes the machine result.
  - Current UID0000UQ and ItemObjImageLib layout evidence therefore establish `void ItemObjImageLib::GetItemGlyphBounds(short, RectBounds *)` as a public nonvirtual member whose body optimizes away unused `this`.
  - An unqualified call in `SelfLookPane::OnPaint` would require the rejected free-helper route or a nonexistent SelfLookPane member. A forward declaration alone would also be insufficient for member lookup on an incomplete type.
  - Resolution: Destination 1 includes the complete ItemObjImageLib interface with `#include "ItemObjImageLib.h"`, declares `extern ItemObjImageLib *g_pItemObjImageLib;`, and calls `g_pItemObjImageLib->GetItemGlyphBounds`. The header/include spelling is source-shape inference; the receiver, member ownership, singleton identity, and no-duplicate-definition route are current accepted facts.
- Class tail:
  - `SelfLookPane` and accepted `SelfLookPane2` align from `+0x170a` onward: two 256-wide identity lines, one 256-wide status line, two 128-wide strings, two dwords, three bytes, one dword, timing fields, three toggle bytes, two 256-wide strings, view fields, button frames, and final cache toggle.
  - Resolution: reuse the accepted source-family names where behavior matches and preserve current SelfLook-specific names already emitted.
- View-cache clear alias:
  - Evidence-time / pre-callback UID0002RG named four dword stores at `+0x16fc`, `+0x1700`, `+0x1704`, and `+0x1708` as separate cached-look fields. Current UID0002RG instead carries the applied hover-slot plus first-identity-wchar source described below.
  - UID0003QN proves bytes `+0x16fc..+0x1709` are the visible equipment hover-state run for slots 7..20, and the parser/layout prove `m_identityLine1` begins at `+0x170a`.
  - Resolution: represent the source as clearing the 14 hover bytes for slots 7..20 and setting `m_identityLine1[0]` to NUL. Those adjacent source statements explain the compiler's four contiguous dword stores without an out-of-bounds array write or invented members.

### Exact SelfLookPane Layout

| Offset | Size | Source-facing field/type | Evidence |
| --- | ---: | --- | --- |
| `+0x000..+0x0f7` | `0xf8` | inherited `PanelPane` | constructor/base/vtable family |
| `+0x0f8` | 4 | `unsigned char *m_statDigitFrames` | `9X11FONT.BIN`, UID0003QU |
| `+0x0fc` | 4 | `SpelledPane *m_spelledPane` | constructor and accepted child methods |
| `+0x100` | 4 | `ProfilePane *m_profilePane` | exact sibling-aligned field gap; lexical confidence cap |
| `+0x104` | 4 | `LegendPane *m_legendPane` | constructor/view helper |
| `+0x108` | `0x44` | `ObjectStatusBlob m_selfLookObjectStatus` | accepted packet/update union |
| `+0x14c` | `0x2a` | `unsigned short m_equipmentSlotItemIds[21]` | parser/clear/paint |
| `+0x176` | `0x15` + 1 implicit pad | `unsigned char m_equipmentSlotRecordStates[21]` | parser/paint |
| `+0x18c` | `0xa80` | `wchar_t m_equipmentSlotNames[21][64]` | parser stride `0x80` |
| `+0xc0c` | `0xa80` | `wchar_t m_equipmentSlotDescriptions[21][64]` | parser stride `0x80` |
| `+0x168c` | `0x54` | `unsigned int m_equipmentSlotValues[21]` | parser |
| `+0x16e0` | `0x15` | `unsigned char m_equipmentSlotValueFlags[21]` | parser |
| `+0x16f5` | `0x15` | `unsigned char m_equipmentSlotHoverStates[21]` | constructor, OnPaint, OnMouseClick |
| `+0x170a` | `0x200` | `wchar_t m_identityLine1[256]` | parser/OnPaint |
| `+0x190a` | `0x200` | `wchar_t m_identityLine2[256]` | parser/OnPaint |
| `+0x1b0a` | `0x200` | `wchar_t m_statusLineA[256]` | parser/sibling layout |
| `+0x1d0a` | `0x100` | `wchar_t m_statusLineB[128]` | parser/sibling layout |
| `+0x1e0a` | `0x100` | `wchar_t m_statusName[128]` | UserStatus copy/sibling layout |
| `+0x1f0a` | 2 | implicit alignment | dword alignment |
| `+0x1f0c` | 4 | `m_summaryCompareKey0` | accepted UID0002RE |
| `+0x1f10` | 4 | `m_summaryCompareKey1` | accepted UID0002RE |
| `+0x1f14` | 3 + 1 implicit pad | `m_summaryTailByte0..2` | parser/UID0002RE/OnPaint |
| `+0x1f18` | 4 | `m_summaryTailValue` | parser/UID0002RE/OnPaint |
| `+0x1f1c` | 4 | `m_lastSelfLookOptionTick` | OnMouseClick |
| `+0x1f20` | 4 | `m_selfLookOptionRepeatDelay` | constructor value 1000 |
| `+0x1f24` | 3 + 1 implicit pad | body/face/stats toggle bytes | constructor/paint/mouse |
| `+0x1f28` | `0x200` | `wchar_t m_auxiliaryText[256]` | parser/OnPaint |
| `+0x2128` | `0x200` | `wchar_t m_spelledSourceText[256]` | constructor/sibling layout |
| `+0x2328` | 4 | `m_activeViewMode` | view methods/paint/helper |
| `+0x232c` | 4 | `m_serverRequestedViewMode` | accepted external packet writer |
| `+0x2330` | 4 | `m_reservedViewState` | exact sibling-aligned field; lexical cap |
| `+0x2334` | 4 | `m_pendingMouseAction` | paint/mouse |
| `+0x2338` | 4 | `m_pendingMouseView` | paint/mouse |
| `+0x233c` | 1 + 3 implicit tail pad | `m_viewCacheToggle` | constructor/view helper/paint |
| total | `0x2340` | natural 4-byte-aligned class size | contiguous offset arithmetic |
- Resource literals:
  - Fresh UTF-16 bytes decode `LOOKEXT.EPF`, `LOOKEXT.PAL`, `SELFLOOK.EPF`, `LOOKICON.PAL`, `LOOKICON.EPF`, `STATBUTS.EPF`, nation/spirit strings, `9X11FONT.BIN`, `FONTSYMB.EPF`, `FONTSYMB.PAL`, `INVENBUT.EPF`, `ONOFFBUT.EPF`, `BUTTON.PAL`, and `INVENBUT.PAL`.
  - Resolution: correct historical `LOOK.EPF` to `SELFLOOK.EPF`; use literals at exact call sites.
- Large-number formatting:
  - The binary formats `%10u`, draws three fixed three-character groups from indices 7, 4, and 1, draws the leading character separately, and renders commas according to `(digitCount-1)/3`.
  - It repeats the secure three-character copy three times per group. This is odd but observable CRT-call behavior and is preserved by a three-pass copy loop inside the formal macro.
- Stats-button tail:
  - Disabled state fills with color 143 and returns.
  - Enabled state only looks up STATBUTS frame 9 or 4 and returns without rendering it.
  - Resolution: preserve the lookup-only return; do not add an apparently missing draw.
- Rejected alternatives:
  - `GetSlotColors`: rejected because no color operation exists.
  - `GetSlotBounds`: defensible but weaker than `GetSlotRect`, which matches current `GetButtonRect` family naming and actual RectBounds output.
  - bool glyph-set argument: rejected by target calls with value 2.
  - separate switch-table source object: rejected as compiler lowering of the nation `switch`.
  - source-local comma ownership: rejected by cross-owner xrefs.
  - hand-emitted vtable/RTTI/stack-cookie/padding: rejected as compiler/ABI output.
  - modern helper extraction for grouped numbers: rejected because no separate binary function exists; a local C++03 macro preserves source-era expansion without inventing a callable helper.

## Evidence Standards Used
- Direct IDA MCP: `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `decompile`, `disasm`, `stack_frame`, `xrefs_to`, `analyze_function`, and `analyze_component`.
- Exact bytes and SHA256 for body, table, padding, full child, and helper ranges.
- Vtable slot and data-xref evidence.
- Constructor/parser field writes and target/helper reads.
- Caller/callee and support-source comparison.
- Current ordinary docs, generated output, manual coverage rows, and relevant executed reports used as leads and union constraints.
- Negative evidence: zero ordinary callers to OnPaint, no separate function at owned data tails, no color access in UID0003QV, no null tolerance, no separate source helper for grouped-number rendering, and cross-owner comma xrefs.
- Evidence is sufficient for `93/94`, not `95/95`, because exact original private spellings, original macro spelling, and the semantic reason for a few deliberate paint quirks are unrecovered.

## Evidence Checked
- IDA MCP/manual-disassembly/raw-byte checks performed:
  - fresh `idb_list` -> one adopted active session `64c11373`, worker PID 21508;
  - `server_health(database=64c11373)` -> healthy analysis/Hex-Rays/string cache;
  - bounded function lookups at target/helper starts and exact ends;
  - target decompile with addresses; helper decompiles with addresses;
  - target/helper instruction totals, stack frames, callers/xrefs, callees, blocks, and complexity;
  - exact raw bytes for target body/table/padding/full child and helper body/tails;
  - direct UTF-16 decoding of resource strings;
  - constructor and character-data parser field-write checks.
- Existing search terms:
  - `UID0003QN`, `[UID:0003QN]`, `0x00567480`, `0x00568bd0`, `SelfLookPaneOnPaint`, `sub_567480`;
  - `UID0003QU`, `0x00569d80`, `DrawNumberString`;
  - `UID0003QV`, `0x00569ed0`, `GetSlotColors`, `GetSlotRect`;
  - `UID0003QW`, `0x0056a300`, `HitTestSlot`;
  - `SelfLookPane`, `UID0000CU`, `UID0000NL`, `LOOKEXT`, `SELFLOOK`, `LOOKICON`, `STATBUTS`, `COMMA`, `9X11FONT`, `FONTSYMB`;
  - `m_selfLookTopButtonSelected`, `m_selfLookBottomButtonSelected`, `0x28de60`, `0x28de61`.
  - `UID0000UQ`, `0x004df460`, `0x004df4f9`, `GetItemGlyphBounds`, `ItemObjImageLib::GetItemGlyphBounds`, `g_pItemObjImageLib`, `ItemObjImageLibLayout`, `ItemObjImageLib.cpp`, `ItemObjImageLib.h`, `free`, `__stdcall`.
- Report roots searched and outcomes:
  - `executed-b-agent-research`: no dedicated UID0003QN report; nine relevant supporting reports opened and classified in Supporting Research.
  - active `tools/leaser/Agents/Agent-B001/research` through `Agent-B005/research`: no overlapping SelfLook report or ordinary edit lane; the former B005 UID0003HT active path is absent.
  - centralized executed B005 UID0003HT archive: opened at current SHA `239A091708E0374010AD0481F3309F965A515FA12C87FB52CFEBC4BBF62D7C20`; validator history records execution command `13891`.
  - legacy `tools/leaser/Agents/Agent-B001/research/executed` through B005 equivalent roots: no direct target result.
  - `Older-Research`: no direct target result.
  - `SpecialReports`: no direct target result.
- Current docs checked:
  - target, UID0003QU/QV/QW/QP, UID0002RG, UID0000CU, UID0000NL, UID0001H7, UID0002UY;
  - UID0003EU/EV/EW/EX/F7/F9/FB;
  - Config UID000031 and RegistryConfig file evidence;
  - accepted equipment/summary/packet/class support;
  - generated `SelfLookPane.cpp`;
  - current centralized B005 UID0003HT archive, validator-owned execution footer, absent former active path, and tracker row;
  - UID0000UQ, ItemObjImageLib layout/class/file, `g_pItemObjImageLib`, generated `ItemObjImageLib.cpp`, and their member/global ownership routes;
  - manual by-memory/by-class/by-file coverage rows.
- Negative checks:
  - no modeled function at `0x00568bb4`, `0x00569ec1`, `0x0056a29e`, or `0x0056a373`;
  - no ordinary code caller of UID0003QN; one vtable data xref only;
  - no color work in UID0003QV;
  - no null output tolerance in UID0003QV;
  - no current exact child rows for UID0003QN/QU/QV/QW/QP or owner-local resource pages in manual by-memory coverage;
  - no by-struct manual coverage file and no affected by-type row requiring change;
  - no defensible free/static/unqualified UID0000UQ call route after the 48-call receiver audit;
  - no need for B002 to emit another ItemObjImageLib class, member definition, or singleton definition.
- Failed/unavailable/intentionally skipped checks:
  - no IDA DB mutation or rename was attempted because the assignment is read-only report-first;
  - no validator or generated refresh was run because implementation is not authorized;
  - no report lifecycle command was run.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0003QN remains exact `[0x00567480,0x00568bd0)`: 5,940-byte body, 20-byte nation switch table, eight-byte alignment. | Very strong | lookup/get_bytes/hashes | UID0003QN Destination 1 and current range/evidence sections; validator `13942`/`13961`/`13965` | incorporate | applied |
| C02 | Source ABI is `virtual void SelfLookPane::OnPaint()` at primary vtable `+0x44`; no ordinary callers. | Very strong | vtable `0x6241cc`, xrefs, sibling ABI | UID0003QN and UID0000CU byte-equal formals; generated command `13965` | incorporate | applied |
| C03 | Stack cookie, 1729-instruction lowering, jump table, register temporaries, and alignment are compiler-only. | Very strong | disasm/analyze/stack frame | UID0003QN compiler-boundary evidence and by-file exclusions | incorporate | applied |
| C04 | Modes 0/1/2 load SELFLOOK or LOOKEXT background frames 0/1/2 and corresponding palette. | Very strong | target decompile, UTF-16 bytes | UID0003QN Destination 1 and complete behavior evidence | incorporate | applied |
| C05 | Unsupported mode preserves COMMA.EPF load, ITEMINV.PAL lookup, initialized-background blit, then return. | Strong | target control flow | UID0003QN Destination 1/default-path evidence | incorporate | applied |
| C06 | Mode 0 loops visible equipment slots 7..20, obtains bounds through `g_pItemObjImageLib->GetItemGlyphBounds`, centers item glyphs, then draws record-state item images through the same singleton. | Very strong | target decompile, UID0002RC, B005 UID0003HT receiver audit | UID0003QN body/dependency evidence; generated target count `1` qualified/`0` unqualified | incorporate | applied |
| C07 | Hover state 1 offsets item by -2/-2 and draws exact 14-entry 48x48 highlight grid. | Very strong | packed constants, target decompile | UID0003QN plus UID0003F7/F9/FB covered-by pages | incorporate | applied |
| C08 | Item IDs/states/hover arrays use accepted class offsets and sparse slot IDs. | Very strong | constructor/parser/paint | UID0003QN and complete UID0000CU union | incorporate | applied |
| C09 | Config top/bottom selected bytes choose ONOFFBUT frame/source state for slots 5/6. | Very strong | B005 reports, Config layout, target | UID0003QN and UID0000CU; Config verified unchanged | incorporate | applied |
| C10 | Bottom navigation uses INVENBUT frames `7*action+6` and `7*view+5` in modes 0/1/2. | Very strong | target decompile | UID0003QN Destination 1 | incorporate | applied |
| C11 | Face/body disabled branches fill color 143; stats enabled branch is lookup-only and returns. | Very strong | target decompile | UID0003QN Destination 1 and behavior evidence | incorporate | applied |
| C12 | Mode 1 draws two identity lines in shadow/highlight passes at exact coordinates/colors. | Very strong | target decompile/parser writes | UID0003QN Destination 1 | incorporate | applied |
| C13 | Owned target jump table is the five-case nation switch for Neutral/Koguryo/Buya/Nagnang/Han. | Very strong | table refs/targets/strings | UID0003QN body/range/compiler evidence | incorporate | applied |
| C14 | Spirit IDs map Ju jak/Baekho/Hyun moo/Chung ryong and render with the same centered triple pass. | Very strong | target decompile/strings | UID0003QN Destination 1 | incorporate | applied |
| C15 | Three percent stats use exact exposed rectangles, `%u`, 9-pixel centering, glyph set 1. | Very strong | target decompile | UID0003QN Destination 1 | incorporate | applied |
| C16 | Three large values use `%10u`, fixed groups 7/4/1 plus leading char, comma count, and glyph sets 2/2/0. | Very strong | target decompile | UID0003QN Destination 1 | incorporate | applied |
| C17 | Three signed tail bytes use `%d`, right alignment, exact rectangles, and glyph set 2. | Very strong | target decompile, summary fields | UID0003QN Destination 1 | incorporate | applied |
| C18 | Auxiliary text is drawn only when length exceeds seven, from `m_auxiliaryText+7`, with exact triple pass. | Very strong | target decompile/parser write | UID0003QN Destination 1 | incorporate | applied |
| C19 | Mode 2 draws only the two bottom navigation buttons after the common background. | Very strong | target control flow | UID0003QN Destination 1 | incorporate | applied |
| C20 | UID0003QU is a void 9x11 digit/symbol renderer using 99-byte frames and glyph sets 0..2. | Very strong | helper decompile/xrefs/constructor | UID0003QU Destination 2; validator `13908`; generated one definition | incorporate | applied |
| C21 | UID0003QV is rectangle-only and must be UID-preserving renamed to SelfLookPaneGetSlotRect. | Very strong | helper decompile/callees | UID0003QV new canonical path; validator `13897`; old path absent; UID unique | reject-stale | applied |
| C22 | GetSlotRect exact mode/slot rectangles include extended offset for slot 5 and 7..20, not slot 6. | Very strong | helper decompile | UID0003QV Destination 3 and complete evidence | incorporate | applied |
| C23 | UID0003QW is a 21-slot first-hit loop returning `0xffff` on miss. | Very strong | helper decompile/xrefs | UID0003QW Destination 4; validator `13917`; generated one definition | incorporate | applied |
| C24 | UID0003QP must use real RectBounds outputs; current null calls are invalid and crash-prone. | Very strong | binary callers, no-null helper | UID0003QP byte-equal Destination 5; validators `13928`/`13962`/`13963`; generated zero null calls | reject-invalid | applied |
| C25 | UID0000CU can use the exact `0x2340` natural layout; UID0002RG's mode-zero dword stores clear hover slots 7..20 plus the first identity-line wchar rather than invented cached-look fields. | Strong | constructor/parser/paint/raw helper/sibling layout | UID0000CU Destination 6 and UID0002RG Destination 12; validators `13944`/`13946`/`13960` | incorporate | applied |
| C26 | Canonical owner UID0000CU and file route UID0000NL remain correct; UID0001H7 remains non-emitting; external ItemObjImageLib consumption does not move target ownership. | Very strong | vtables/cluster/current docs/member dependency | Metadata retained; UID0001H7/UID0000NL synchronized by `13958`/`13959` | already-present | already-present |
| C27 | Owner-local resource/rectangle pages are represented by target use-site literals/local arrays; shared comma pages stay pooled. | Very strong | xrefs/bytes/source placement | Destinations 7-11 applied; pooled UID0003EV/EX verified unchanged | incorporate | applied |
| C28 | Recommended scores are target 93/94, QU 92/93, QV 92/94, QW 91/93, QP 90/92, class 93/94, file 93/94, parent 89/92, local data 90/92. | Strong | blocker closure and source readiness | Current ordinary metadata/hashes and scoped validator results | incorporate | applied |
| C29 | Generated output should contain one complete class and target/helper definitions with no target empty marker or GetSlotColors spelling, and UID0003QN must contain the singleton-qualified member call with no unqualified glyph-helper call. | Strong | current generated snapshot and formal route | Waited target proof `13965`, SHA `A184...C602`; latest observed header-only refresh `13981`, SHA `F65D...A86E`, exact normalized parity | incorporate | applied |
| C30 | Exact manual coverage replacements/insertions are supplied; B002 does not edit supervisor-owned coverage or lifecycle state. | Very strong | current manual rows/workflow | Immutable 15-row handoff retained; current manual hashes/readback recorded; no manual edit | incorporate | excluded-with-reason |
| C31 | UID0000UQ is the public nonvirtual `ItemObjImageLib::GetItemGlyphBounds` member; every one of 48 direct callers supplies `g_pItemObjImageLib` in ECX and zero consume EAX. | Very strong | B005 exhaustive caller audit/current UID0000UQ/layout/class/file | Stable B005 ordinary hashes and UID0003QN consumer body | incorporate | applied |
| C32 | `g_pItemObjImageLib` is the existing singleton dependency and UID0000RA remains its sole definition; B002 emits only an external declaration before UID0003QN. | Very strong | global lifecycle/storage page and current generated ItemObjImageLib route | UID0000RA unchanged; commands `13965` and latest observed `13981` each read back one singleton definition | already-present | already-present |
| C33 | The historical free/`__stdcall` and unqualified `GetItemGlyphBounds` route is incompatible with current receiver evidence and must not remain current source-facing text. | Very strong | 48/48 hidden-receiver setup, zero result consumers | UID0003QN/history/file prose and generated zero target unqualified calls | reject-stale | applied |
| C34 | B005 exclusively owns UID0000UQ and ItemObjImageLib layout/class/file implementation; B002 callback rebases only the SelfLookPane consumer over the stable B005 union and adds no duplicate owner/source. | Very strong | current centralized B005 archive, historical callback artifact, tracker, and stable ordinary readback | B005 hashes unchanged; B002 changed no ItemObjImageLib ordinary page | incorporate | applied |
| C35 | Final generated verification must show one ItemObjImageLib member declaration, one qualified UID0000UQ definition, zero unqualified free definitions, and SelfLookPane UID0003QN using exactly one `g_pItemObjImageLib->GetItemGlyphBounds` call. | Strong | accepted formal routes/current generated baselines | Waited command `13965` and latest observed read-only command `13981`: `1/1/0`, target `1` qualified/`0` unqualified; exact normalized parity | incorporate | applied |

## Positive Evidence Summary
- One primary vtable data xref directly maps `0x006241cc` to target entry `0x00567480`.
- The target body has one coherent paint CFG, one class receiver, source-family render APIs, and exact mode/slot/field/resource behavior.
- Constructor/parser writes align with all paint reads and with the accepted SelfLookPane2 tail layout.
- Helper callers and output behavior prove final signatures and disprove stale names.
- Resource bytes and owner-local xrefs support exact literal spelling and source placement.
- The sibling source-ready SelfLookPane2 renderer supplies accepted naming/API/style precedent without substituting for this target.
- Exhaustive B005 review of UID0000UQ supplies positive receiver evidence that the target's glyph-bounds call is an ItemObjImageLib singleton member call, not a free helper. The current layout declaration and qualified body provide the consumed interface without transferring ownership to SelfLookPane.

## IDA MCP Facts
- Function/range facts:
  - `sub_567480` starts `0x00567480`, size `0x1734`, exclusive end `0x00568bb4`.
  - target body: 5,940 bytes, SHA256 `C13F998CBA4613DE6F2FA7C54DFD8F341B6863287353A9AFAB5D3DE9923ACE5A`.
  - target table: 20 bytes, SHA256 `30F2D68672230FCD982AA759D130E5C778D4AB2AA7628BAB4737D32979550B1A`.
  - target padding: eight bytes, SHA256 `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`.
  - full child: 5,968 bytes, SHA256 `25135512526A653B304385D68153A27CE5EA16E947927902643F776CFBBF24AE`.
  - first 16 bytes: `55 8b ec 81 ec 64 02 00 00 a1 24 2f 67 00 33 c5`.
  - 1,729 instructions, 162 blocks, cyclomatic complexity 74, local allocation `0x264`, stack-cookie frame.
- Data/table/padding facts:
  - table dwords: `0x00567ccb`, `0x00567cd2`, `0x00567cd9`, `0x00567ce0`, `0x00567ce7`.
  - table belongs to the nation switch.
  - next modeled function begins exactly at `0x00568bd0`.
- Xref facts:
  - zero ordinary code callers.
  - one data xref from primary vtable cell `0x006241cc`.
  - target calls UID0003QU twelve times and UID0003QV ten times.
- Helper facts:
  - UID0003QU body 321 bytes, SHA256 `6C488EE18AD4132C5EC52BA9CAC40E62950B4206649C128B6DD3026FF8C27632`, 115 instructions, 9 blocks, complexity 6, twelve target xrefs.
  - UID0003QV body 974 bytes, SHA256 `67BF3C7687FC13896665BE9FD67FA0FEF44B1638D33A4A5E89D855D4FE91A337`, 309 instructions, 50 blocks, complexity 33; full child 1,072 bytes, SHA256 `57C1EFB063ADB4107504876AF455051D8396AA1BAB0016E54DD489EE400DF6F8`.
  - UID0003QW body 115 bytes, SHA256 `D4D7F5B997DA871629A2FD7B66AB868B8DE2C78B9F523F6BA59286555481B155`, 49 instructions, 5 blocks, complexity 2, three UID0003QP callers.
- Vtable/global/type facts:
  - primary SelfLookPane vtable base `0x00624188`; target at `+0x44`.
  - Config top/bottom selected bytes are at `+0x28de60/+0x28de61`.
  - accepted EPFTileContext uses `void *pixelData`, `RectBounds bounds`, and `int rowStridePixels`.
- Negative IDA facts:
  - no separate modeled table function/data owner;
  - no UID0003QV color helper calls;
  - no null-safe output route;
  - no source-level vtable, cookie, or alignment body.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00567480-0x00568bd0` | UID0003QN target | `virtual void OnPaint()` plus compiler tail | true | UID0000CU | `93/94` | applied source-ready |
| `0x00569d80-0x00569ec1` | UID0003QU | `DrawNumberString` | true | UID0000CU | `92/93` | applied source-ready |
| `0x00569ed0-0x0056a300` | UID0003QV renamed path | `GetSlotRect` plus compiler tail | true | UID0000CU | `92/94` | applied UID-preserving rename/source-ready |
| `0x0056a300-0x0056a373` | UID0003QW | `HitTestSlot` | true | UID0000CU | `91/93` | applied source-ready |
| `0x00568cb0-0x005693d0` | UID0003QP | `OnMouseClick` | true | UID0000CU | `90/92` | applied bounded formal correction |
| `0x0056b9f0-0x0056ba99` | UID0002RG | `ToggleSelfLookViewCache` raw helper | true | UID0000CU | `89/92` | applied field/layout synchronization |
| `0x00565610-0x0056a373` | UID0001H7 | exact child index | false | UID0000CU | `89/92` | remains non-emitting |
| class declaration | UID0000CU | complete `SelfLookPane` declaration/layout | true | UID0000NL | `93/94` | applied source-ready union |
| source file | UID0000NL | `SelfLookPane.cpp` route | n/a | FILE | `93/94` | applied prose/score sync |
| local literals/constants | UID0003EU/EW/F7/F9/FB | target-owned source data | true | UID0000NL | `90/92` each | applied covered-by formals |
| shared comma literals | UID0003EV/EX | pooled physical strings | false | NONE | `85/88` | verify-only unchanged |
| exact vtable data | UID0002UY | compiler-generated vtable bytes | true/generated-binary | UID00038M | `89/92` | verify-only unchanged |
| `0x004df460-0x004df4f9` | UID0000UQ | public nonvirtual `ItemObjImageLib::GetItemGlyphBounds` dependency | true | UID00006W | `92/94` current executed B005 state | B005-owned verify/coordination dependency |
| singleton/header route | UID0000RA / UID0001UU / UID0000KH | `g_pItemObjImageLib` definition plus ItemObjImageLib declaration/file route | true | UID00006W / FILE | current scores retained | B005-owned or verify-only; B002 consumes only |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x006241cc` | data -> `0x00567480` | primary vtable `+0x44` OnPaint route |
| twelve sites `0x56800f` through `0x568927` | target -> UID0003QU | percentage, grouped-number, signed-byte rendering |
| ten sites `0x567619` through `0x568b79` | target -> UID0003QV | equipment/button rectangle resolution |
| `0x566fdc`, `0x56709c`, raw `0x56715c` | toggle helpers -> UID0003QV | slot 0/1/2 rectangle consumers |
| `0x568f5d`, `0x5691dd`, `0x5691ed` | UID0003QP -> UID0003QV | real stack output rectangles |
| `0x56a327` | UID0003QW -> UID0003QV | 21-slot hit-test loop |
| `0x568d29`, `0x568eae`, `0x5692aa` | UID0003QP -> UID0003QW | click/move hit tests |
| target equipment-loop glyph site | UID0003QN -> UID0000UQ | source call must load `g_pItemObjImageLib` as receiver and call the public member |
| 48 direct UID0000UQ call sites across 23 functions | callers -> UID0000UQ | every caller supplies the singleton receiver; zero support a free/static route |

## Documentation Evidence And IDA Status
- Historical pre-callback state: target/helper docs preserved ranges/ownership/callers but were incomplete about source behavior and retained stale names/blockers. Current callback state source-closes all accepted target/helper pages.
- UID0002UY already records the exact `0x006241cc -> 0x00567480` slot and needs no ordinary edit.
- Config UID000031 already contains `m_selfLookTopButtonSelected` and `m_selfLookBottomButtonSelected` at exact offsets and needs no ordinary edit.
- UID0003EV/UID0003EX already preserve pooled non-emitting ownership and need no edit.
- Historical pre-callback UID0000CU was partial and lacked `[[CHILDREN]]` placement. Current UID0000CU is `93/94` with the byte-equal complete Destination 6 block and class closure before children; validators `13944`/`13960` passed.
- Historical pre-callback UID0002RG used four undeclared `m_cachedLookState*` names. Current UID0002RG is `89/92` with byte-equal Destination 12 hover-slot/identity-line source; validator `13946` passed.
- B005-owned ItemObjImageLib support is a direct dependency, not unrelated work. Current UID0000UQ, UID0001UU, UID00006W, and UID0000KH establish one public member declaration/qualified definition route; UID0000RA preserves the singleton definition. The authoritative B005 report is now the centralized executed archive, and B002 must not edit or duplicate those routes during report-only repair.
- Historical command `13823` and report-only command `13892` established the B005 dependency baseline. Final B002 command `13965` preserves one member declaration, one qualified UID0000UQ definition, zero free definitions, zero UID0000UQ markers, and one singleton definition; latest observed read-only command `13981` retains the same semantic and byte-normalized result.
- Historical pre-callback generated output had one UID0003QN marker, zero target helpers, stale `GetSlotColors`, invalid null calls, and invented cache fields. Final B002 command `13965` has zero of those blockers and exact target/helper definitions; latest observed command `13981` differs only in volatile command/timestamp header text.

## Ranked Ownership Analysis

### 1. UID0000CU SelfLookPane
- Evidence for: primary vtable slot, ECX receiver, class-local fields, direct helper family, constructor/parser writes, current owner route, and address cluster.
- Evidence against: no original PDB/private names.
- Decision: retain as canonical owner and emitter.

### 2. UID0000NL SelfLookPane.cpp
- Evidence for: accepted source family, both SelfLookPane classes, resource/data xrefs, current generated route, and address/source ordering.
- Evidence against: exact historical filename is inferred rather than recovered.
- Decision: retain as source-file root, not direct semantic owner of class methods.

### 3. Resource/data owner or synthetic render helper file
- Evidence for: the target has many resource and drawing dependencies.
- Evidence against: all receiver state and vtable evidence are class-local; splitting the method by resources or render phases would invent functions/files absent from the binary.
- Decision: reject.

### 4. UID00006W ItemObjImageLib dependency
- Evidence for ownership of UID0000UQ: the exact helper's 48 direct callers all supply `g_pItemObjImageLib` in ECX, current layout declares the member, and current source emits one qualified definition.
- Evidence against ownership of UID0003QN: target vtable, fields, mode state, render ordering, and all other receiver behavior remain SelfLookPane-local.
- Decision: ItemObjImageLib owns the called helper and singleton interface only. SelfLookPane owns OnPaint and consumes that interface through an include plus external singleton declaration.

### Proposed new file/grouping, if applicable
- Not applicable. The existing `NexusTK/ui/panels/SelfLookPane.cpp` grouping is the strongest source placement.

## Source Placement
- Recommended placement: class declaration on UID0000CU, method/helper definitions on exact by-memory children, generated through UID0000NL to `NexusTK/ui/panels/SelfLookPane.cpp`.
- Source order: class declaration; existing address-ordered SelfLookPane children; UID0003QN OnPaint before OnKeyPress/OnMouseClick; UID0003QU DrawNumberString; renamed UID0003QV GetSlotRect; UID0003QW HitTestSlot; later packet/update helpers; sibling SelfLookPane2 union.
- Compile-visible dependency placement: Destination 1 begins with `#include "ItemObjImageLib.h"` and `extern ItemObjImageLib *g_pItemObjImageLib;` before the method definition. The probable original top-of-translation-unit include belongs in SelfLookPane file prose; the valid child emitter carries the exact text because by-file roots cannot emit reconstruction metadata.
- Definition ownership remains singular: UID0001UU supplies the ItemObjImageLib declaration, UID0000UQ supplies the qualified member body, and UID0000RA supplies the singleton definition in the ItemObjImageLib source family. B002 adds no duplicate definition.
- UID0001H7 remains a semantic index and must not duplicate child code.
- by-file UID0000NL receives prose only; by-file roots must not receive reconstruction metadata.
- Rejected target placements: Config/RegistryConfig, ItemObjImageLib, UserStatusPane, a new render utility, or physical `.rdata` grouping. ItemObjImageLib remains a consumed dependency, not the target owner.
- Remaining placement uncertainty: only exact original filename spelling; it does not block the accepted route.

## Range / Split / Padding / Reclassification Analysis
- Exact target range remains `[0x00567480,0x00568bd0)`.
- `[0x00567480,0x00568bb4)` is source method body.
- `[0x00568bb4,0x00568bc8)` is the compiler jump table for the source nation `switch`.
- `[0x00568bc8,0x00568bd0)` is eight-byte `0xcc` alignment.
- No target split or new child is required.
- UID0003QV retains its range and UID but requires path/title rename only.
- UID0003QU and UID0003QW ranges remain exact.
- UID0001H7 remains non-emitting and gains source-ready inventory wording.

## Negative Evidence Summary
- No ordinary caller exists for UID0003QN; vtable dispatch explains liveness.
- No separate function exists at the target table or padding boundaries.
- UID0003QV has no palette, color, or text-color operation.
- UID0003QV has no null check; null formal calls are invalid.
- Shared comma literal xrefs cross unrelated source owners, defeating exclusive SelfLook ownership.
- No direct caller supports a free, static, `__stdcall`, or unqualified UID0000UQ source route; all 48 calls supply the ItemObjImageLib singleton receiver.
- A mere `class ItemObjImageLib;` forward declaration cannot make the member call compile-visible, and a duplicated local class declaration would violate the accepted single-owner source route. The include plus external singleton declaration is the bounded source-safe alternative.
- No binary helper supports extracting grouped-number rendering into another callable method.
- The active-view unsupported branch and enabled stats-button lookup-only tail are unusual but directly observed; apparent cleanup is rejected.
- No evidence supports handwritten vtable, RTTI, cookie, SEH, jump-table, or alignment source.

## IDA Rename / Type / Comment Recommendations
- Source-facing target: `SelfLookPane::OnPaint`.
- UID0003QU: `SelfLookPane::DrawNumberString`, return `void`, arguments `const wchar_t *`, `int`, `int`, `unsigned char`.
- UID0003QV: UID-preserving path/title rename from `SelfLookPaneGetSlotColors` to `SelfLookPaneGetSlotRect`; return `void`; `short slotId`; `RectBounds *bounds`; const member.
- UID0003QW: `SelfLookPane::HitTestSlot`, return `unsigned short`, arguments `int x`, `int y`, const member.
- External item helper: `ItemObjImageLib::GetItemGlyphBounds`, public nonvirtual `void(short itemId, RectBounds *outBounds)`, called as `g_pItemObjImageLib->GetItemGlyphBounds(...)`.
- Compile-visible dependency: `ItemObjImageLib.h` plus `extern ItemObjImageLib *g_pItemObjImageLib;` before the exact target definition; the singleton's sole initialized definition remains UID0000RA.
- Source-facing fields: `m_statDigitFrames`, accepted equipment arrays, `m_identityLine1`, `m_identityLine2`, `m_statusLineA`, `m_statusLineB`, `m_statusName`, accepted summary fields, `m_auxiliaryText`, `m_spelledSourceText`, `m_activeViewMode`, `m_serverRequestedViewMode`, `m_pendingMouseAction`, `m_pendingMouseView`, `m_viewCacheToggle`.
- `m_profilePane` at `+0x100` is inferred from exact sibling layout and field gap; it is not used by this target.
- Historical aliases retained only as superseded: unqualified/free/`__stdcall` `GetItemGlyphBounds`, `GetSlotColors`, `m_selfLookSlot5AlternateStyle`, `m_selfLookSlot6AlternateStyle`, and `LOOK.EPF`.
- No IDA DB edit is requested or authorized.

## First-Draft C++ Recommendation
- Eligible for draft C++: UID0003QN, UID0003QU, renamed UID0003QV, UID0003QW, UID0003QP, and UID0000CU. Owner-local data pages receive covered-by formal comments. Shared compiler/pooled items remain blank.
- Recommended code: Destinations 1-12 below are the exact destination-specific formal insertion text. Destination 1 includes the complete ItemObjImageLib interface dependency and external singleton declaration before the method; no prose-only sample, body-only substitute, free helper, duplicate class declaration, or duplicate singleton definition is intended.

### Destination 1 - UID0003QN target

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ItemObjImageLib.h"

extern ItemObjImageLib *g_pItemObjImageLib;

void SelfLookPane::OnPaint()
{
    EPFTileContext tileContext;
    EPFTileContext commaContext;
    EPFTileContext offButtonContext;
    EPFTileContext onButtonContext;
    RectBounds imageBounds;
    RectBounds slotBounds;
    RectBounds destinationBounds;
    RectBounds statBounds;
    wchar_t text[128];

    tileContext.Initialize();
    commaContext.Initialize();
    offButtonContext.Initialize();
    onButtonContext.Initialize();

    const wchar_t *backgroundPaletteName = L"ITEMINV.PAL";

    switch (m_activeViewMode) {
    case ViewMode_Default:
        backgroundPaletteName =
            m_viewCacheToggle ? L"LOOKEXT.PAL" : L"LOOKICON.PAL";
        g_pEPFLib->LookupLayoutEntry(
            m_viewCacheToggle ? L"LOOKEXT.EPF" : L"SELFLOOK.EPF",
            0,
            &tileContext);
        break;

    case ViewMode_Spelled:
        backgroundPaletteName =
            m_viewCacheToggle ? L"LOOKEXT.PAL" : L"LOOKICON.PAL";
        g_pEPFLib->LookupLayoutEntry(
            m_viewCacheToggle ? L"LOOKEXT.EPF" : L"SELFLOOK.EPF",
            1,
            &tileContext);
        break;

    case ViewMode_Legend:
        backgroundPaletteName =
            m_viewCacheToggle ? L"LOOKEXT.PAL" : L"LOOKICON.PAL";
        g_pEPFLib->LookupLayoutEntry(
            m_viewCacheToggle ? L"LOOKEXT.EPF" : L"SELFLOOK.EPF",
            2,
            &tileContext);
        break;

    default:
        g_pEPFLib->LookupLayoutEntry(L"COMMA.EPF", 0, &commaContext);
        break;
    }

    DLPalette *backgroundPalette =
        g_pPaletteLib->GetPaletteByName(backgroundPaletteName);
    g_pfnBlitSprite(this,
                    &tileContext,
                    &tileContext.bounds,
                    &m_bounds,
                    0,
                    backgroundPalette,
                    NULL);

    if (m_activeViewMode == ViewMode_Default) {
        const int highlightLeft[14] = {
            7, 63, 121, 7, 63, 121, 7,
            63, 121, 7, 63, 121, 7, 63
        };
        const int highlightTop[14] = {
            10, 10, 10, 62, 62, 62, 114,
            114, 114, 166, 166, 166, 218, 218
        };

        for (short slotId = SelfLookEquipmentSlot_FaceAccessory1;
             slotId <= SelfLookEquipmentSlot_Foot;
             ++slotId) {
            const unsigned short itemId =
                m_equipmentSlotItemIds[slotId];
            if (itemId == 0)
                continue;

            g_pItemObjImageLib->GetItemGlyphBounds(itemId, &imageBounds);
            GetSlotRect(slotId, &slotBounds);

            const int itemWidth = imageBounds.right - imageBounds.left;
            const int itemHeight = imageBounds.bottom - imageBounds.top;
            destinationBounds.left =
                (slotBounds.left + slotBounds.right) / 2 - itemWidth / 2;
            destinationBounds.right =
                destinationBounds.left + itemWidth;
            destinationBounds.top =
                (slotBounds.top + slotBounds.bottom) / 2 - itemHeight / 2;
            destinationBounds.bottom =
                destinationBounds.top + itemHeight;

            if (m_equipmentSlotHoverStates[slotId] == 1) {
                OffsetRect(&destinationBounds, -2, -2);

                const int highlightIndex =
                    slotId - SelfLookEquipmentSlot_FaceAccessory1;
                RectBounds highlightBounds;
                InitRectBounds(&highlightBounds,
                               highlightLeft[highlightIndex],
                               highlightTop[highlightIndex],
                               highlightLeft[highlightIndex] + 48,
                               highlightTop[highlightIndex] + 48);

                g_pEPFLib->LookupLayoutEntry(L"LOOKICON.EPF",
                                             highlightIndex,
                                             &tileContext);
                RenderTileFrame(&tileContext,
                                &tileContext.bounds,
                                &highlightBounds,
                                0,
                                L"LOOKICON.PAL",
                                NULL);
            }

            g_pItemObjImageLib->DrawItemImage(
                this,
                &destinationBounds,
                static_cast<short>(itemId),
                m_equipmentSlotRecordStates[slotId],
                NULL,
                0.0f);
        }

        g_pEPFLib->LookupLayoutEntry(L"ONOFFBUT.EPF",
                                     0,
                                     &offButtonContext);
        g_pEPFLib->LookupLayoutEntry(L"ONOFFBUT.EPF",
                                     1,
                                     &onButtonContext);

        GetSlotRect(SelfLookSlot_TopOption, &slotBounds);
        EPFTileContext *buttonContext =
            g_pConfig->m_selfLookTopButtonSelected
                ? &onButtonContext
                : &offButtonContext;
        RenderTileFrame(buttonContext,
                        &buttonContext->bounds,
                        &slotBounds,
                        0,
                        L"BUTTON.PAL",
                        NULL);

        GetSlotRect(SelfLookSlot_BottomOption, &slotBounds);
        buttonContext =
            g_pConfig->m_selfLookBottomButtonSelected
                ? &onButtonContext
                : &offButtonContext;
        RenderTileFrame(buttonContext,
                        &buttonContext->bounds,
                        &slotBounds,
                        0,
                        L"BUTTON.PAL",
                        NULL);

        g_pEPFLib->LookupLayoutEntry(
            L"INVENBUT.EPF",
            7 * m_pendingMouseAction + 6,
            &tileContext);
        GetSlotRect(SelfLookSlot_Next, &slotBounds);
        RenderTileFrame(&tileContext,
                        &tileContext.bounds,
                        &slotBounds,
                        0,
                        L"INVENBUT.PAL",
                        NULL);

        g_pEPFLib->LookupLayoutEntry(
            L"INVENBUT.EPF",
            7 * m_pendingMouseView + 5,
            &tileContext);
        GetSlotRect(SelfLookSlot_Previous, &slotBounds);
        RenderTileFrame(&tileContext,
                        &tileContext.bounds,
                        &slotBounds,
                        0,
                        L"INVENBUT.PAL",
                        NULL);

        GetSlotRect(SelfLookSlot_Face, &slotBounds);
        if (m_faceToggleState == ButtonVisualState_Disabled) {
            SetDrawColor(143);
            m_drawMode = 0;
            g_pfnFillRect(this, &slotBounds);
        } else {
            g_pEPFLib->LookupLayoutEntry(
                L"STATBUTS.EPF",
                m_faceToggleState ? 7 : 2,
                &tileContext);
            RenderTileFrame(&tileContext,
                            &tileContext.bounds,
                            &slotBounds,
                            0,
                            L"BUTTON.PAL",
                            NULL);
        }

        GetSlotRect(SelfLookSlot_Body, &slotBounds);
        if (m_bodyToggleState == ButtonVisualState_Disabled) {
            SetDrawColor(143);
            m_drawMode = 0;
            g_pfnFillRect(this, &slotBounds);
        } else {
            g_pEPFLib->LookupLayoutEntry(
                L"STATBUTS.EPF",
                m_bodyToggleState ? 8 : 3,
                &tileContext);
            RenderTileFrame(&tileContext,
                            &tileContext.bounds,
                            &slotBounds,
                            0,
                            L"BUTTON.PAL",
                            NULL);
        }

        GetSlotRect(SelfLookSlot_Stats, &slotBounds);
        if (m_statsToggleState == ButtonVisualState_Disabled) {
            SetDrawColor(143);
            m_drawMode = 0;
            g_pfnFillRect(this, &slotBounds);
            return;
        }

        g_pEPFLib->LookupLayoutEntry(
            L"STATBUTS.EPF",
            m_statsToggleState ? 9 : 4,
            &tileContext);
        return;
    }

    if (m_activeViewMode == ViewMode_Spelled) {
        SetTextColor(128);
        m_textDrawMode = 1;

        MoveTo(59, 25);
        SetTextColor(128);
        DrawWideText(m_identityLine1,
                     static_cast<int>(wcslen(m_identityLine1)));
        MoveTo(58, 24);
        SetTextColor(37);
        DrawWideText(m_identityLine1,
                     static_cast<int>(wcslen(m_identityLine1)));
        MoveTo(57, 24);
        DrawWideText(m_identityLine1,
                     static_cast<int>(wcslen(m_identityLine1)));

        MoveTo(59, 45);
        SetTextColor(128);
        DrawWideText(m_identityLine2,
                     static_cast<int>(wcslen(m_identityLine2)));
        MoveTo(58, 44);
        SetTextColor(37);
        DrawWideText(m_identityLine2,
                     static_cast<int>(wcslen(m_identityLine2)));
        MoveTo(57, 44);
        DrawWideText(m_identityLine2,
                     static_cast<int>(wcslen(m_identityLine2)));

        const int nationId = g_activeUserStatusPane->GetNationId();
        if (nationId != -1) {
            const wchar_t *nationText;
            switch (nationId) {
            case 0:
                nationText = L"Neutral";
                break;
            case 1:
                nationText = L"Koguryo";
                break;
            case 2:
                nationText = L"Buya";
                break;
            case 3:
                nationText = L"Nagnang";
                break;
            case 4:
                nationText = L"Han";
                break;
            default:
                nationText = L"";
                break;
            }

            wcscpy_s(text, 128, nationText);
            SetTextColor(128);
            MoveTo(64 - GetTextWidth(text) / 2, 86);
            DrawWideText(text, static_cast<int>(wcslen(text)));
            SetTextColor(37);
            MoveTo(64 - GetTextWidth(text) / 2, 85);
            DrawWideText(text, static_cast<int>(wcslen(text)));
            MoveTo(63 - GetTextWidth(text) / 2, 85);
            DrawWideText(text, static_cast<int>(wcslen(text)));
        }

        const int spiritId = g_activeUserStatusPane->GetSpiritId();
        if (spiritId != -1) {
            const wchar_t *spiritText;
            switch (spiritId) {
            case 0:
                spiritText = L"Ju jak";
                break;
            case 1:
                spiritText = L"Baekho";
                break;
            case 2:
                spiritText = L"Hyun moo";
                break;
            case 3:
                spiritText = L"Chung ryong";
                break;
            default:
                spiritText = L"";
                break;
            }

            wcscpy_s(text, 128, spiritText);
            SetTextColor(128);
            MoveTo(133 - GetTextWidth(text) / 2, 86);
            DrawWideText(text, static_cast<int>(wcslen(text)));
            SetTextColor(37);
            MoveTo(133 - GetTextWidth(text) / 2, 85);
            DrawWideText(text, static_cast<int>(wcslen(text)));
            MoveTo(132 - GetTextWidth(text) / 2, 85);
            DrawWideText(text, static_cast<int>(wcslen(text)));
        }

        InitRectBounds(&statBounds, 24, 120, 56, 132);
        if (m_exposedRegion.IntersectsRect(&statBounds)) {
            swprintf_s(text,
                       128,
                       L"%u",
                       static_cast<unsigned int>(
                           g_activeUserStatusPane->GetPercentStatA()));
            OffsetRect(&statBounds,
                       (statBounds.right -
                        static_cast<int>(9 * wcslen(text)) -
                        statBounds.left) /
                           2,
                       0);
            DrawNumberString(text,
                             statBounds.left,
                             statBounds.top,
                             1);
        }

        InitRectBounds(&statBounds, 83, 120, 115, 132);
        if (m_exposedRegion.IntersectsRect(&statBounds)) {
            swprintf_s(text,
                       128,
                       L"%u",
                       static_cast<unsigned int>(
                           g_activeUserStatusPane->GetPercentStatB()));
            OffsetRect(&statBounds,
                       (statBounds.right -
                        static_cast<int>(9 * wcslen(text)) -
                        statBounds.left) /
                           2,
                       0);
            DrawNumberString(text,
                             statBounds.left,
                             statBounds.top,
                             1);
        }

        InitRectBounds(&statBounds, 142, 120, 174, 132);
        if (m_exposedRegion.IntersectsRect(&statBounds)) {
            swprintf_s(text,
                       128,
                       L"%u",
                       static_cast<unsigned int>(
                           g_activeUserStatusPane->GetPercentStatC()));
            OffsetRect(&statBounds,
                       (statBounds.right -
                        static_cast<int>(9 * wcslen(text)) -
                        statBounds.left) /
                           2,
                       0);
            DrawNumberString(text,
                             statBounds.left,
                             statBounds.top,
                             1);
        }

#define DRAW_GROUPED_SELF_LOOK_NUMBER(VALUE, GLYPH_SET)                         \
        do {                                                                    \
            unsigned int groupedValue = (VALUE);                               \
            swprintf_s(text, 128, L"%10u", groupedValue);                      \
            const int textLength = static_cast<int>(wcslen(text));             \
            statBounds.right =                                                 \
                (statBounds.right + statBounds.left +                          \
                 9 * textLength + 15) / 2;                                     \
            statBounds.left = statBounds.right - 27;                           \
            statBounds.top =                                                   \
                (statBounds.top - 11 + statBounds.bottom) / 2 + 1;             \
            int digitCount = 0;                                                \
            while (groupedValue != 0 && digitCount < 10) {                     \
                ++digitCount;                                                  \
                groupedValue /= 10;                                            \
            }                                                                  \
            const int commaCount = (digitCount - 1) / 3;                       \
            OffsetRect(&statBounds, 0, -1);                                    \
            wchar_t group[4];                                                  \
            const wchar_t *groupStart = text + 7;                              \
            for (int groupIndex = 0; groupIndex < 3; ++groupIndex) {           \
                for (int copyPass = 0; copyPass < 3; ++copyPass) {             \
                    wcsncpy_s(group, 4, groupStart, 3);                         \
                    group[3] = L'\0';                                          \
                }                                                              \
                DrawNumberString(group,                                        \
                                 statBounds.left,                              \
                                 statBounds.top,                               \
                                 (GLYPH_SET));                                 \
                OffsetRect(&statBounds, -4, 6);                                \
                if (commaCount > groupIndex) {                                 \
                    RenderTileFrame(&commaContext,                             \
                                    &commaContext.bounds,                      \
                                    &statBounds,                               \
                                    1,                                         \
                                    L"COMMA.PAL",                              \
                                    NULL);                                     \
                }                                                              \
                OffsetRect(&statBounds, -27, -6);                              \
                groupStart -= 3;                                               \
            }                                                                  \
            wcsncpy_s(group, 4, text, 1);                                      \
            group[1] = L'\0';                                                  \
            OffsetRect(&statBounds, 18, 0);                                    \
            DrawNumberString(group,                                            \
                             statBounds.left,                                  \
                             statBounds.top,                                   \
                             (GLYPH_SET));                                     \
        } while (0)

        InitRectBounds(&statBounds, 50, 200, 179, 212);
        if (m_exposedRegion.IntersectsRect(&statBounds)) {
            DRAW_GROUPED_SELF_LOOK_NUMBER(
                g_activeUserStatusPane->GetDisplayValueA(),
                2);
        }

        InitRectBounds(&statBounds, 50, 220, 179, 232);
        if (m_exposedRegion.IntersectsRect(&statBounds)) {
            DRAW_GROUPED_SELF_LOOK_NUMBER(
                g_activeUserStatusPane->GetDisplayValueB(),
                2);
        }

        InitRectBounds(&statBounds, 0, 140, 110, 152);
        if (m_exposedRegion.IntersectsRect(&statBounds)) {
            swprintf_s(text,
                       128,
                       L"%d",
                       static_cast<signed char>(m_summaryTailByte0));
            statBounds.left =
                statBounds.right -
                static_cast<int>(9 * wcslen(text));
            DrawNumberString(text,
                             statBounds.left,
                             statBounds.top,
                             2);
        }

        swprintf_s(text,
                   128,
                   L"%d",
                   static_cast<signed char>(m_summaryTailByte1));
        InitRectBounds(&statBounds, 0, 160, 83, 172);
        if (m_exposedRegion.IntersectsRect(&statBounds)) {
            statBounds.left =
                statBounds.right -
                static_cast<int>(9 * wcslen(text));
            DrawNumberString(text,
                             statBounds.left,
                             statBounds.top,
                             2);
        }

        swprintf_s(text,
                   128,
                   L"%d",
                   static_cast<signed char>(m_summaryTailByte2));
        InitRectBounds(&statBounds, 0, 160, 168, 172);
        if (m_exposedRegion.IntersectsRect(&statBounds)) {
            statBounds.left =
                statBounds.right -
                static_cast<int>(9 * wcslen(text));
            DrawNumberString(text,
                             statBounds.left,
                             statBounds.top,
                             2);
        }

        InitRectBounds(&statBounds, 50, 180, 179, 192);
        if (m_exposedRegion.IntersectsRect(&statBounds)) {
            DRAW_GROUPED_SELF_LOOK_NUMBER(m_summaryTailValue, 0);
        }

#undef DRAW_GROUPED_SELF_LOOK_NUMBER

        InitRectBounds(&statBounds, 0, 175, 110, 187);
        if (m_exposedRegion.IntersectsRect(&statBounds) &&
            wcslen(m_auxiliaryText) > 7) {
            swprintf_s(text, 128, L"%s", m_auxiliaryText + 7);
            SetTextColor(128);
            MoveTo(58, 105);
            DrawWideText(text, static_cast<int>(wcslen(text)));
            SetTextColor(37);
            MoveTo(58, 104);
            DrawWideText(text, static_cast<int>(wcslen(text)));
            MoveTo(57, 104);
            DrawWideText(text, static_cast<int>(wcslen(text)));
        }
    } else if (m_activeViewMode != ViewMode_Legend) {
        return;
    }

    g_pEPFLib->LookupLayoutEntry(
        L"INVENBUT.EPF",
        7 * m_pendingMouseAction + 6,
        &tileContext);
    GetSlotRect(SelfLookSlot_Next, &slotBounds);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &slotBounds,
                    0,
                    L"INVENBUT.PAL",
                    NULL);

    g_pEPFLib->LookupLayoutEntry(
        L"INVENBUT.EPF",
        7 * m_pendingMouseView + 5,
        &tileContext);
    GetSlotRect(SelfLookSlot_Previous, &slotBounds);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &slotBounds,
                    0,
                    L"INVENBUT.PAL",
                    NULL);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2 - UID0003QU DrawNumberString

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SelfLookPane::DrawNumberString(const wchar_t *text,
                                    int x,
                                    int y,
                                    unsigned char glyphSet)
{
    EPFTileContext glyphContext;
    EPFTileContext symbolContext;
    RectBounds sourceBounds;
    RectBounds destinationBounds;

    glyphContext.Initialize();
    symbolContext.Initialize();
    glyphContext.rowStridePixels = 9;

    InitRectBounds(&sourceBounds, 0, 0, 9, 11);
    InitRectBounds(&destinationBounds, x, y, x + 9, y + 11);

    while (*text != L'\0') {
        if (*text == L'-') {
            g_pEPFLib->LookupLayoutEntry(L"FONTSYMB.EPF",
                                         4,
                                         &symbolContext);
            OffsetRect(&destinationBounds,
                       symbolContext.bounds.left,
                       symbolContext.bounds.top);
            RenderTileFrame(&symbolContext,
                            &symbolContext.bounds,
                            &destinationBounds,
                            1,
                            L"FONTSYMB.PAL",
                            NULL);
            OffsetRect(&destinationBounds,
                       -symbolContext.bounds.left,
                       -symbolContext.bounds.top);
        } else if (*text != L' ' && *text != L'/') {
            glyphContext.pixelData =
                m_statDigitFrames +
                99 * (*text + 10 * glyphSet - 47);
            g_pfnBlitSprite(this,
                            &glyphContext,
                            &sourceBounds,
                            &destinationBounds,
                            1,
                            NULL,
                            NULL);
        }

        ++text;
        OffsetRect(&destinationBounds, 9, 0);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3 - UID0003QV UID-preserving rename to SelfLookPaneGetSlotRect

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SelfLookPane::GetSlotRect(short slotId, RectBounds *bounds) const
{
    bool applyExtendedOffset = false;

    switch (slotId) {
    case SelfLookSlot_Face:
        if (m_activeViewMode == ViewMode_Default)
            InitRectBounds(bounds, 126, 228, 153, 255);
        else
            InitRectBounds(bounds, -1, -1, -1, -1);
        return;

    case SelfLookSlot_Body:
        if (m_activeViewMode == ViewMode_Default)
            InitRectBounds(bounds, 155, 228, 182, 255);
        else
            InitRectBounds(bounds, -1, -1, -1, -1);
        return;

    case SelfLookSlot_Stats:
        if (m_activeViewMode == ViewMode_Default)
            InitRectBounds(bounds, 126, 256, 153, 283);
        else
            InitRectBounds(bounds, -1, -1, -1, -1);
        return;

    case SelfLookSlot_Previous:
        if (m_activeViewMode == ViewMode_Spelled)
            InitRectBounds(bounds, 149, 268, 167, 286);
        else if (m_activeViewMode == ViewMode_Legend)
            InitRectBounds(bounds, 169, 268, 187, 286);
        else
            InitRectBounds(bounds, -1, -1, -1, -1);
        return;

    case SelfLookSlot_Next:
        if (static_cast<unsigned int>(m_activeViewMode) <
            static_cast<unsigned int>(ViewMode_Legend))
            InitRectBounds(bounds, 169, 268, 187, 286);
        else
            InitRectBounds(bounds, -1, -1, -1, -1);
        return;

    case SelfLookSlot_TopOption:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 107, 7, 121, 21);
        applyExtendedOffset = true;
        break;

    case SelfLookSlot_BottomOption:
        if (m_activeViewMode == ViewMode_Default)
            InitRectBounds(bounds, 49, 221, 63, 235);
        else
            InitRectBounds(bounds, -1, -1, -1, -1);
        return;

    case SelfLookEquipmentSlot_FaceAccessory1:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 12, 12, 60, 60);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_Head:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 68, 12, 116, 60);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_HeadAccessory2:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 126, 12, 174, 60);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_RightHand:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 10, 68, 58, 116);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_Body:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 68, 68, 116, 116);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_LeftHand:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 126, 68, 174, 116);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_RightAccessory:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 10, 122, 58, 170);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_Mantle:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 68, 122, 116, 170);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_LeftAccessory:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 126, 122, 174, 170);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_LeftSubAccessory:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 10, 174, 58, 222);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_Coat:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 68, 174, 116, 222);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_RightSubAccessory:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 126, 174, 174, 222);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_Necklace:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 10, 226, 58, 274);
        applyExtendedOffset = true;
        break;

    case SelfLookEquipmentSlot_Foot:
        if (m_activeViewMode != ViewMode_Default) {
            InitRectBounds(bounds, -1, -1, -1, -1);
            return;
        }
        InitRectBounds(bounds, 68, 226, 116, 274);
        applyExtendedOffset = true;
        break;

    default:
        InitRectBounds(bounds, -1, -1, -1, -1);
        return;
    }

    if (applyExtendedOffset && m_viewCacheToggle)
        OffsetRect(bounds, 2, 272);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4 - UID0003QW HitTestSlot

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
unsigned short SelfLookPane::HitTestSlot(int x, int y) const
{
    for (short slotId = SelfLookSlot_Face;
         slotId <= SelfLookEquipmentSlot_Foot;
         ++slotId) {
        RectBounds bounds;
        GetSlotRect(slotId, &bounds);
        if (PointInRect(x, y, &bounds))
            return static_cast<unsigned short>(slotId);
    }

    return 0xffff;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5 - UID0003QP corrected complete OnMouseClick formal

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SelfLookPane::OnMouseClick(const PanelMouseEvent *event)
{
    const unsigned short slotId = HitTestSlot(event->x, event->y);

    if (event->button == PanelMouseButton_Right) {
        if (g_pSelfLookPopupPane != NULL)
            g_pSelfLookPopupPane->Close(1);

        switch (slotId) {
        case SelfLookSlot_Face:
            ShowSelfLookHelpPopup(197, event->x, event->y);
            return true;
        case SelfLookSlot_Body:
            ShowSelfLookHelpPopup(198, event->x, event->y);
            return true;
        case SelfLookEquipmentSlot_FaceAccessory1:
        case SelfLookEquipmentSlot_Head:
        case SelfLookEquipmentSlot_HeadAccessory2:
        case SelfLookEquipmentSlot_RightHand:
        case SelfLookEquipmentSlot_Body:
        case SelfLookEquipmentSlot_LeftHand:
        case SelfLookEquipmentSlot_RightAccessory:
        case SelfLookEquipmentSlot_Mantle:
        case SelfLookEquipmentSlot_LeftAccessory:
        case SelfLookEquipmentSlot_LeftSubAccessory:
        case SelfLookEquipmentSlot_Coat:
        case SelfLookEquipmentSlot_RightSubAccessory:
        case SelfLookEquipmentSlot_Necklace:
        case SelfLookEquipmentSlot_Foot:
            if (m_equipmentSlotItemIds[slotId] != 0)
                ShowEquipmentSlotTooltip(slotId, event->x, event->y);
            return true;
        default:
            return false;
        }
    }

    if (event->button == PanelMouseButton_Left) {
        if (g_pCollectionData->IsInteractionLocked())
            return true;

        switch (slotId) {
        case SelfLookSlot_Face: {
            if (m_faceToggleState == ButtonVisualState_Disabled)
                return true;
            m_faceToggleState = !m_faceToggleState;
            SendSelfLookOptionRequest(0x08);
            RectBounds changedBounds;
            GetSlotRect(SelfLookSlot_Face, &changedBounds);
            break;
        }

        case SelfLookSlot_Body: {
            if (m_bodyToggleState == ButtonVisualState_Disabled)
                return true;
            m_bodyToggleState = !m_bodyToggleState;
            SendSelfLookOptionRequest(0x02);
            RectBounds changedBounds;
            GetSlotRect(SelfLookSlot_Body, &changedBounds);
            break;
        }

        case SelfLookSlot_Previous:
            if (m_activeViewMode == ViewMode_Legend)
                ShowSpelledView();
            else if (m_activeViewMode == ViewMode_Spelled)
                ResetAndRefresh();
            m_pendingMouseAction = 0;
            m_pendingMouseView = 2;
            InvalidateRect(&m_bounds);
            return true;

        case SelfLookSlot_Next:
            if (m_activeViewMode == ViewMode_Default)
                ShowSpelledView();
            else if (m_activeViewMode == ViewMode_Spelled)
                DeactivateView();
            m_pendingMouseAction = 2;
            m_pendingMouseView = 0;
            InvalidateRect(&m_bounds);
            return true;

        case SelfLookSlot_TopOption:
            g_pGeneralPurposePanel->GetActiveChildPane(6);
            SendSelfLookPanelCommand(14);
            return true;

        case SelfLookSlot_BottomOption:
            g_pGeneralPurposePanel->GetActiveChildPane(6);
            SendSelfLookPanelCommand(15);
            return true;

        case SelfLookEquipmentSlot_Head:
            SendTakeOffPacket(4);
            return true;
        case SelfLookEquipmentSlot_Body:
            SendTakeOffPacket(2);
            return true;
        case SelfLookEquipmentSlot_LeftHand:
            SendTakeOffPacket(3);
            return true;
        case SelfLookEquipmentSlot_RightHand:
            SendTakeOffPacket(1);
            return true;
        case SelfLookEquipmentSlot_FaceAccessory1:
            SendTakeOffPacket(22);
            return true;
        case SelfLookEquipmentSlot_LeftAccessory:
            SendTakeOffPacket(7);
            return true;
        case SelfLookEquipmentSlot_RightAccessory:
            SendTakeOffPacket(8);
            return true;
        case SelfLookEquipmentSlot_LeftSubAccessory:
            SendTakeOffPacket(20);
            return true;
        case SelfLookEquipmentSlot_RightSubAccessory:
            SendTakeOffPacket(21);
            return true;
        case SelfLookEquipmentSlot_HeadAccessory2:
            SendTakeOffPacket(23);
            return true;
        case SelfLookEquipmentSlot_Mantle:
            SendTakeOffPacket(14);
            return true;
        case SelfLookEquipmentSlot_Necklace:
            SendTakeOffPacket(6);
            return true;
        case SelfLookEquipmentSlot_Foot:
            SendTakeOffPacket(13);
            return true;
        case SelfLookEquipmentSlot_Coat:
            SendTakeOffPacket(16);
            return true;
        default:
            return false;
        }

        m_lastSelfLookOptionTick = g_clientTickCounter->m_tickCount;
        return true;
    }

    if (event->button != PanelMouseButton_Move)
        return false;

    if (!PointInRect(event->x, event->y, &m_bounds)) {
        m_pendingMouseAction = 0;
        m_pendingMouseView = 0;
        return false;
    }

    UpdateHoverButtonState(event->x, event->y);
    m_hoverSlotStateValue = 0;
    m_hoverSlotStateValue2 = 0;
    m_hoverSlotStateFlag = 0;

    if (m_activeViewMode == ViewMode_Default) {
        const unsigned short hoverSlot =
            HitTestSlot(event->x, event->y);
        if (hoverSlot != 0xffff &&
            hoverSlot >= SelfLookEquipmentSlot_FaceAccessory1 &&
            hoverSlot <= SelfLookEquipmentSlot_Foot) {
            if (g_selfLookLastHoverEquipmentSlotId != hoverSlot) {
                m_hoverTimer.RemovePendingTimers();
                m_hoverTimer.ScheduleTimer(hoverSlot,
                                           1000,
                                           event->y,
                                           event->x);
            }
            g_selfLookLastHoverEquipmentSlotId = hoverSlot;
            m_equipmentSlotHoverStates[hoverSlot] = true;
            InvalidateRect(&m_bounds);
        }
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 6 - UID0000CU complete SelfLookPane declaration/layout union

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SelfLookPane : public PanelPane
{
public:
    enum ViewMode
    {
        ViewMode_Default = 0,
        ViewMode_Spelled = 1,
        ViewMode_Legend = 2
    };

    enum SlotId
    {
        SelfLookSlot_Face = 0,
        SelfLookSlot_Body = 1,
        SelfLookSlot_Stats = 2,
        SelfLookSlot_Previous = 3,
        SelfLookSlot_Next = 4,
        SelfLookSlot_TopOption = 5,
        SelfLookSlot_BottomOption = 6,
        SelfLookEquipmentSlot_FaceAccessory1 = 7,
        SelfLookEquipmentSlot_Head = 8,
        SelfLookEquipmentSlot_HeadAccessory2 = 9,
        SelfLookEquipmentSlot_RightHand = 10,
        SelfLookEquipmentSlot_Body = 11,
        SelfLookEquipmentSlot_LeftHand = 12,
        SelfLookEquipmentSlot_RightAccessory = 13,
        SelfLookEquipmentSlot_Mantle = 14,
        SelfLookEquipmentSlot_LeftAccessory = 15,
        SelfLookEquipmentSlot_LeftSubAccessory = 16,
        SelfLookEquipmentSlot_Coat = 17,
        SelfLookEquipmentSlot_RightSubAccessory = 18,
        SelfLookEquipmentSlot_Necklace = 19,
        SelfLookEquipmentSlot_Foot = 20
    };

    enum ButtonVisualState
    {
        ButtonVisualState_Disabled = 0xff
    };

    SelfLookPane();
    virtual ~SelfLookPane();

    virtual void OnReceiveCharacterData(const unsigned char *packet);
    virtual void OnPaint();
    virtual bool OnMouseClick(const PanelMouseEvent *event);
    virtual bool OnKeyPress(Event *event);
    virtual bool OnPacketEvent(const PanelPacketEvent *event);
    virtual bool OnShowHelp(void *helpContext, int x, int y);
    virtual void OnGetRect(RectBounds *bounds);
    virtual int OnTransformRect(RectBounds *bounds, int transformMode);

    void RefreshSpelledPane();
    void ResetAndRefresh();
    void ActivateView();
    void ShowSpelledView();
    void DeactivateView();

    void DrawNumberString(const wchar_t *text,
                          int x,
                          int y,
                          unsigned char glyphSet);
    void GetSlotRect(short slotId, RectBounds *bounds) const;
    unsigned short HitTestSlot(int x, int y) const;

    bool SendSelfLookOptionRequest(unsigned char optionSubtype);
    void SendSelfLookOption02Raw();
    void SendSelfLookOption08Raw();
    void SendSelfLookOption0bRaw();

    bool ApplySelfLookRectRecord(const unsigned char *packet);
    bool ApplySelfLookRectStateRecord(const unsigned char *packet);
    bool ApplyEquipmentSlotRecord(const unsigned char *packet);
    bool ClearEquipmentSlotRecord(const unsigned char *packet);
    bool ApplySelfLookSummaryRecord(const unsigned char *packet);
    bool DispatchSpelledText(const unsigned char *packet);
    void ToggleSelfLookViewCache();

private:
    unsigned char *m_statDigitFrames;
    SpelledPane *m_spelledPane;
    ProfilePane *m_profilePane;
    LegendPane *m_legendPane;
    ObjectStatusBlob m_selfLookObjectStatus;

    unsigned short m_equipmentSlotItemIds[21];
    unsigned char m_equipmentSlotRecordStates[21];
    wchar_t m_equipmentSlotNames[21][64];
    wchar_t m_equipmentSlotDescriptions[21][64];
    unsigned int m_equipmentSlotValues[21];
    unsigned char m_equipmentSlotValueFlags[21];
    unsigned char m_equipmentSlotHoverStates[21];

    wchar_t m_identityLine1[256];
    wchar_t m_identityLine2[256];
    wchar_t m_statusLineA[256];
    wchar_t m_statusLineB[128];
    wchar_t m_statusName[128];
    unsigned int m_summaryCompareKey0;
    unsigned int m_summaryCompareKey1;
    unsigned char m_summaryTailByte0;
    unsigned char m_summaryTailByte1;
    unsigned char m_summaryTailByte2;
    unsigned int m_summaryTailValue;
    unsigned int m_lastSelfLookOptionTick;
    unsigned int m_selfLookOptionRepeatDelay;
    unsigned char m_bodyToggleState;
    unsigned char m_faceToggleState;
    unsigned char m_statsToggleState;
    wchar_t m_auxiliaryText[256];
    wchar_t m_spelledSourceText[256];
    int m_activeViewMode;
    int m_serverRequestedViewMode;
    int m_reservedViewState;
    int m_pendingMouseAction;
    int m_pendingMouseView;
    unsigned char m_viewCacheToggle;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 7 - UID0003EU SelfLookPaneLookResourceStrings covered-by marker

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Covered by the LOOKEXT.EPF, LOOKEXT.PAL, SELFLOOK.EPF, and
// LOOKICON.PAL use-site literals in SelfLookPane::OnPaint().
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 8 - UID0003EW SelfLookPaneLookIconNationStrings covered-by marker

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Covered by the LOOKICON.EPF, STATBUTS.EPF, nation-name, and
// spirit-name use-site literals in SelfLookPane::OnPaint().
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 9 - UID0003F7 SelfLookPaneRectConstantsA covered-by marker

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Covered by SelfLookPane::OnPaint() local highlightLeft coordinates.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 10 - UID0003F9 SelfLookPaneRectConstantB covered-by marker

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Covered by SelfLookPane::OnPaint() local highlightTop coordinates.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 11 - UID0003FB SelfLookPaneRectConstantsC covered-by marker

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Covered by SelfLookPane::OnPaint() local highlightLeft and
// highlightTop coordinate arrays.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 12 - UID0002RG view-cache helper field/layout synchronization

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SelfLookPane::ToggleSelfLookViewCache()
{
    m_viewCacheToggle = m_viewCacheToggle == 0;

    OnViewCacheToggleChanged();

    RectBounds attachRect;
    GetChildAttachRect(&attachRect, 0);
    AttachToLayer(&attachRect, 0, g_pBackPane, MainUiLayerSlots);
    InvalidateRect(&m_bounds);

    if (m_activeViewMode == ViewMode_Default) {
        memset(m_equipmentSlotHoverStates +
                   SelfLookEquipmentSlot_FaceAccessory1,
               0,
               SelfLookEquipmentSlot_Foot -
                   SelfLookEquipmentSlot_FaceAccessory1 + 1);
        m_identityLine1[0] = L'\0';
    } else if (m_activeViewMode == ViewMode_Legend) {
        m_legendPane->RefreshScrollState();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason the formal source preserves behavior:
  - it retains every observed mode branch, resource/frame choice, item loop, hover grid, toggle path, exact text/stat rectangle, grouped-number operation, comma path, invalid/default path, and unusual early return;
  - it preserves the exact item-glyph helper operation while correcting only the source receiver to the accepted `g_pItemObjImageLib` singleton member route;
  - it retains the mode-1 initialized-but-unloaded comma context and unsupported-mode initialized-background blit;
  - Destination 12 preserves the exact mode-zero stores as the 14 visible hover bytes plus the first identity-line wchar without inventing four class fields;
  - it does not handwrite compiler table/cookie/padding/vtable output.
- Reason it matches plausible source-era C++:
  - ordinary C++03 class methods, enums, fixed arrays, stack contexts, local `const` coordinate arrays, and a local macro fit the binary and the accepted sibling style;
  - a normal ItemObjImageLib header include plus an external singleton declaration supplies compile visibility without duplicating class or global definitions;
  - no decompiler labels, raw receiver arithmetic, or modern language feature remains.
- Inferred source-facing names/types are descriptive and evidence-bound. Exact original lexical spellings are not claimed.
- Third-party import directive: not applicable.

## Final Recommendation
- Destinations 1-12 are applied byte-for-byte at their accepted ordinary pages. Scores, owner/emitter/reconstructable/range/Nested/position dispositions match the accepted matrix.
- UID0003QV is uniquely registered at `by-memory/0x00569ed0-0x0056a300.SelfLookPaneGetSlotRect.md`; the old path is absent.
- UID0001H7 is `89/92`, false/non-emitting with complete source-ready child inventory; UID0000NL is `93/94`, prose-only, with the full current SelfLookPane/SelfLookPane2 union.
- UID0002UY, Config UID000031, and pooled UID0003EV/UID0003EX were verified unchanged.
- UID0003QE current prose names `GetSlotRect` while retaining its independent `85/89` raw-helper metadata and blank formal.
- The centralized B005 archive and all five ItemObjImageLib dependency ordinary hashes remain unchanged; B005 remains sole owner of the member declaration/definition/global route.
- Final waited command `13965` proves the complete generated target/helper/class/dependency contract. No generated file was edited manually.
- Exact items left non-emitting: UID0001H7 broad index, target/helper switch tables and alignment, shared comma literal pages, vtable/RTTI bytes, stack cookie, and compiler lowering.
- No additional target or duplicate report is warranted.

## Recommended Target Doc Changes
- Target path: `by-memory/0x00567480-0x00568bd0.SelfLookPaneOnPaint.md`.
- Exact facts incorporated:
  - all range, byte, hash, instruction, CFG, stack, ABI, caller, callee, vtable, resource, field, mode, loop, switch, rectangle, color, font, failure/default, and compiler-boundary evidence in this report;
  - exact Destination 1 formal, including `#include "ItemObjImageLib.h"`, the external singleton declaration, and `g_pItemObjImageLib->GetItemGlyphBounds(itemId, &imageBounds);`;
  - accepted B005 receiver/member evidence and the explicit rejection of the free/unqualified helper route;
  - exact historicalization of the prior blank-C++ and alternate-style assumptions.
- Metadata:
  - `93/94`;
  - owner/emitter UID0000CU unchanged;
  - reconstructable true unchanged;
  - blank optional position unchanged;
  - Nested 0 unchanged.
- Item Summary replacement:
  - `Source-ready virtual SelfLookPane::OnPaint with exact 5,940-byte body, nation switch table and padding, three view modes, SELFLOOK/LOOKEXT backgrounds, equipment/hover/button rendering, ItemObjImageLib singleton-member glyph bounds, identity/nation/spirit/stat/grouped-number paths, exact resources/fields/helpers, compiler exclusions, and complete formal C++.`

## Recommended Support Doc Changes
- `by-memory/0x00569d80-0x00569ec1.SelfLookPaneDrawNumberString.md`:
  - apply Destination 2, `92/93`, exact hash/instruction/CFG/xrefs, `m_statDigitFrames`, 9x11/99-byte/glyph-set/symbol behavior, and source-void ABI.
- UID0003QV current path:
  - UID-preserving rename applied to `by-memory/0x00569ed0-0x0056a300.SelfLookPaneGetSlotRect.md`;
  - Destination 3, `92/94`, hashes/CFG/callers/slot map/offset exceptions applied;
  - all directly affected current source-facing links/spellings reconciled; historical rejected-name text remains explicitly historical.
- `by-memory/0x0056a300-0x0056a373.SelfLookPaneHitTestSlot.md`:
  - Destination 4 and `91/93` applied.
- `by-memory/0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick.md`:
  - Destination 5 and `90/92` applied;
  - preserve all accepted take-off, hover, timer, packet, and view behavior.
- `by-class/SelfLookPane.md`:
  - Destination 6 and `93/94` applied;
  - preserve all accepted B004/B005/B006/B007/B011 methods/evidence;
  - synchronize exact field layout, helper names, method inventory, source ordering, compiler exclusions, and `[[CHILDREN]]` placement.
- `by-memory/0x0056b9f0-0x0056ba99.SelfLookPaneViewToggleRaw.md`:
  - set `89/92`;
  - Destination 12 applied;
  - four artificial `m_cachedLookState*` aliases replaced by exact hover-slot plus first-identity-wchar clear evidence while retaining raw-start no-xref and cookie/padding facts.
- `by-memory/0x00565610-0x0056a373.SelfLookPane.md`:
  - `89/92`, same false/non-emitting metadata, complete source-ready child inventory, corrected QV path/name, and no duplicate source.
- `by-file/SelfLookPane.md`:
  - `93/94`, prose only;
  - add the complete UID0003QN/QU/QV/QW/QP union, resource/data covered-by disposition, source order, ItemObjImageLib header/singleton dependency, generated expectations, and retained SelfLookPane2/shared child content;
  - record probable original top-of-translation-unit `ItemObjImageLib.h` placement as prose only; do not add by-file reconstruction metadata.
- UID0003EU:
  - `90/92`, exact `SELFLOOK.EPF`, Destination 7 applied.
- UID0003EW:
  - `90/92`, Destination 8 applied.
- UID0003F7/F9/FB:
  - `90/92`, Destinations 9-11 applied.
- Directly affected link/prose pages:
  - current source-facing `GetSlotColors` spelling/path references in UID0003QN, UID0003QE, UID0003QP, UID0003QW, UID0001H7, and UID0000CU are reconciled; UID0003QV contains Destination 3;
  - leave historical `by-memory/-report.old.md` untouched as stale generated history;
  - preserve all other behavior and scores unless a concrete current contradiction requires a bounded score/prose update.
- Verify-only:
  - UID0002UY vtable page;
  - Config UID000031 and RegistryConfig file;
  - UID0003EV/UID0003EX pooled comma pages;
  - accepted UserStatusPane, GrafPort, EPFTileContext, RectBounds, Palette, resource-library, and SelfLookPane2 pages;
  - B005-owned UID0000UQ, ItemObjImageLib layout/class/file, and `g_pItemObjImageLib` under the current centralized executed archive. They are direct coordination dependencies, not unrelated support and not B002 edit destinations.

## Score And Metadata Recommendation
| Item | Before callback | Applied | Metadata disposition |
| --- | ---: | ---: | --- |
| UID0003QN | `86/90` | `93/94` | owner/emitter true route retained; blank position; exact formal |
| UID0003QU | `85/89` | `92/93` | owner/emitter retained; exact formal |
| UID0003QV | `86/90` | `92/94` | UID-preserving rename; owner/emitter retained; exact formal |
| UID0003QW | `85/90` | `91/93` | owner/emitter retained; exact formal |
| UID0003QP | `88/91` | `90/92` | owner/emitter/formal route retained; corrected full formal |
| UID0002RG | `87/90` | `89/92` | owner/emitter retained; exact formal field/layout correction |
| UID0000CU | `89/91` | `93/94` | owner UID0000NL/emitter retained; complete declaration |
| UID0001H7 | `88/91` | `89/92` | semantic owner retained; false/non-emitting/blank formal retained |
| UID0000NL | `92/94` | `93/94` | FILE root/path retained; prose only |
| UID0003EU/EW/F7/F9/FB | `85/88` | `90/92` | owner/emitter retained; covered-by formal |
| UID0000UQ / UID0001UU / UID00006W / UID0000KH / UID0000RA | current executed B005 implementation state | unchanged by B002 | verify/coordination only; member declaration/body/global ownership remains singular |
- Reason not higher:
  - exact original private member names and access sections are unrecovered;
  - the source-level macro spelling and the purpose behind a few deliberate quirks are inferred;
  - exact historical file naming remains inferred.
- Score-blocker audit:
  - full body: resolved through complete decompile/control-flow reconstruction;
  - switch ownership: resolved to nation source switch;
  - ABI/return: resolved through vtable/sibling/call-result evidence;
  - helper signatures: resolved through exact callees/callers/field effects;
  - resource names: resolved through direct UTF-16 bytes;
  - fields/layout: resolved through constructor/parser/sibling natural layout;
  - rectangle constants: resolved through direct packed values and stack-copy use;
  - source placement: resolved to existing class/file route;
  - item-glyph receiver/ownership: resolved to public nonvirtual ItemObjImageLib member by exhaustive 48-call receiver evidence;
  - cross-module compile visibility: resolved by exact Destination 1 include plus external singleton declaration, with sole declaration/body/global ownership retained in the B005 ItemObjImageLib family;
  - B005 dependency implementation: resolved by stable ordinary hashes, bounded commands `13821`/`13822`, and final waited command `13823` generated readback;
  - generated blocker: closed by final waited command `13965`.

## Open Questions With Attempted Resolution
| Question | Checks | Resolution | Score/C++ impact |
| --- | --- | --- | --- |
| Is OnPaint `int` or `void`? | prototype, ret, vtable, sibling slot, ignored results | `void` | closed |
| Does the target tail need a data declaration? | table bytes, xref, case targets | no; compiler nation switch table | closed |
| What is UID0003QV? | complete decompile, callees, callers | `GetSlotRect`, no color behavior | closed |
| Does extended layout move slot 6? | case-specific control flow | no; slot 5 and 7..20 only | closed |
| Can UID0003QP pass null? | helper entry and all binary callers | no; use local RectBounds | closed |
| Is DrawNumberString bool-selected? | all twelve calls and formula | no; unsigned char glyph set 0..2 | closed |
| What are the Config fields? | parser bits, exact Config layout, paint geometry | accepted top/bottom selected names | closed |
| What source represents packed constants? | local stack copies, values, use | two local const arrays | closed |
| Who owns comma literals? | cross-owner xrefs | pooled NONE/FALSE pages; use-site literals | closed |
| Why no source draw for enabled stats button? | exact branch/tail | observed lookup-only return preserved | closed |
| What is the `+0x100` field? | exact gap, sibling layout, constructor absence | `ProfilePane *m_profilePane` is strongest descriptive inference; unused here | confidence cap only |
| Are UID0002RG's four cache fields real members? | target hover reads, parser text start, constructor zeroing, exact raw dword stores | no; source clears hover slots 7..20 and `m_identityLine1[0]` | closed |
| Is GetItemGlyphBounds a free helper, SelfLookPane member, or ItemObjImageLib member? | all 48 direct callers, hidden ECX receiver, result-use audit, current UID0000UQ/layout/class/file | public nonvirtual `ItemObjImageLib` member | closed |
| How does SelfLookPane compile against that member without duplicate ownership? | by-file emitter restrictions, current ItemObjImageLib header route, global definition route, accepted cross-TU patterns | Destination 1 includes `ItemObjImageLib.h`, declares the singleton external, and calls through `g_pItemObjImageLib`; B005 retains sole class/member/global source | closed |
| Does B002 need to edit ItemObjImageLib pages? | current centralized B005 archive and stable ordinary/generated readback | no; verify/coordinate only unless a concrete post-execution contradiction appears | closed |
- No investigable blocker remains unresolved.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Final read-only manual snapshots:
  - `by-memory/-coverage-report.md`: SHA256 `6C2F436736E4BA86639EB767A538B96E9018AEE22CF2E64283B512AA494DE117`, 1,762,192 bytes / 4,232 lines. This supervisor-owned file advanced after the callback because of unrelated current-union activity; direct reread confirms the fifteen B002-scoped dispositions are unchanged: UID0001H7 remains the stale `82%` reconstructable aggregate row, UID0002RG remains the stale `84%` unassigned/raw row, and the target/helper/data rows are absent.
  - `by-class/-coverage-report.md`: SHA256 `A4AE36910FCFD2616E30F92B792DC390DC8AEB9D1980E1214FB525C68ED369AC`, 228,369 bytes / 622 lines. UID0000CU remains the stale `89%` row.
  - `by-file/-coverage-report.md`: SHA256 `DAB064BFC53369EA708D0EEDFF45D1C82EBFCC0C124D063B879A6314ADDCFBA8`, 131,070 bytes / 316 lines. UID0000NL remains the stale `92%` row.
- No `by-struct/-coverage-report.md` exists. No affected by-type manual row requires change because UID0002UY remains unchanged.
- B005's ItemObjImageLib metadata/member correction has its own exact supervisor-owned coverage handoff. B002 supplies no duplicate UID0000UQ/layout/class/file/global row; the fifteen SelfLookPane rows below remain byte-for-byte the accepted B002 handoff.
- `auto-generated/-ag-research-tracker.md` is validator-owned queue/output state, so no hand-edited tracker row is supplied. The target page `Item Summary` replacement above is the correct source input for generated by-memory coverage.
- File/placement: replace the current UID0001H7 plus UID0003QH block in `by-memory/-coverage-report.md` with this exact no-loss block:

```text
    - [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](by-memory/0x00565610-0x0056a373.SelfLookPane.md) 0x00565610-0x0056a373 | non-emitting class split index | SelfLookPane : not_reconstructable : 89% : very-strong : Complete SelfLookPane method/raw/data/padding index with exact child ranges, source-ready OnPaint/DrawNumberString/GetSlotRect/HitTestSlot support, packet/view/input children, class/file ownership, compiler switch exclusions, and no duplicate aggregate source.
        - [UID:0003QH][0x005671c0-0x005671de.SelfLookPaneRefreshSpelledPane](by-memory/0x005671c0-0x005671de.SelfLookPaneRefreshSpelledPane.md) 0x005671c0-0x005671de | SelfLookPane member | SelfLookPaneRefreshSpelledPane : reconstructable : 89% : very-strong : Exact 30-byte SelfLookPane SpelledPane refresh wrapper with receiver field +0xfc, FrameHandler remove-then-schedule behavior represented by RefreshScrollState, two UID0003UN branch callers, exact SHA256, and complete source C++.
        - [UID:0003QN][0x00567480-0x00568bd0.SelfLookPaneOnPaint](by-memory/0x00567480-0x00568bd0.SelfLookPaneOnPaint.md) 0x00567480-0x00568bd0 | virtual paint method plus compiler tail | SelfLookPaneOnPaint : reconstructable : 93% : very-strong : Complete SelfLookPane OnPaint source with exact body/table/padding hashes, three view modes, SELFLOOK/LOOKEXT backgrounds, equipment/hover/toggle/navigation drawing, identity/nation/spirit/stats/grouped-number paths, exact helpers/resources/fields, and compiler exclusions.
        - [UID:0003QP][0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick](by-memory/0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick.md) 0x00568cb0-0x005693d0 | virtual mouse method plus compiler tail | SelfLookPaneOnMouseClick : reconstructable : 90% : very-strong : Complete click/move/take-off/hover/timer body with corrected GetSlotRect stack outputs, exact slot/view/action branches, and no invalid null rectangle calls.
        - [UID:0003QU][0x00569d80-0x00569ec1.SelfLookPaneDrawNumberString](by-memory/0x00569d80-0x00569ec1.SelfLookPaneDrawNumberString.md) 0x00569d80-0x00569ec1 | numeric glyph helper | SelfLookPaneDrawNumberString : reconstructable : 92% : very-strong : Exact void 9x11 numeric renderer with 99-byte glyph frames, glyph sets 0-2, FONTSYMB minus handling, space/slash skip, unconditional 9-pixel advance, twelve OnPaint callers, and complete source C++.
        - [UID:0003QV][0x00569ed0-0x0056a300.SelfLookPaneGetSlotRect](by-memory/0x00569ed0-0x0056a300.SelfLookPaneGetSlotRect.md) 0x00569ed0-0x0056a300 | slot rectangle helper plus compiler tail | SelfLookPaneGetSlotRect : reconstructable : 92% : very-strong : Exact 21-slot/mode rectangle map with all-minus-one invalid output, extended-layout offset for slot 5 and slots 7-20 but not slot 6, eighteen callers, owned compiler switch data, and complete source C++.
        - [UID:0003QW][0x0056a300-0x0056a373.SelfLookPaneHitTestSlot](by-memory/0x0056a300-0x0056a373.SelfLookPaneHitTestSlot.md) 0x0056a300-0x0056a373 | slot hit-test helper | SelfLookPaneHitTestSlot : reconstructable : 91% : very-strong : Exact 21-slot GetSlotRect/PointInRect loop returning the first slot or 0xffff, three OnMouseClick callers, exact hash/CFG, and complete source C++.
```

- File/placement: replace the current UID0002RG row beneath UID00023V in `by-memory/-coverage-report.md` with:

```text
        - [UID:0002RG][0x0056b9f0-0x0056ba99.SelfLookPaneViewToggleRaw](by-memory/0x0056b9f0-0x0056ba99.SelfLookPaneViewToggleRaw.md) 0x0056b9f0-0x0056ba99 | raw view/cache helper | SelfLookPaneViewToggleRaw : reconstructable : 89% : very-strong : Exact source-shaped view-cache toggle with raw-start/no-xref caveat, view-byte flip, pane/layer/invalidation calls, mode-zero clear of hover slots 7..20 plus the first identity-line wchar, mode-two LegendPane refresh, cookie/padding exclusions, and corrected source C++ without artificial cached-look fields.
```

- File/placement: beneath UID0002V2 in `by-memory/-coverage-report.md`, insert:

```text
            - [UID:0003EU][0x00624788-0x006247f0.SelfLookPaneLookResourceStrings](by-memory/0x00624788-0x006247f0.SelfLookPaneLookResourceStrings.md) 0x00624788-0x006247f0 | source-local resource literals | SelfLookPaneLookResourceStrings : reconstructable : 90% : very-strong : Exact LOOKEXT.EPF/LOOKEXT.PAL/SELFLOOK.EPF/LOOKICON.PAL bytes and SelfLook-family xrefs, represented by SelfLookPane::OnPaint use-site literals with a formal covered-by marker.
            - [UID:0003EW][0x00624804-0x006248cc.SelfLookPaneLookIconNationStrings](by-memory/0x00624804-0x006248cc.SelfLookPaneLookIconNationStrings.md) 0x00624804-0x006248cc | source-local resource/text literals | SelfLookPaneLookIconNationStrings : reconstructable : 90% : very-strong : Exact LOOKICON.EPF/STATBUTS.EPF plus nation/spirit strings, all target-local by xref and represented by OnPaint use-site literals with a formal covered-by marker.
            - [UID:0003F7][0x00624be0-0x00624bf0.SelfLookPaneRectConstantsA](by-memory/0x00624be0-0x00624bf0.SelfLookPaneRectConstantsA.md) 0x00624be0-0x00624bf0 | source-local packed constants | SelfLookPaneRectConstantsA : reconstructable : 90% : very-strong : Exact [7,63,121,7] hover-grid coordinates, one OnPaint xref, and formal covered-by representation through the local highlightLeft array.
            - [UID:0003F9][0x00624c00-0x00624c10.SelfLookPaneRectConstantB](by-memory/0x00624c00-0x00624c10.SelfLookPaneRectConstantB.md) 0x00624c00-0x00624c10 | source-local packed constants | SelfLookPaneRectConstantB : reconstructable : 90% : very-strong : Exact [10,10,10,62] hover-grid coordinates, one OnPaint xref, and formal covered-by representation through the local highlightTop array.
            - [UID:0003FB][0x00624c20-0x00624c64.SelfLookPaneRectConstantsC](by-memory/0x00624c20-0x00624c64.SelfLookPaneRectConstantsC.md) 0x00624c20-0x00624c64 | source-local packed constants | SelfLookPaneRectConstantsC : reconstructable : 90% : very-strong : Exact remaining hover-grid coordinate vectors through the SimpleListPane boundary, all OnPaint-local and formally covered by the two local coordinate arrays.
```

- File/placement: replace the UID0000CU row in `by-class/-coverage-report.md` with:

```text
- [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md) : reconstructable : 93% : very-strong : Complete PanelPane-derived 0x2340 SelfLookPane declaration with exact natural equipment/text/summary/view layout, OnPaint/DrawNumberString/GetSlotRect/HitTestSlot and packet/input methods, ObjectStatusBlob/Spelled/Legend state, class closure before children, source-ready method union, and compiler/vtable/padding exclusions.
```

- File/placement: replace the UID0000NL row in `by-file/-coverage-report.md` with:

```text
- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) : reconstructable : 93% : very-strong : NexusTK/ui/panels/SelfLookPane.cpp source grouping with complete SelfLookPane 0x2340 declaration and OnPaint/DrawNumberString/GetSlotRect/HitTestSlot/input/packet union, complete SelfLookPane2 union, ObjectStatusBlob/equipment/text/view behavior, exact resources and covered-by local constants, shared child panes, source order, raw/helper/compiler distinctions, and filename/name confidence caps.
```

- Reason B agent must not apply it directly: manual coverage files are supervisor-owned. These exact rows are immutable handoff text; their later applied/current state is authoritative only in the current coverage files and validator-owned records.

## Follow-Up Actions
- B002's accepted implementation callback is complete: ordinary edits, UID-preserving rename, scoped validators, final waited generation, readback, report reconciliation, and lease release are terminal.
- The exact fifteen-row manual coverage handoff remains supervisor-owned. Callback-final manual files still contained stale/absent rows at the read-only hashes recorded above; this report does not assert what a later supervisor may apply.
- Current/future Gate 2, coverage, execution, path, move, count, archive, and validator-history state are external. B002 never runs `execute_report` or report lifecycle commands.
- No separate B-agent report is needed for UID0003QU, UID0003QV, or UID0003QW; they are included support scope.

## Confidence
- Recommendation confidence: very strong.
- Score confidence: strong.
- Remaining uncertainty: exact original private lexical names, precise access grouping, the historical source macro spelling, and the semantic reason for deliberate lookup/blit quirks. None blocks behavior-identical source.
- The exact original header basename/include-search-path spelling is inferred; current module naming supports `ItemObjImageLib.h`, while member ownership, singleton receiver, ABI, and definition uniqueness are very strong and do not remain blockers.

## Validator Results
- Every changed ordinary page passed a scoped validator. Every command below exited `0` with `ok:1`.

| Command | Timestamp | Scoped path / purpose | Result and relevant side effects |
| --- | --- | --- | --- |
| `000000013897` | `2026-07-16T12:12:24-04:00` | UID0003QV renamed `SelfLookPaneGetSlotRect` | UID/path/score/owner/block registry update; old path removed; generated deferred; temporary missing UID0003QW registry warning later closed by `13917`. |
| `000000013908` | `2026-07-16T12:13:25-04:00` | UID0003QU | `92/93`, block registration, references; generated deferred. |
| `000000013917` | `2026-07-16T12:14:32-04:00` | UID0003QW | `91/93`, block registration, QV/OnMouseClick links; generated deferred. |
| `000000013928` | `2026-07-16T12:15:55-04:00` | UID0003QP initial correction | `90/92`, formal/link registry update; generated deferred. |
| `000000013942` | `2026-07-16T12:18:08-04:00` | UID0003QN | `93/94`, blank-to-block registry update; generated deferred. |
| `000000013944` | `2026-07-16T12:19:57-04:00` | UID0000CU complete union | `93/94`, block hash and QV link update; pre-existing missing sibling UID warnings; generated deferred. |
| `000000013946` | `2026-07-16T12:20:52-04:00` | UID0002RG | `89/92`, corrected block hash; generated deferred. |
| `000000013947` | `2026-07-16T12:21:44-04:00` | UID0003EU | `90/92`, covered-by block registration; generated deferred. |
| `000000013952` | `2026-07-16T12:22:07-04:00` | UID0003EW | `90/92`, covered-by block registration; generated deferred. |
| `000000013954` | `2026-07-16T12:22:39-04:00` | UID0003F7 | `90/92`, covered-by block registration; generated deferred. |
| `000000013955` | `2026-07-16T12:23:01-04:00` | UID0003F9 | `90/92`, covered-by block registration; generated deferred. |
| `000000013956` | `2026-07-16T12:23:36-04:00` | UID0003FB | `90/92`, covered-by block registration; generated deferred. |
| `000000013957` | `2026-07-16T12:24:21-04:00` | UID0003QE prose link | metadata retained, UID0003QV canonical link updated; generated deferred. |
| `000000013958` | `2026-07-16T12:25:09-04:00` | UID0001H7 index | `89/92`, current inventory/references; pre-existing missing sibling UID warnings; generated deferred. |
| `000000013959` | `2026-07-16T12:26:16-04:00` | UID0000NL file union | `93/94`, B002 links/current union; pre-existing missing sibling UID warnings; generated deferred. |
| `000000013960` | `2026-07-16T12:26:45-04:00` | UID0000CU bounded method-map correction | metadata/formal unchanged; pre-existing missing sibling UID warnings; generated deferred. |
| `000000013961` | `2026-07-16T12:27:07-04:00` | UID0003QN bounded stale-name correction | no target metadata/formal change; generated deferred. |
| `000000013962` | `2026-07-16T12:27:27-04:00` | UID0003QP bounded stale-name correction | no metadata/formal change; generated deferred. |
| `000000013963` | `2026-07-16T12:29:02-04:00` | UID0003QP exact formal separator parity | block registry hash updated; generated deferred. |
| `000000013964` | `2026-07-16T12:29:15-04:00` | historical initial waited target refresh | Validator completed, but the preceding lease invocation used the wrong working-directory path and did not acquire a lease. No ordinary edit occurred in this step; this command is not the final proof. |
| `000000013965` | `2026-07-16T12:29:55-04:00` | final target `--wait-generated` under valid B002 target lease | generated refresh completed; registry rebuilt; projected/generated metadata refreshed; final target proof. |

- Command `13965` warnings were pre-existing project-wide `autogen_children_marker_missing`, `autogen_children_fallback_insert`, and unrelated `autogen_emitter_has_no_code` diagnostics. None is a UID0003QN target defect.
- Validator side effects were validator-owned projected stats, registry/reference metadata, research-tracker refresh, generated metadata, and generated C++. B002 did not edit those files manually.
- Authorized final generated proof:
  - `auto-generated/NexusTK/ui/panels/SelfLookPane.cpp`: command `13965`, refreshed `2026-07-16T12:29:55-04:00`, SHA256 `A184B35E3D415C1F0E9CDC920F659CD277CAA703FC372226CE557B9DE0E3C602`, 103,732 bytes / 2,977 lines; one complete `SelfLookPane` class before children; one UID0003QN OnPaint, DrawNumberString, GetSlotRect, and HitTestSlot; one qualified target glyph call and zero unqualified target calls; zero UID0003QN marker, `GetSlotColors`, null GetSlotRect call, cached-look alias, or literal `[[CHILDREN]]`.
  - `auto-generated/NexusTK/render/ItemObjImageLib.cpp`: command `13965`, refreshed `2026-07-16T12:29:55-04:00`, SHA256 `9BD19CC95EDCCBDA8BA11FDDC386DC22ACA642763A65CA7250EE6B70976E5219`, 7,625 bytes / 176 lines; one class member declaration, one qualified UID0000UQ definition, zero free definitions, zero UID0000UQ marker, and one singleton definition.
- Latest observed read-only generated epoch at final report reconciliation:
  - command `13981`, refreshed `2026-07-16T12:40:20-04:00`;
  - `SelfLookPane.cpp`: SHA256 `F65D3598DE03DA44180B5648D789D1D5119FA89C43639445B976335F983EA86E`, unchanged 103,732 bytes / 2,977 lines and unchanged exact semantic counts;
  - `ItemObjImageLib.cpp`: SHA256 `1BCFB5D0BFE355E3461AA28394B173B7A17B9B09E9ABE846EF5CB3BB6865F33A`, unchanged 7,625 bytes / 176 lines and unchanged exact semantic counts;
  - replacing only command `13981`'s command-id and refreshed-at header lines with command `13965`'s values reproduces SHA256 `A184...C602` and `9BD1...5219` exactly. Therefore the validator-owned refresh changed no generated byte below the volatile header.
- External B005 execution command `13891` and archive footer were read only. B002 ran no lifecycle command.

## Changed Files
- Callback report updated:
  - `tools/leaser/Agents/Agent-B002/research/0003QN-SelfLookPaneOnPaint-source-quality.md`.
- UID-preserving rename:
  - removed `by-memory/0x00569ed0-0x0056a300.SelfLookPaneGetSlotColors.md`;
  - current `by-memory/0x00569ed0-0x0056a300.SelfLookPaneGetSlotRect.md`, UID0003QV unique.
- Changed ordinary pages and final SHA256:

| Path | SHA256 |
| --- | --- |
| `by-memory/0x00567480-0x00568bd0.SelfLookPaneOnPaint.md` | `4231FC3CC4F693F23E5DEBB479184E7510B7C05E75A75858B67031F09726255C` |
| `by-memory/0x00569d80-0x00569ec1.SelfLookPaneDrawNumberString.md` | `18C9397E46204D78EFD9EDAC713A7FE95B6CE5CD47EABDDB08538E0DC6573313` |
| `by-memory/0x00569ed0-0x0056a300.SelfLookPaneGetSlotRect.md` | `C67929DF7A5D938E1BAE7A254F9BD23C1E5928A7CA433600DC62806D7005127D` |
| `by-memory/0x0056a300-0x0056a373.SelfLookPaneHitTestSlot.md` | `37A700A509B6FA7425AFE8AB2C8E1EEDD534C2A566B7D8775F37B966457D8555` |
| `by-memory/0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick.md` | `1026172B83CDBFE77766CADE1FD21126716ABA6654D04E4119712DC750507432` |
| `by-class/SelfLookPane.md` | `F65443D0FB75166C477A86DE6B28913F499CECE1F79094E9D1BE3A9C65806BDE` |
| `by-memory/0x0056b9f0-0x0056ba99.SelfLookPaneViewToggleRaw.md` | `89811486870EA95F8CE5ACE31A2E87E882A5C43D11F1F72CCD5B038529419AED` |
| `by-memory/0x00565610-0x0056a373.SelfLookPane.md` | `FAD0E2881164443C4804BFB36C007BF0A89CA5AD7AAEB10944E56D43EF9AB55E` |
| `by-file/SelfLookPane.md` | `4EAA5131B20009E0E672EC00904AE52D8647DC2A385ECBF992D1C7DEB059EF08` |
| `by-memory/0x00624788-0x006247f0.SelfLookPaneLookResourceStrings.md` | `FF0C84348C6F6CE9633F25E72E264565DE32BB3F40E618D3F1BA806A091C2351` |
| `by-memory/0x00624804-0x006248cc.SelfLookPaneLookIconNationStrings.md` | `73A2850197F78AE3C2334CF075BA86B521A45A2545E2780A68C617DBA6091D71` |
| `by-memory/0x00624be0-0x00624bf0.SelfLookPaneRectConstantsA.md` | `F7F29CE322AB9EE9A31E7198EC119743917FE21C186AF7C0B04AD39850137865` |
| `by-memory/0x00624c00-0x00624c10.SelfLookPaneRectConstantB.md` | `B0227060145961CA6D8054FAA91AC6696ABD55170AFACE9A74DF867ED37F34C0` |
| `by-memory/0x00624c20-0x00624c64.SelfLookPaneRectConstantsC.md` | `B080BA8B3D36E3EDFD30461AF2658D098489A6607A4DB2BFA1E548761E6031A7` |
| `by-memory/0x005670c0-0x0056717a.SelfLookPaneSendToggleStatsRaw.md` | `9901F487114EBE4C831B24C172F199ACF95DB20D2F0F066F30C6F05A15E1DB4A` |

- Verify-only UID0002UY, Config UID000031, UID0003EV/UID0003EX, and all B005 ItemObjImageLib ordinary pages were unchanged.
- Manual coverage/generated/tracker/audit/supervisor/validator-state/IDA files were not manually edited.
- Leases: each ordinary page was leased only for its immediate edit/validation batch and released. Target/QP/class were re-leased for bounded follow-up or final proof. Command `13964` had no lease because of the recorded path mistake; no edit occurred, and final command `13965` was rerun under a valid lease. Final lease table: zero B002 leases.
- Current read-only dependency artifact: `executed-b-agent-research/B005/0003HT-ItemObjectPaneClearOutputRects-source-quality.md`, SHA256 `239A091708E0374010AD0481F3309F965A515FA12C87FB52CFEBC4BBF62D7C20`, execution command `13891`.
- Historical pre-execution callback artifact: SHA256 `CC1ADD0037A32B568BD690BB4BEE609A8483400AF2769CE9FFECDF91F37EFEF8`, 43 checked / 0 unchecked rows; former active path is absent.
- Report lifecycle: B002 ran no execution, probe, count, move, archive, or lifecycle command. Exact current path and any validator-owned header/footer are authoritative for lifecycle state.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor exact-artifact Gate 1 passed before implementation.
- [x] Confirmed all C01-C35 Action cells use only the accepted vocabulary.
- [x] Confirmed the accepted report-only artifact had every C01-C35 state exactly `proposed`; callback states are now terminal.
- [x] Re-read the centralized B005 archive, tracker row, UID0000UQ, ItemObjImageLib layout/class/file/global, and generated dependency before callback.
- [x] Recorded current/historical B005 provenance and deterministic B005-owner/B002-consumer boundary.
- [x] Re-read UID0003QN and applied Destination 1 at report-level detail.
- [x] Installed Destination 1 with the exact include, extern declaration, and singleton-qualified member call.
- [x] Preserved UID0000UQ/UID0001UU/UID0000RA singular ownership/declaration/definition routes with no duplicate source.
- [x] Set UID0003QN to `93/94` and preserved owner/emitter/reconstructable/range/Nested/blank position.
- [x] Preserved exact body/table/padding/hash/instruction/CFG/stack/ABI/caller/callee/vtable/compiler proof.
- [x] Preserved every accepted mode/resource/item/hover/button/text/nation/spirit/stat/grouped/signed/auxiliary/default behavior.
- [x] Applied UID0003QU Destination 2 at `92/93`.
- [x] UID-preservingly renamed UID0003QV to `SelfLookPaneGetSlotRect`; old path absent, UID unique.
- [x] Applied Destination 3 at `92/94` with exact mapping/tail evidence.
- [x] Applied UID0003QW Destination 4 at `91/93`.
- [x] Preserved UID0003QP's accepted body and applied byte-equal Destination 5 at `90/92`.
- [x] Merged UID0000CU Destination 6 over the complete current union without loss.
- [x] Set UID0000CU to `93/94`; verified exact `0x2340` layout and class closure before children.
- [x] Applied UID0002RG Destination 12 at `89/92` with raw-start/call-order/layer/cookie/padding facts retained.
- [x] Verified UID0002RG clears hover slots `7..20` plus `m_identityLine1[0]`; no cached-look alias remains.
- [x] Set UID0001H7 to `89/92`, retained false/non-emitting metadata, and updated complete child inventory/QV path.
- [x] Set UID0000NL to `93/94`, prose only, preserving the full SelfLookPane2/shared-child/file union.
- [x] Applied Destinations 7-11 and `90/92` to UID0003EU/EW/F7/F9/FB.
- [x] Corrected UID0003EU historical `LOOK.EPF` wording to exact `SELFLOOK.EPF`.
- [x] Preserved UID0003EV/UID0003EX as pooled `NONE/FALSE` blank pages.
- [x] Verified UID0002UY and Config UID000031 unchanged at same-or-greater detail.
- [x] Scanned directly affected current docs and reconciled every source-facing stale helper spelling.
- [x] Updated UID0003QE helper-name/path prose only; metadata/formal disposition retained.
- [x] Preserved historical aliases as explicitly superseded.
- [x] Preserved negative/rejected/compiler-only evidence without compression.
- [x] Acquired short ordinary leases immediately before edits.
- [x] Re-read each destination after leasing.
- [x] Ran and recorded scoped validators for every changed ordinary page.
- [x] Released each lease immediately after its edit/validator batch.
- [x] Ran final authorized waited target refresh `13965` under a valid lease.
- [x] Verified one complete generated SelfLookPane class before child definitions.
- [x] Verified one OnPaint, DrawNumberString, GetSlotRect, and HitTestSlot definition.
- [x] Verified UID0003QN has one qualified glyph call and zero unqualified target calls.
- [x] Verified ItemObjImageLib one declaration/one qualified definition/zero free definitions/zero UID0000UQ markers/one singleton.
- [x] Verified zero UID0003QN marker, `GetSlotColors`, or null slot-rectangle call.
- [x] Verified zero `m_cachedLookState0..3` spelling.
- [x] Verified no duplicate resource/global/data declaration or handwritten compiler ABI/data source.
- [x] Independently reread generated output and recorded hashes/metrics/header/counts.
- [x] Re-read affected manual rows and preserved the exact immutable fifteen-row supervisor handoff.
- [x] Made zero prohibited manual edits to coverage/generated/tracker/audit/supervisor/validator/lifecycle/archive/IDA state.
- [x] Ran no `execute_report` probe or report lifecycle command.
- [x] Updated this same report's C01-C35 states, validators, changed files, leases, generated proof, and checklist.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation at SHA `BAAC88F9CB29F739223D622F3C25E53DE3208F3D8D8949E4E5CCCBF1046025B7`.
- [x] All accepted target/support destinations incorporated at report-level detail.
- [x] Every C01-C35 row has a legal terminal callback state with proof outside the state cell.
- [x] All metadata/score/rename/formal/class/data changes applied or excluded with exact reason.
- [x] All historical/rejected/negative evidence preserved.
- [x] All open questions remain closed.
- [x] Every scoped validator is recorded and successful.
- [x] Final waited generated assertions are recorded and successful.
- [x] Exact manual coverage handoff preserved for supervisor action.
- [x] Every ordinary lease released; zero active B002 leases.
- [x] No prohibited command or file edit performed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000014009","destination_path":"executed-b-agent-research/B002/0003QN-SelfLookPaneOnPaint-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0003QN-SelfLookPaneOnPaint-source-quality.md","timestamp":"2026-07-16T12:51:13-04:00","uid":"0003QN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
