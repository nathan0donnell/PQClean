#ifndef NTT_H
#define NTT_H
#include "NTT_params.h"
#include "params.h"
#include <stdint.h>

extern void PQCLEAN_DILITHIUM3_AARCH64_asm_ntt_SIMD_top(int *des, const int *table, const int *_constants);
extern void PQCLEAN_DILITHIUM3_AARCH64_asm_ntt_SIMD_bot(int *des, const int *table, const int *_constants);

extern void PQCLEAN_DILITHIUM3_AARCH64_asm_intt_SIMD_top(int *des, const int *table, const int *_constants);
extern void PQCLEAN_DILITHIUM3_AARCH64_asm_intt_SIMD_bot(int *des, const int *table, const int *_constants);

#define NTT(in) { \
        PQCLEAN_DILITHIUM3_AARCH64_asm_ntt_SIMD_top(in, streamlined_CT_negacyclic_table_Q1_extended, constants); \
        PQCLEAN_DILITHIUM3_AARCH64_asm_ntt_SIMD_bot(in, streamlined_CT_negacyclic_table_Q1_extended, constants); \
    }

#define iNTT(in) { \
        PQCLEAN_DILITHIUM3_AARCH64_asm_intt_SIMD_bot(in, streamlined_inv_CT_table_Q1_extended, constants); \
        PQCLEAN_DILITHIUM3_AARCH64_asm_intt_SIMD_top(in, streamlined_inv_CT_table_Q1_extended, constants); \
    }

#define ntt DILITHIUM_NAMESPACE(ntt)
void ntt(int32_t a[]);
#define invntt_tomont DILITHIUM_NAMESPACE(invntt_tomont)
void invntt_tomont(int32_t a[]);

static const int constants[16] = {
    Q1, -Q1prime, RmodQ1_prime_half, RmodQ1_doubleprime,
    invNQ1R2modQ1_prime_half,
    invNQ1R2modQ1_doubleprime,
    invNQ1_final_R2modQ1_prime_half,
    invNQ1_final_R2modQ1_doubleprime
};

