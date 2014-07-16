(function(){

    var resultObject;

    function invokeSearch() {

        var searchQuery = $("#request")[0].value;

        var request = {
            "searchQuery": {
                "text": searchQuery
            }
        };

        var requestInfo = {
            type: "GET",
            contentType: "application/json; charset=utf-8",
            url: "/axis2/services/Searcher/searchserve",
            async: true,
            processData: false,
            dataType: "json",
            data: JSON.stringify(request)
        };


        function onSuccess(result) {
            resultObject.text(result.SearchResult.text);
            resultObject.css("color", "");
        }

        function onError(none, error) {
            resultObject.text("ERROR: " + error);
            resultObject.css("color", "red");
        }

        jQuery.ajax(requestInfo)
        .success(onSuccess)
        .error(onError);
    }

    $(document).ready(function() {
        $('#invoke').bind("click", invokeSearch);
        resultObject = $('#result');
    });

})();
