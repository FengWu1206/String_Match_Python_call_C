#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define SIGMA = 128

typedef struct result {
    int match;
    int number;
} result, *result_point;

void Pre_Horspool(unsigned char *P, long int m, long int hbc[]);

result_point search(unsigned char *P, unsigned char *T);

void Pre_Horspool(unsigned char *P, long int m, long int hbc[]) {
    int i;
    for (i = 0; i < 128; i++) hbc[i] = m;
    for (i = 0; i < m - 1; i++) hbc[P[i]] = m - i - 1;
}


result_point search(unsigned char *P, unsigned char *T) {
    long int i, s, hbc[128];
    long int m = strlen(P);
    long int n = strlen(T);
    result_point bm_result = (result_point)malloc(sizeof(result));
    bm_result->match = 0;
    bm_result->number = 0;
    Pre_Horspool(P, m, hbc);

    /* Searching */
    s = 0;
    while (s <= n - m) {
        i = 0;
        while (i < m && P[i] == T[s + i]) i++;
        if (i == m){
            bm_result->match = 1;
            bm_result->number += 1;
            s += m;
        }
        else{
            s += hbc[T[s + m - 1]];
        }
    }
    return bm_result;
}

// Driver program to test above function
result_point main() {
    char *txt = "ZZIP_DISK_FILE*file=zzip_mem_disk_fopen(disk,name);if(file){charbuffer[1024];intlen;while((len=zzip_mem_disk_fread(buffer,1,1024,file))){fwrite(buffer,1,len,out);#py-faster-rcnnhasbeendeprecated.Pleasesee[Detectron](https://github.com/facebookresearch/Detectron),whichincludesanimplementationof[MaskR-CNN](https://arxiv.org/abs/1703.06870).###DisclaimerTheofficialFasterR-CNNcode(writteninMATLAB)isavailable[here](https://github.com/ShaoqingRen/faster_rcnn).IfyourgoalistoreproducetheresultsinourNIPS2015paper,pleaseusethe[officialcode](https://github.com/ShaoqingRen/faster_rcnn).ThisrepositorycontainsaPython*reimplementation*oftheMATLABcode.ThisPythonimplementationisbuiltonaforkof[FastR-CNN](https://github.com/rbgirshick/fast-rcnn).Thereareslightdifferencesbetweenthetwoimplementations.Inparticular,thisPythonport-is~10%slowerattest-time,becausesomeoperationsexecuteontheCPUinPythonlayers(e.g.,220ms/imagevs.200ms/imageforVGG16)-givessimilar,butnotexactlythesame,mAPastheMATLABversion-is*notcompatible*withmodelstrainedusingtheMATLABcodeduetotheminorimplementationdifferences-**includesapproximatejointtraining**thatis1.5xfasterthanalternatingoptimization(forVGG16)--seethese[slides](https://www.dropbox.com/s/xtr4yd4i5e0vw8g/iccv15_tutorial_training_rbg.pdf?dl=0)formoreinformation#*Faster*R-CNN:TowardsReal-TimeObjectDetectionwithRegionProposalNetworks{FILE*out=stdout;if(extract)out=create_fopen(name,\"w\",1);unzzip_cat_file(disk,name,out);if(extract)fclose(out);break;/*matchloop*/ByShaoqingRen,KaimingHe,RossGirshick,JianSun(MicrosoftResearch)ThisPythonimplementationcontainscontributionsfromSeanBell(Cornell)writtenduringanMSRinternship.Pleaseseetheofficial[README.md](https://github.com/ShaoqingRen/faster_rcnn/blob/master/README.md)formoredetails.FasterR-CNNwasinitiallydescribedinan[arXivtechreport](http://arxiv.org/abs/1506.01497)andwassubsequentlypublishedinNIPS2015.###LicenseFasterR-CNNisreleasedundertheMITLicense(refertotheLICENSEfilefordetails).###CitingFasterR-CNNIfyoufindFasterR-CNNusefulinyourresearch,pleaseconsiderciting:@inproceedings{renNIPS15fasterrcnn,Author={ShaoqingRenandKaimingHeandRossGirshickandJianSun},Title={Faster{R-CNN}:TowardsReal-TimeObjectDetectionwithRegionProposalNetworks},Booktitle={AdvancesinNeuralInformationProcessingSystems({NIPS})},Year={2015}}###Contents1.[Requirements:software](#requirements-software)2.[Requirements:hardware](#requirements-hardware)3.[Basicinstallation](#installation-sufficient-for-the-demo)4.[Demo](#demo)5.[Beyondthedemo:trainingandtesting](#beyond-the-demo-installation-for-training-and-testing-models)6.[Usage](#usage)ZZIP_DISK_FILE*file=zzip_mem_disk_fopen(disk,name);if(file){charbuffer[1024];intlen;while((len=zzip_mem_disk_fread(buffer,1,1024,file))){fwrite(buffer,1,len,out);###Requirements:software**NOTE**IfyouarehavingissuescompilingandyouareusingarecentversionofCUDA/cuDNN,pleaseconsult[thisissue](https://github.com/rbgirshick/py-faster-rcnn/issues/509?_pjax=%23js-repo-pjax-container#issuecomment-284133868)foraworkaround1.Requirementsfor`Caffe`and`pycaffe`(see:[Caffeinstallationinstructions](http://caffe.berkeleyvision.org/installation.html))**Note:**Caffe*must*bebuiltwithsupportforPythonlayers!```make#InyourMakefile.config,makesuretohavethislineuncommentedWITH_PYTHON_LAYER:=1#Unrelatedly,it'salsorecommendedthatyouuseCUDNNUSE_CUDNN:=1```Youcandownloadmy[Makefile.config](https://dl.dropboxusercontent.com/s/6joa55k64xo2h68/Makefile.config?dl=0)forreference.2.Pythonpackagesyoumightnothave:`cython`,`python-opencv`,`easydict`3.[Optional]MATLABisrequiredfor**official**PASCALVOCevaluationonly.ThecodenowincludesunofficialPythonevaluationcode.###Requirements:hardwareZZIP_DISK_FILE*file=zzip_mem_disk_fopen(disk,name);if(file){charbuffer[1024];intlen;while((len=zzip_mem_disk_fread(buffer,1,1024,file))){fwrite(buffer,1,len,out);aaaaaaa;getabcd_hgjgj()getabcd()1.Fortrainingsmallernetworks(ZF,VGG_CNN_M_1024)agoodGPU(e.g.,Titan,K20,K40,...)withatleast3Gofmemorysuffices2.FortrainingFastR-CNNwithVGG16,you'llneedaK40(~11Gofmemory)3.Fortrainingtheend-to-endversionofFasterR-CNNwithVGG16,3GofGPUmemoryissufficient(usingCUDNN)###Installation(sufficientforthedemo)1.ClonetheFasterR-CNNrepository```Shell#Makesuretoclonewith--recursivegitclone--recursivehttps://github.com/rbgirshick/py-faster-rcnn.git```2.We'llcallthedirectorythatyouclonedFasterR-CNNinto`FRCN_ROOT`*Ignorenotes1and2ifyoufollowedstep1above.***Note1:**Ifyoudidn'tcloneFasterR-CNNwiththe`--recursive`flag,thenyou'llneedtomanuallyclonethe`caffe-fast-rcnn`submodule:```Shellgitsubmoduleupdate--init--recursive```**Note2:**The`caffe-fast-rcnn`submoduleneedstobeonthe`faster-rcnn`branch(orequivalentdetachedstate).Thiswillhappenautomatically*ifyoufollowedstep1instructions*.3.BuildtheCythonmodules```Shellcd$FRCN_ROOT/libmake```4.BuildCaffeandpycaffe```Shellcd$FRCN_ROOT/caffe-fast-rcnn#NowfollowtheCaffeinstallationinstructionshere:#http://caffe.berkeleyvision.org/installation.html#Ifyou'reexperiencedwithCaffeandhavealloftherequirementsinstalled#andyourMakefile.configinplace,thensimplydo:make-j8&&makepycaffe```5.Downloadpre-computedFasterR-CNNdetectors```Shellcd$FRCN_ROOT./data/scripts/fetch_faster_rcnn_models.sh```Thiswillpopulatethe`$FRCN_ROOT/data`folderwith`faster_rcnn_models`.See`data/README.md`fordetails.ThesemodelsweretrainedonVOC2007trainval.###Demo*Aftersuccessfullycompleting[basicinstallation](#installation-sufficient-for-the-demo)*,you'llbereadytorunthedemo.Torunthedemo```Shellcd$FRCN_ROOT./tools/demo.py```ThedemoperformsdetectionusingaVGG16networktrainedfordetectiononPASCALVOC2007.###Beyondthedemo:installationfortrainingandtestingmodels1.Downloadthetraining,validation,testdataandVOCdevkit```Shellwgethttp://host.robots.ox.ac.uk/pascal/VOC/voc2007/VOCtrainval_06-Nov-2007.tarwgethttp://host.robots.ox.ac.uk/pascal/VOC/voc2007/VOCtest_06-Nov-2007.tarwgethttp://host.robots.ox.ac.uk/pascal/VOC/voc2007/VOCdevkit_08-Jun-2007.tar```2.Extractallofthesetarsintoonedirectorynamed`VOCdevkit````ShelltarxvfVOCtrainval_06-Nov-2007.tartarxvfVOCtest_06-Nov-2007.tartarxvfVOCdevkit_08-Jun-2007.tar```3.Itshouldhavethisbasicstructure```Shell$VOCdevkit/#developmentkit$VOCdevkit/VOCcode/#VOCutilitycode$VOCdevkit/VOC2007#imagesets,annotations,etc.#...andseveralotherdirectories...```4.CreatesymlinksforthePASCALVOCdataset```Shellcd$FRCN_ROOT/dataln-s$VOCdevkitVOCdevkit2007```UsingsymlinksisagoodideabecauseyouwilllikelywanttosharethesamePASCALdatasetinstallationbetweenmultipleprojects.5.[Optional]followsimilarstepstogetPASCALVOC2010and20126.[Optional]IfyouwanttouseCOCO,pleaseseesomenotesunder`data/README.md`7.Followthenextsectionstodownloadpre-trainedImageNetmodels###Downloadpre-trainedImageNetmodelsPre-trainedImageNetmodelscanbedownloadedforthethreenetworksdescribedinthepaper:ZFandVGG16.```Shellcd$FRCN_ROOT./data/scripts/fetch_imagenet_models.sh```VGG16comesfromthe[CaffeModelZoo](https://github.com/BVLC/caffe/wiki/Model-Zoo),butisprovidedhereforyourconvenience.ZFwastrainedatMSRA.###UsageTotrainandtestaFasterR-CNNdetectorusingthe**alternatingoptimization**algorithmfromourNIPS2015paper,use`experiments/scripts/faster_rcnn_alt_opt.sh`.Outputiswrittenunderneath`$FRCN_ROOT/output`.```Shellcd$FRCN_ROOT./experiments/scripts/faster_rcnn_alt_opt.sh[GPU_ID][NET][--set...]#GPU_IDistheGPUyouwanttotrainon#NETin{ZF,VGG_CNN_M_1024,VGG16}isthenetworkarchtouse#--set...allowsyoutospecifyfast_rcnn.configoptions,e.g.#--setEXP_DIRseed_rng1701RNG_SEED1701```(\"altopt\"referstothealternatingoptimizationtrainingalgorithmdescribedintheNIPSpaper.)TotrainandtestaFasterR-CNNdetectorusingthe**approximatejointtraining**method,use`experiments/scripts/faster_rcnn_end2end.sh`.Outputiswrittenunderneath`$FRCN_ROOT/output`.```Shellcd$FRCN_ROOT./experiments/scripts/faster_rcnn_end2end.sh[GPU_ID][NET][--set...]#GPU_IDistheGPUyouwanttotrainon#NETin{ZF,VGG_CNN_M_1024,VGG16}isthenetworkarchtouse#--set...allowsyoutospecifyfast_rcnn.configoptions,e.g.#--setEXP_DIRseed_rng1701RNG_SEED1701```ThismethodtrainstheRPNmodulejointlywiththeFastR-CNNnetwork,ratherthanalternatingbetweentrainingthetwo.Itresultsinfaster(~1.5xspeedup)trainingtimesandsimilardetectionaccuracy.Seethese[slides](https://www.dropbox.com/s/xtr4yd4i5e0vw8g/iccv15_tutorial_training_rbg.pdf?dl=0)formoredetails.Artifactsgeneratedbythescriptsin`tools`arewritteninthisdirectory.TrainedFastR-CNNnetworksaresavedunder:```output/<experimentdirectory>/<datasetname>/```Testoutputsaresavedunder:```output/<experimentdirectory>/<datasetname>/<networksnapshotname>/```";
    char *pat = "ZZIP_DISK_FILE*file=zzip_mem_disk_fopen(disk,name);if(file){charbuffer[1024];intlen;while((len=zzip_mem_disk_fread(buffer,1,1024,file))){fwrite(buffer,1,len,out);";
    printf("%d", search(pat, txt)->number);
    return search(pat, txt);
}