static const int streamlined_CT_negacyclic_table_Q1_extended[(NTT_N + (1 << 0) + (1 << 4)) << 1] = {
    0, 0, -915382907, -3572223, 964937599, 3765607, 963888510, 3761513, -820383522, -3201494, -738955404, -2883726, -806080660, -3145678, -820367122, -3201430, -154181397, -601683, 907762539, 3542485, 687336873, 2682288, 545785280, 2129892, 964747974, 3764867, -257592709, -1005239, 142848732, 557458, -312926867, -1221177, 0, 0, -863652652, -3370349, 923069133, 3602218, 815613168, 3182878, 787459213, 3073009, 327391679, 1277625, -675340520, -2635473, 987079667, 3852015, 449207, 1753, -495951789, -1935420, -681503850, -2659525, -373072124, -1455890, 681730119, 2660408, -456183549, -1780227, -15156688, -59148, 710479343, 2772600, 0, 0, -1041158200, -4063053, 702264730, 2740543, -919027554, -3586446, 1071989969, 4183372, -825844983, -3222807, -799869667, -3121440, -70227934, -274060, 302950022, 1182243, 22347069, 87208, 163212680, 636927, -1016110510, -3965306, -1013916752, -3956745, -588452222, -2296397, -841760171, -3284915, -952468207, -3716946, 0, 0, 682491182, 2663378, -797147778, -3110818, 538486762, 2101410, 642926661, 2508980, 519705671, 2028118, 496502727, 1937570, -977780347, -3815725, -7126831, -27812, 210776307, 822541, 258649997, 1009365, -628875181, -2454145, -507246529, -1979497, 409185979, 1596822, -1013967746, -3956944, -963363710, -3759465, 0, 0, -429120452, -1674615, 949361686, 3704823, 297218217, 1159875, 720393920, 2811291, -764594519, -2983781, -284313712, -1109516, 1065510939, 4158088, -431820817, -1685153, -873958779, -3410568, 686309310, 2678278, -965793731, -3768948, -909946047, -3551006, 162963861, 635956, -64176841, -250446, -629190881, -2455377, 0, 0, -903139016, -3524442, 101000509, 394148, 237992130, 928749, 391567239, 1528066, 123678909, 482649, 294395108, 1148858, -759080783, -2962264, -1062481036, -4146264, -454226054, -1772588, 561940831, 2192938, -442566669, -1727088, 611800717, 2387513, -925511710, -3611750, -68791907, -268456, -814992530, -3180456, 0, 0, -111244624, -434125, 280713909, 1095468, -898510625, -3506380, -144935890, -565603, 43482586, 169688, 631001801, 2462444, -854436357, -3334383, 960233614, 3747250, 588375860, 2296099, 317727459, 1239911, -983611064, -3838479, 818892658, 3195676, 677264190, 2642980, 321386456, 1254190, -3181859, -12417, 0, 0, 173376332, 676590, 530906624, 2071829, -1029866791, -4018989, -1067647297, -4166425, -893898890, -3488383, 509377762, 1987814, -819295484, -3197248, 768294260, 2998219, 36345249, 141835, -22883400, -89301, 643961400, 2513018, -347191365, -1354892, 157142369, 613238, -335754661, -1310261, -568482643, -2218467, 0, 0, -342333886, -1335936, 830756018, 3241972, 552488273, 2156050, 444930577, 1736313, 60323094, 235407, -832852657, -3250154, 834980303, 3258457, -117552223, -458740, -492511373, -1921994, 1035301089, 4040196, -889718424, -3472069, 522531086, 2039144, -481719139, -1879878, -209807681, -818761, -558360247, -2178965, 0, 0, -827143915, -3227876, 875112161, 3415069, 450833045, 1759347, -660934133, -2579253, 458160776, 1787943, -612717067, -2391089, -577774276, -2254727, -415984810, -1623354, 539479988, 2105286, -608441020, -2374402, -521163479, -2033807, 150224382, 586241, -302276083, -1179613, 135295244, 527981, -702999655, -2743411, 0, 0, 439288460, 1714295, -209493775, -817536, -915957677, -3574466, 892316032, 3482206, -1071872863, -4182915, -333129378, -1300016, -605279149, -2362063, -378477722, -1476985, 510974714, 1994046, 638402564, 2491325, -356997292, -1393159, 130156402, 507927, -304395785, -1187885, -185731180, -724804, -470097680, -1834526, 0, 0, 628833668, 2453983, 962678241, 3756790, -496048908, -1935799, -337655269, -1317678, 630730945, 2461387, 777970524, 3035980, 159173408, 621164, -777397036, -3033742, -86720197, -338420, 678549029, 2647994, 771248568, 3009748, -669544140, -2612853, 1063046068, 4148469, 192079267, 749577, -1030830548, -4022750, 0, 0, 374309300, 1460718, -439978542, -1716988, -1012201926, -3950053, 999753034, 3901472, -314332144, -1226661, 749740976, 2925816, 864652284, 3374250, 1020029345, 3980599, 658309618, 2569011, -413979908, -1615530, 441577800, 1723229, 426738094, 1665318, 519685171, 2028038, 298172236, 1163598, -863376927, -3369273, 0, 0, -164673562, -642628, -742437332, -2897314, 818041395, 3192354, 347590090, 1356448, -711287812, -2775755, 687588511, 2683270, -712065019, -2778788, 1023635298, 3994671, -3043996, -11879, -351195274, -1370517, 773976352, 3020393, 861908357, 3363542, 55063046, 214880, 139752717, 545376, -197425671, -770441, 0, 0, -918682129, -3585098, 142694469, 556856, 991769559, 3870317, -888589898, -3467665, 592665232, 2312838, -167401858, -653275, -117660617, -459163, 795799901, 3105558, -282732136, -1103344, 130212265, 508145, -141890356, -553718, 220412084, 860144, 879049958, 3430436, 35937555, 140244, -388001774, -1514152, 0, 0, 721508096, 2815639, 747568486, 2917338, 475038184, 1853806, 89383150, 348812, -84011120, -327848, 259126110, 1011223, -603268097, -2354215, -559928242, -2185084, 800464680, 3123762, 604333585, 2358373, -561979013, -2193087, -772445769, -3014420, -439933955, -1716814, 749801963, 2926054, -100631253, -392707, 0, 0, 585207070, 2283733, 857403734, 3345963, 476219497, 1858416, -978523985, -3818627, -492577742, -1922253, -573161516, -2236726, 447030292, 1744507, -77645096, -303005, 904878186, 3531229, -1018462631, -3974485, -967019376, -3773731, 486888731, 1900052, -200355636, -781875, 270210213, 1054478, -187430119, -731434, 0, 0
};

static const int streamlined_inv_CT_table_Q1_extended[(NTT_N + (1 << 0) + (1 << 4)) << 1] = {
    0, 0, 915382907, 3572223, -963888510, -3761513, -964937599, -3765607, 820367122, 3201430, 806080660, 3145678, 738955404, 2883726, 820383522, 3201494, 312926867, 1221177, -142848732, -557458, 257592709, 1005239, -964747974, -3764867, -545785280, -2129892, -687336873, -2682288, -907762539, -3542485, 154181397, 601683, 0, 0, -585207070, -2283733, -476219497, -1858416, -857403734, -3345963, -447030292, -1744507, 573161516, 2236726, 492577742, 1922253, 978523985, 3818627, 187430119, 731434, -270210213, -1054478, 200355636, 781875, -486888731, -1900052, 967019376, 3773731, 1018462631, 3974485, -904878186, -3531229, 77645096, 303005, 0, 0, -721508096, -2815639, -475038184, -1853806, -747568486, -2917338, 603268097, 2354215, -259126110, -1011223, 84011120, 327848, -89383150, -348812, 100631253, 392707, -749801963, -2926054, 439933955, 1716814, 772445769, 3014420, 561979013, 2193087, -604333585, -2358373, -800464680, -3123762, 559928242, 2185084, 0, 0, 918682129, 3585098, -991769559, -3870317, -142694469, -556856, 117660617, 459163, 167401858, 653275, -592665232, -2312838, 888589898, 3467665, 388001774, 1514152, -35937555, -140244, -879049958, -3430436, -220412084, -860144, 141890356, 553718, -130212265, -508145, 282732136, 1103344, -795799901, -3105558, 0, 0, 164673562, 642628, -818041395, -3192354, 742437332, 2897314, 712065019, 2778788, -687588511, -2683270, 711287812, 2775755, -347590090, -1356448, 197425671, 770441, -139752717, -545376, -55063046, -214880, -861908357, -3363542, -773976352, -3020393, 351195274, 1370517, 3043996, 11879, -1023635298, -3994671, 0, 0, -374309300, -1460718, 1012201926, 3950053, 439978542, 1716988, -864652284, -3374250, -749740976, -2925816, 314332144, 1226661, -999753034, -3901472, 863376927, 3369273, -298172236, -1163598, -519685171, -2028038, -426738094, -1665318, -441577800, -1723229, 413979908, 1615530, -658309618, -2569011, -1020029345, -3980599, 0, 0, -628833668, -2453983, 496048908, 1935799, -962678241, -3756790, -159173408, -621164, -777970524, -3035980, -630730945, -2461387, 337655269, 1317678, 1030830548, 4022750, -192079267, -749577, -1063046068, -4148469, 669544140, 2612853, -771248568, -3009748, -678549029, -2647994, 86720197, 338420, 777397036, 3033742, 0, 0, -439288460, -1714295, 915957677, 3574466, 209493775, 817536, 605279149, 2362063, 333129378, 1300016, 1071872863, 4182915, -892316032, -3482206, 470097680, 1834526, 185731180, 724804, 304395785, 1187885, -130156402, -507927, 356997292, 1393159, -638402564, -2491325, -510974714, -1994046, 378477722, 1476985, 0, 0, 827143915, 3227876, -450833045, -1759347, -875112161, -3415069, 577774276, 2254727, 612717067, 2391089, -458160776, -1787943, 660934133, 2579253, 702999655, 2743411, -135295244, -527981, 302276083, 1179613, -150224382, -586241, 521163479, 2033807, 608441020, 2374402, -539479988, -2105286, 415984810, 1623354, 0, 0, 342333886, 1335936, -552488273, -2156050, -830756018, -3241972, -834980303, -3258457, 832852657, 3250154, -60323094, -235407, -444930577, -1736313, 558360247, 2178965, 209807681, 818761, 481719139, 1879878, -522531086, -2039144, 889718424, 3472069, -1035301089, -4040196, 492511373, 1921994, 117552223, 458740, 0, 0, -173376332, -676590, 1029866791, 4018989, -530906624, -2071829, 819295484, 3197248, -509377762, -1987814, 893898890, 3488383, 1067647297, 4166425, 568482643, 2218467, 335754661, 1310261, -157142369, -613238, 347191365, 1354892, -643961400, -2513018, 22883400, 89301, -36345249, -141835, -768294260, -2998219, 0, 0, 111244624, 434125, 898510625, 3506380, -280713909, -1095468, 854436357, 3334383, -631001801, -2462444, -43482586, -169688, 144935890, 565603, 3181859, 12417, -321386456, -1254190, -677264190, -2642980, -818892658, -3195676, 983611064, 3838479, -317727459, -1239911, -588375860, -2296099, -960233614, -3747250, 0, 0, 903139016, 3524442, -237992130, -928749, -101000509, -394148, 759080783, 2962264, -294395108, -1148858, -123678909, -482649, -391567239, -1528066, 814992530, 3180456, 68791907, 268456, 925511710, 3611750, -611800717, -2387513, 442566669, 1727088, -561940831, -2192938, 454226054, 1772588, 1062481036, 4146264, 0, 0, 429120452, 1674615, -297218217, -1159875, -949361686, -3704823, -1065510939, -4158088, 284313712, 1109516, 764594519, 2983781, -720393920, -2811291, 629190881, 2455377, 64176841, 250446, -162963861, -635956, 909946047, 3551006, 965793731, 3768948, -686309310, -2678278, 873958779, 3410568, 431820817, 1685153, 0, 0, -682491182, -2663378, -538486762, -2101410, 797147778, 3110818, 977780347, 3815725, -496502727, -1937570, -519705671, -2028118, -642926661, -2508980, 963363710, 3759465, 1013967746, 3956944, -409185979, -1596822, 507246529, 1979497, 628875181, 2454145, -258649997, -1009365, -210776307, -822541, 7126831, 27812, 0, 0, 1041158200, 4063053, 919027554, 3586446, -702264730, -2740543, 70227934, 274060, 799869667, 3121440, 825844983, 3222807, -1071989969, -4183372, 952468207, 3716946, 841760171, 3284915, 588452222, 2296397, 1013916752, 3956745, 1016110510, 3965306, -163212680, -636927, -22347069, -87208, -302950022, -1182243, 0, 0, 863652652, 3370349, -815613168, -3182878, -923069133, -3602218, -987079667, -3852015, 675340520, 2635473, -327391679, -1277625, -787459213, -3073009, -710479343, -2772600, 15156688, 59148, 456183549, 1780227, -681730119, -2660408, 373072124, 1455890, 681503850, 2659525, 495951789, 1935420, -449207, -1753, 0, 0
};

#endif
